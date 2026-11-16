/* An object at +0xf0 of its owner whose first virtual method takes a pointer
 * and an int and returns a pointer (the handlers FUN_00599340, FUN_00599dc0
 * and FUN_00c02790 store through it); three matched thunks in src/game/unknown/ forward their own
 * second argument to it with a constant and return 0. derived names. */
#ifndef TLG_DEVICE_THUNK_H
#define TLG_DEVICE_THUNK_H

#include "tlg_types.h"
#include "tlg_game_array.h"

struct Device583950Vtable {
    void *(*method0)(void *self, void *arg, int mode);
};

struct Device583950 {
    Device583950Vtable *vtable;
};

struct Owner583950;

/* A value of three floats, as the owner holds one of type 7 and
 * FUN_0057fd20 copies one between its two lists. derived name */
struct Vector583950 {
    float x;
    float y;
    float z;
};

/* An entry of the handler tables FUN_00525530 fills: the owner and a node. */
typedef int (*Handler583950)(Owner583950 *self, void *arg);

/* A node the handlers are given: the int at +0x24 indexes the owner's handler
 * table (0 is none); the handlers FUN_0057fc70 and its siblings dispatch the
 * node held at +0x28, +0x30, +0x38 or +0x58. derived names. */
struct Node583950 {
    u8 unknown0[0x24];
    int kind;            /* +0x24 */
    Node583950 *child;   /* +0x28 */
    Node583950 *child30; /* +0x30 */
    Node583950 *child38; /* +0x38 */
    u8 unknown40[8];
    int value48; /* +0x48, stored by FUN_00596780 */
    u8 unknown4c[0xc];
    Node583950 *child58; /* +0x58 */
};

/* A node of the kind FUN_0058da20 and its two copies are given: the index of
 * its Name at +0x2c (the name table, tlg_game_name.h) and the node of the
 * list it refers to at +0x38. derived names. */
struct NamedNode583950 {
    u8 unknown0[0x2c];
    unsigned name; /* +0x2c */
    u8 unknown30[8];
    void *target; /* +0x38 */
};

/* The owner's list of nodes: a count and an array of pointers (read by
 * FUN_00583980 and its six copies). derived names. */
struct NodeList583950 {
    u8 unknown0[8];
    unsigned count; /* +0x8 */
    void **items;   /* +0x10 */
    int *offsets;   /* +0x18: the byte offset of each node's value from the second on */
    u8 *states;     /* +0x20: a byte for each node (FUN_00583bb0) */
    char *values;   /* +0x28 */
};

/* A node of the kind FUN_00583bb0 is given: the flags at +0x28. derived names. */
struct StateNode583950 {
    u8 unknown0[0x28];
    u8 flags; /* +0x28 */
};

/* What a call is given: a node, and the node's value where the call needs
 * it (FUN_005995c0 copies both in one assignment: `mov [rcx+r11+0x18],
 * rsi; mov [rcx+r11+0x20], r8` with the queue read once). derived names */
struct CallArguments583950 {
    void *node;
    void *value; /* +0x8 */
};

/* An entry of the call queue: the function at +0x0, the node it is given at
 * +0x10 (FUN_0059d3f0 and its four copies) and 0x58 bytes after the
 * function. derived names */
struct Call583950 {
    void (*function)(void *vm);
    u8 unknown8[8];
    CallArguments583950 arguments; /* +0x10 */
    u8 unknown20[0x40];
};

/* A queue of calls: its capacity, its size and the entries from +0x8.
 * derived names */
struct CallQueue583950 {
    unsigned capacity;
    unsigned size;       /* +0x4 */
    Call583950 calls[1]; /* +0x8 */
};

/* The owner's frame at +0x110: a depth and the call queue (FUN_0059ab60,
 * FUN_00c0bc10 and FUN_00c0bcb0 append a call to it). derived names */
struct CallFrame583950 {
    /* appends a call when a slot after it is left (derived name) */
    bool push(void (*function)(void *vm))
    {
        const unsigned next = queue->size + 1;
        if (next >= queue->capacity)
            return false;
        queue->calls[queue->size].function = function;
        queue->size = next;
        return true;
    }

    /* appends a call with the node it is given, the slot's index read once
     * (FUN_0059d3f0 and its four copies: `mov esi, [rcx+4]`, the function
     * and the node stored at that index, the queue read again before each
     * store). derived name */
    bool push(void (*function)(void *vm), void *argument)
    {
        const unsigned size = queue->size;
        const unsigned next = size + 1;
        if (next >= queue->capacity)
            return false;
        queue->calls[size].function = function;
        queue->calls[size].arguments.node = argument;
        queue->size = next;
        return true;
    }

    /* appends a call with the node and its value, the same way
     * (FUN_005995c0). derived name */
    bool push(void (*function)(void *vm), const CallArguments583950 &arguments)
    {
        const unsigned size = queue->size;
        const unsigned next = size + 1;
        if (next >= queue->capacity)
            return false;
        queue->calls[size].function = function;
        queue->calls[size].arguments = arguments;
        queue->size = next;
        return true;
    }

    /* appends a call one level deeper (FUN_00c0bc10, FUN_00c0bcb0). derived
     * name */
    void pushDeeper(void (*function)(void *vm))
    {
        if (push(function))
            ++depth;
    }

    int depth;
    CallQueue583950 *queue; /* +0x8 */
};

/* A list of nodes with its current index: the owner has two, at +0x38 and
 * +0x190 (FUN_00af09d0 and its three copies search both). derived names */
struct NodeCursor583950 {
    /* finds a node of the list, searched from the current index to the
     * end, then from the start up to the current index: false when it is
     * not in the list, else its index in the argument (derived name) */
    bool find(void *node, unsigned &index) const
    {
        const NodeList583950 *nodes = list;
        unsigned at = current;
        bool found = false;
        for (unsigned i = current; i < nodes->count; ++i) {
            if (nodes->items[i] == node) {
                at = i;
                found = true;
                break;
            }
        }
        if (!found) {
            for (unsigned i = 0; i < current; ++i) {
                if (nodes->items[i] == node) {
                    at = i;
                    found = true;
                    break;
                }
            }
        }
        if (found)
            index = at;
        return found;
    }

    /* makes a node of the list the current one: false when it is not in
     * the list (derived name) */
    bool select(void *node)
    {
        unsigned index;
        if (!find(node, index))
            return false;
        current = index;
        return true;
    }

    /* the storage of the current node: the first node's value is at the
     * start of the list's storage, each later one's at its offset (derived
     * name) */
    char *value() const
    {
        const NodeList583950 *nodes = list;
        const int offset = current != 0 && current < nodes->count ? nodes->offsets[current - 1] : 0;
        return nodes->values + offset;
    }

    /* the state byte of the current node, null when the index is past the
     * list's end (derived name) */
    u8 *state() const
    {
        const NodeList583950 *nodes = list;
        return current < nodes->count ? &nodes->states[current] : 0;
    }

    /* makes a node of the list the current one and returns its state byte;
     * null when the node is not in the list (derived name) */
    u8 *selectState(void *node)
    {
        if (!select(node))
            return 0;
        return state();
    }

    unsigned current; /* the index of the current node in the list */
    u8 unknown4[4];
    NodeList583950 *list; /* +0x8 */
};

/* What every handler of the tables FUN_00525530, FUN_00be6da0 and their
 * callers fill is given: the list with its current index and the table of
 * handlers by kind. What follows +0xf0 differs by table: an owner of each
 * kind derives from this one. derived name */
struct Owner583950 {
    /* finds a node of the list (derived name) */
    bool find(void *node, unsigned &index) const
    {
        return cursor.find(node, index);
    }

    /* makes a node of the list the current one; nothing changes when the
     * node is not in it (FUN_00583980 and the six handlers of the same
     * body). derived name */
    void select(void *node)
    {
        cursor.select(node);
    }

    /* the storage of the current node: the first node's value is at the
     * start of the list's storage, each later one's at its offset
     * (FUN_0058da20 and its two copies; FUN_0057f9d0 and FUN_00584df0 read
     * the same fields). derived name */
    char *currentValue() const
    {
        return cursor.value();
    }

    /* the state byte of the current node, null when the index is past the
     * list's end. derived name */
    u8 *currentState() const
    {
        return cursor.state();
    }

    /* makes a node of the list the current one and returns its state byte;
     * null when the node is not in the list (FUN_00583bb0). derived name */
    u8 *selectState(void *node)
    {
        return cursor.selectState(node);
    }

    /* hands a node to the handler of its kind, when it has a kind and the
     * kind a handler; the table is read first (FUN_00583d20 reads it before
     * each of its two nodes is tested). derived name */
    void dispatch(Node583950 *node)
    {
        Handler583950 *table = handlers;
        if (node && node->kind) {
            Handler583950 handler = table[node->kind];
            if (handler)
                handler(this, node);
        }
    }

    u8 unknown0[0x38];
    NodeCursor583950 cursor; /* +0x38: the current index, the list at +0x40 */
    Handler583950 *handlers; /* +0x48, indexed by a node's kind */
    u8 unknown50[0x88];
    int unknownd8; /* +0xd8: the state FUN_00583bb0 leaves */
    u8 unknowndc[0x14];
};

/* An owner whose handlers call through a device at +0xf0: the handlers of
 * the tables at +0x5a0 and +0x7a0 of FUN_00be6da0's and FUN_00525530's
 * object, of FUN_0058c760's and of FUN_00be6da0's (FUN_00583950 and its
 * siblings). derived name */
struct DeviceOwner583950 : Owner583950 {
    Device583950 *device; /* +0xf0 */
};

/* An owner that keeps the nodes it has handed on, each once: the handlers
 * of the tables at +0x17a0 and +0x1ba0 of FUN_00525530's object
 * (FUN_00595220, FUN_00590910 and their siblings: the list at +0xf8
 * searched, then appended to). derived name */
struct NodesOwner583950 : DeviceOwner583950 {
    Array05943280<void *> nodes; /* +0xf8 */
};

/* A node of kind 31 with a list of children at +0x50 (FUN_00594920, FUN_00594a80).
 * derived name */
struct ParentNode583950Kind31 {
    u8 unknown0[0x50];
    Node583950 **children; /* +0x50 */
    unsigned count;        /* +0x58 */
};

/* A node of kind 32 with a list of children at +0x80 (FUN_0058fa80).
 * derived name */
struct ParentNode583950Kind32 {
    u8 unknown0[0x80];
    Node583950 **children; /* +0x80 */
    unsigned count;        /* +0x88 */
};

/* A node of kind 33 with a list of children at +0x40 (FUN_00596360, FUN_005964c0).
 * derived name */
struct ParentNode583950Kind33 {
    u8 unknown0[0x40];
    Node583950 **children; /* +0x40 */
    unsigned count;        /* +0x48 */
};

/* A node of kind 34 with a list of children at +0x78 (FUN_00595990, FUN_00595af0).
 * derived name */
struct ParentNode583950Kind34 {
    u8 unknown0[0x78];
    Node583950 **children; /* +0x78 */
    unsigned count;        /* +0x80 */
};

/* A node of kind 35 with a list of children at +0x88 (FUN_00595dc0, FUN_00595f20).
 * derived name */
struct ParentNode583950Kind35 {
    u8 unknown0[0x88];
    Node583950 **children; /* +0x88 */
    unsigned count;        /* +0x90 */
};

/* A node of kind 36 with a list of children at +0x78 (FUN_00595220, FUN_00595380).
 * derived name */
struct ParentNode583950Kind36 {
    u8 unknown0[0x78];
    Node583950 **children; /* +0x78 */
    unsigned count;        /* +0x80 */
};

/* A node of kind 37 with a list of children at +0x30 (FUN_00594d90, FUN_00594ef0).
 * derived name */
struct ParentNode583950Kind37 {
    u8 unknown0[0x30];
    Node583950 **children; /* +0x30 */
    unsigned count;        /* +0x38 */
};

/* A node of kind 38 with a list of children at +0x68 (FUN_00592f10).
 * derived name */
struct ParentNode583950Kind38 {
    u8 unknown0[0x68];
    Node583950 **children; /* +0x68 */
    unsigned count;        /* +0x70 */
};

/* A node of kind 39 with a list of children at +0x48 (FUN_005935c0, FUN_00593720).
 * derived name */
struct ParentNode583950Kind39 {
    u8 unknown0[0x48];
    Node583950 **children; /* +0x48 */
    unsigned count;        /* +0x50 */
};

/* A node of kind 40 with a list of children at +0x58 (FUN_00593ca0).
 * derived name */
struct ParentNode583950Kind40 {
    u8 unknown0[0x58];
    Node583950 **children; /* +0x58 */
    unsigned count;        /* +0x60 */
};

/* A node of kind 41 with a list of children at +0x50 (FUN_00594260, FUN_005943c0).
 * derived name */
struct ParentNode583950Kind41 {
    u8 unknown0[0x50];
    Node583950 **children; /* +0x50 */
    unsigned count;        /* +0x58 */
};

/* A node of kind 42 with a list of children at +0x50 (FUN_005907b0, FUN_00590910).
 * derived name */
struct ParentNode583950Kind42 {
    u8 unknown0[0x50];
    Node583950 **children; /* +0x50 */
    unsigned count;        /* +0x58 */
};

/* A node of kind 43 with a list of children at +0x60 (FUN_00591c40, FUN_00591da0).
 * derived name */
struct ParentNode583950Kind43 {
    u8 unknown0[0x60];
    Node583950 **children; /* +0x60 */
    unsigned count;        /* +0x68 */
};

/* A node of kind 44 with a list of children at +0x38 (FUN_00590290).
 * derived name */
struct ParentNode583950Kind44 {
    u8 unknown0[0x38];
    Node583950 **children; /* +0x38 */
    unsigned count;        /* +0x40 */
};

/* An owner with a current value, the call frame and a second list: the
 * handlers of the tables at +0x9a0, +0x42a0 and +0x44a0 of FUN_00525530's
 * object (the value at +0xf0 read by its type at +0x100: 0 an int, 4 a
 * float, 7 three floats, FUN_0058fc10; the frame FUN_0059ab60 appends to),
 * of the table FUN_00525530's caller builds on its stack (the copies between
 * the two lists, FUN_005839e0) and of FUN_00aec5d0's and FUN_005f2b90's.
 * derived name */
struct ValueOwner583950 : Owner583950 {
    union {
        int intValue;
        float floatValue;
        float vector[3];
    }; /* +0xf0 */

    int valueType; /* +0x100 */
    u8 unknown104[0xc];
    CallFrame583950 *frame; /* +0x110 */
    u8 unknown118[0x78];
    /* +0x190: a second list of the same nodes with its own current index,
     * whose state byte FUN_00af09d0 and its three copies set from the
     * first's. derived name */
    NodeCursor583950 cursor190;
    u8 unknown1a0[0x38];
    /* +0x1d8: a flag the handler FUN_00589500 raises from its node's bit
     * while +0x1dc is set, then restores. derived names */
    int unknown1d8;
    int unknown1dc; /* +0x1dc */
};

#endif
