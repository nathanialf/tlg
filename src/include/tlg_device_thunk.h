/* An object at +0xf0 of its owner whose first virtual method takes a pointer
 * and an int and returns a pointer (the handlers FUN_00599340, FUN_00599dc0
 * and FUN_00c02790 store through it); three matched thunks in src/game/unknown/ forward their own
 * second argument to it with a constant and return 0. derived names. */
#ifndef TLG_DEVICE_THUNK_H
#define TLG_DEVICE_THUNK_H

#include "tlg_types.h"

struct Device583950Vtable {
    void *(*method0)(void *self, void *arg, int mode);
};

struct Device583950 {
    Device583950Vtable *vtable;
};

struct Owner583950;

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

struct Owner583950 {
    /* finds a node of the list, searched from the current index to the
     * end, then from the start up to the current index: false when it is not
     * in the list, else its index in the argument (derived name) */
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

    /* makes a node of the list the current one; nothing changes when the
     * node is not in it (FUN_00583980 and the six handlers of the same
     * body). derived name */
    void select(void *node)
    {
        unsigned index;
        if (find(node, index))
            current = index;
    }

    /* the storage of the current node: the first node's value is at the
     * start of the list's storage, each later one's at its offset
     * (FUN_0058da20 and its two copies; FUN_0057f9d0 and FUN_00584df0 read
     * the same fields). derived name */
    char *currentValue() const
    {
        const NodeList583950 *nodes = list;
        const int offset = current != 0 && current < nodes->count ? nodes->offsets[current - 1] : 0;
        return nodes->values + offset;
    }

    /* the state byte of the current node, null when the index is past the
     * list's end. derived name */
    u8 *currentState() const
    {
        const NodeList583950 *nodes = list;
        return current < nodes->count ? nodes->states + current : 0;
    }

    /* makes a node of the list the current one and returns its state byte;
     * null when the node is not in the list (FUN_00583bb0). derived name */
    u8 *selectState(void *node)
    {
        unsigned index;
        if (!find(node, index))
            return 0;
        current = index;
        return currentState();
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
    unsigned current; /* +0x38: the index of the current node in the list */
    u8 unknown3c[4];
    NodeList583950 *list;    /* +0x40 */
    Handler583950 *handlers; /* +0x48, indexed by a node's kind */
    u8 unknown50[0x88];
    int unknownd8; /* +0xd8: the state FUN_00583bb0 leaves */
    u8 unknowndc[0x14];

    /* +0xf0: the owner's current value, read by its type at +0x100 (0 an
     * int, 4 a float, 7 three floats: FUN_0058fc10) or as the object the
     * handlers FUN_00583950 and its siblings call through. derived names */
    union {
        Device583950 *device;
        int intValue;
        float floatValue;
        float vector[3];
    };

    int valueType; /* +0x100 */
};

#endif
