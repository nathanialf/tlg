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

struct Owner583950 {
    u8 unknown0[0x48];
    Handler583950 *handlers; /* +0x48, indexed by a node's kind */
    u8 unknown50[0xa0];
    Device583950 *device; /* +0xf0 */
};

#endif
