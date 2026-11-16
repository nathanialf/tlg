/* An object at +0xf0 of its owner whose first virtual method takes a pointer
 * and an int and returns a pointer (the handlers FUN_00599340, FUN_00599dc0
 * and FUN_00c02790 store through it); three matched thunks in src/game/unknown/ forward their own
 * second argument to it with a constant and return 0. derived names. */
#ifndef TLG_DEVICE_THUNK_H
#define TLG_DEVICE_THUNK_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_math.h"

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
    /* the first node of a list current (derived name) */
    explicit NodeCursor583950(NodeList583950 *list_) : current(0), list(list_) {}

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

/* a four-character code as its characters lie in memory, the first at the
 * lowest address (derived name) */
inline unsigned fourCharCode(char a, char b, char c, char d)
{
    return (unsigned)(unsigned char)a | (unsigned)(unsigned char)b << 8 |
           (unsigned)(unsigned char)c << 16 | (unsigned)(unsigned char)d << 24;
}

/* What every handler of the tables FUN_00525530, FUN_00be6da0 and their
 * callers fill is given: the list with its current index and the table of
 * handlers by kind. The owner is not the object that holds the tables: each
 * walk builds one on its stack, a four-character code at +0x0 ('XAOC',
 * 'XAER', 'XAIT', 'XAAS', 'XFIT'), with +0x48 pointing at one table of
 * FUN_00525530's object or at a table on the same stack (FUN_005269a0
 * builds them, then calls the handler with the stack object in rdi; a
 * handler that walks further builds the next one, FUN_00588200,
 * FUN_00591f30). What follows +0xf0 differs by code: an owner of each kind
 * derives from this one. derived name */
struct Owner583950 {
    /* an owner of the given codes over a list, with its handlers (the
     * 'XFIT' owners of FUN_00588200 and FUN_005890d0). derived name */
    Owner583950(unsigned code_, unsigned parentCode_, NodeList583950 *list, void *unknown18_,
                void *unknown28_, Handler583950 *table)
        : code(code_), parentCode(parentCode_), unknown8(-1), unknown10(0), unknown18(unknown18_),
          unknown28(unknown28_), unknown30(0), cursor(list), handlers(table), unknownd8(0)
    {
    }

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

    /* +0x0: the four-character codes of the owner and of the owner it was
     * built from ('XFIT' and 'XAIT', FUN_00588200). derived names */
    unsigned code;
    unsigned parentCode; /* +0x4 */
    int unknown8;        /* +0x8: -1 when built */
    int unknownc;        /* +0xc: the builder's */
    void *unknown10;     /* +0x10: 0 when built */
    void *unknown18;     /* +0x18: the builder's */
    u8 unknown20[8];
    void *unknown28;         /* +0x28: the builder's */
    void *unknown30;         /* +0x30: 0 when built */
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
struct FrameOwner583950;

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
    u8 unknown0[0xc];
    Name name; /* +0xc */
    u8 unknown10[0x18];
    unsigned debugFlags; /* +0x28: bit 0 writes a message (FUN_0058fc10) */
    /* +0x2c: bit 0 the record takes the default first, bit 1 it is kept
     * at the minimum or above, bit 2 at the maximum or below */
    unsigned flags;
    int kind;              /* +0x30: 0 a float, 1 an int, 2 a vector */
    float floatDefault;    /* +0x34 */
    float floatMinimum;    /* +0x38 */
    float floatMaximum;    /* +0x3c */
    int intDefault;        /* +0x40 */
    int intMinimum;        /* +0x44 */
    int intMaximum;        /* +0x48 */
    Float4A vectorDefault; /* +0x50 */
    Float4A vectorMinimum; /* +0x60 */
    Float4A vectorMaximum; /* +0x70 */
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
    u8 unknown0[0x30];
    int unknown30; /* +0x30: copied to its record (FUN_00592d90) */
    int unknown34; /* +0x34 */
    u8 unknown38[8];
    int unknown40[4]; /* +0x40: copied to its record */
    u8 unknown50[0x18];
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

/* The records the device returns for a node of kinds 32, 38, 40 and 44 (the
 * handlers of the table at +0x17a0, FUN_0058f910, FUN_00592d90,
 * FUN_00593b30 and FUN_00590130: each asks the device for its record's size
 * and fills what it returns). derived names */
struct Record583950Kind32 {
    int unknown0;
    float floatValue; /* +0x4 */
    int unknown8;
    int intValue; /* +0xc */
    u8 unknown10[0x10];
    Float4A vector; /* +0x20: (0, 0, 0, 1) when made */
};

struct Record583950Kind38 {
    int unknown0;
    int unknown4; /* +0x4 */
    int unknown8; /* +0x8 */
    int unknownc;
    int unknown10[4]; /* +0x10 */
};

struct Record583950Kind40 {
    Float4 unknown0;  /* +0x0 */
    Float4 unknown10; /* +0x10 */
    int unknown20;    /* +0x20 */
    u8 unknown24[0xc];
    Float4 unknown30; /* +0x30 */
};

/* An owner with a current value ('XFIT', built by FUN_00588200 from an
 * 'XAIT' owner's +0x158): the handlers of the tables at +0x42a0 and +0x44a0
 * of FUN_00525530's object (the value at +0xf0 read by its type at +0x100:
 * 0 an int, 4 a float, 7 three floats, FUN_0058fc10). derived name */
struct ValueOwner583950 : Owner583950 {
    /* an owner built from an 'XAIT' one, to walk its nodes with the given
     * handlers (FUN_00588200, FUN_005890d0). derived name */
    inline ValueOwner583950(const FrameOwner583950 &builder, Handler583950 *table, int depth);

    union {
        int intValue;
        float floatValue;
        Float4A vector; /* a copy of it is one aligned 16-byte move (FUN_0058fc10) */
    }; /* +0xf0 */

    int valueType; /* +0x100 */
    u8 unknown104[4];
    void *unknown108; /* +0x108: the 'XAIT' builder's +0x100 */
    void *unknown110; /* +0x110: the 'XAIT' builder's +0x120 */
    int unknown118;   /* +0x118: 0 when built */
    int depth;        /* +0x11c: the count the builder's node value keeps (derived name) */
    void *unknown120; /* +0x120: the 'XAIT' builder's +0x180 */
    void *unknown128; /* +0x128: the 'XAIT' builder's +0x1b0 */
};

/* The handlers of the default table of the 'XFIT' owners (FUN_00525530
 * stores the same at +0x42a0 of its object). derived names */
int FUN_00c05e90(ValueOwner583950 *self, void *arg);
int FUN_00c65c00(ValueOwner583950 *self, void *arg);
int FUN_00c65ce0(ValueOwner583950 *self, void *arg);
int FUN_00c65ff0(ValueOwner583950 *self, void *arg);
int FUN_00c05d90(ValueOwner583950 *self, void *arg);
int FUN_00c05e10(ValueOwner583950 *self, void *arg);

/* A table of handlers by kind, cleared when made; the walk handlers make
 * one on their stack (FUN_00588200, FUN_005890d0: the stores the 16 bytes
 * at a time to it are unaligned, so it is not the bare array). derived name */
struct HandlerTable583950 {
    HandlerTable583950()
    {
        memset(handlers, 0, sizeof(handlers));
    }

    /* the default table of the 'XFIT' owners, used when the 'XAIT' owner
     * has none (derived name) */
    void setValueDefaults()
    {
        memset(handlers, 0, sizeof(handlers));
        handlers[17] = reinterpret_cast<Handler583950>(FUN_00c65c00);
        handlers[18] = reinterpret_cast<Handler583950>(FUN_00c65ce0);
        handlers[19] = reinterpret_cast<Handler583950>(FUN_00c65ff0);
        handlers[38] = reinterpret_cast<Handler583950>(FUN_00c05d90);
        handlers[39] = reinterpret_cast<Handler583950>(FUN_00c05e10);
        handlers[1] = reinterpret_cast<Handler583950>(FUN_00c05e90);
    }

    Handler583950 handlers[128];
};

/* An owner with the call frame and a second list ('XAIT', FUN_005269a0
 * builds it with -1.0f at +0xf0 and +0xf4 and -1 at +0xf8, its +0x100 a
 * pointer the 'XFIT' owners it builds keep at +0x108): the handlers of the
 * tables at +0x9a0 and +0xba0 of FUN_00525530's object (the frame
 * FUN_0059ab60 appends to), of the table FUN_005269a0 builds on its stack
 * (the copies between the two lists, FUN_005839e0) and of FUN_00aec5d0's and
 * FUN_005f2b90's. derived name */
struct FrameOwner583950 : Owner583950 {
    float unknownf0; /* +0xf0 */
    float unknownf4; /* +0xf4: -1 when FUN_0059ab60 is done */
    int unknownf8;   /* +0xf8 */
    u8 unknownfc[4];
    void *unknown100; /* +0x100: kept by the 'XFIT' owners it builds at +0x108 */
    u8 unknown108[8];
    CallFrame583950 *frame; /* +0x110 */
    u8 unknown118[8];
    void *unknown120; /* +0x120 */
    u8 unknown128[0x30];
    /* +0x158: the handlers of the 'XFIT' owners it builds (the table at
     * +0x42a0 of FUN_00525530's object); when null, FUN_00588200 makes the
     * default table on its stack. derived name */
    Handler583950 *valueHandlers;
    u8 unknown160[0x20];
    void *unknown180; /* +0x180 */
    u8 unknown188[8];
    /* +0x190: a second list of the same nodes with its own current index,
     * whose state byte FUN_00af09d0 and its three copies set from the
     * first's. derived name */
    NodeCursor583950 cursor190;
    u8 unknown1a0[0x10];
    void *unknown1b0; /* +0x1b0 */
    u8 unknown1b8[0x20];
    /* +0x1d8: a flag the handler FUN_00589500 raises from its node's bit
     * while +0x1dc is set, then restores. derived names */
    int unknown1d8;
    int unknown1dc; /* +0x1dc */
};

inline ValueOwner583950::ValueOwner583950(const FrameOwner583950 &builder, Handler583950 *table,
                                          int depth_)
    : Owner583950(fourCharCode('X', 'F', 'I', 'T'), fourCharCode('X', 'A', 'I', 'T'),
                  builder.cursor.list, builder.unknown18, builder.unknown28, table),
      unknown118(0), depth(depth_)
{
    unknownc = builder.unknownc;
    unknown108 = builder.unknown100;
    unknown110 = builder.unknown120;
    unknown120 = builder.unknown180;
    unknown128 = builder.unknown1b0;
}

#endif
