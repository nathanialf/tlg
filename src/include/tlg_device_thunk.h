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

/* The owner's list of nodes: a count and an array of pointers (read by
 * FUN_00583980 and its six copies). derived names. */
struct NodeList583950 {
    u8 unknown0[8];
    unsigned count; /* +0x8 */
    void **items;   /* +0x10 */
};

struct Owner583950 {
    /* finds a node of the list, searched from the current index to the
     * end, then from the start up to the current index: false when it is not
     * in the list, else its index in the argument (derived name) */
    bool find(void *node, unsigned &index) const
    {
        for (int i = current; i < list->count; ++i) {
            if (list->items[i] == node) {
                index = i;
                return true;
            }
        }
        for (int i = 0; i < current; ++i) {
            if (list->items[i] == node) {
                index = i;
                return true;
            }
        }
        return false;
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
    u8 unknown50[0xa0];
    Device583950 *device; /* +0xf0 */
};

#endif
