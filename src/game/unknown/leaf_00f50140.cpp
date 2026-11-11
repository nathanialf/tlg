/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: an object whose slot 2 is called with a second object
 * (FUN_00f50140 and its siblings). */
struct Listener00f50140 /* derived name */
{
    struct Vtable {
        void *unknown0[2];
        void (*notify)(Listener00f50140 *self, void *from); /* slot 2 */
    } *vtable;
};

/* derived names: one entry of the owner's table, 24 bytes */
struct Entry00f50140 /* derived name */
{
    u8 unknown0[8];
    Listener00f50140 *listener; /* +0x8 */
    u8 unknown10[8];
};

struct Owner00f50140 /* derived name */
{
    u8 unknown0[0x290];
    Entry00f50140 *entries; /* +0x290 */
    unsigned count;         /* +0x298 */
};

struct Object00f50140 /* derived name */
{
    u8 unknown0[8];
    Owner00f50140 *owner; /* +0x8 */
    u8 unknown10[0x60];
    int unknown70; /* +0x70 */
};

void FUN_013cf950(Object00f50140 *self); /* derived name */

/* derived names: slot 2 of the vtable at 0x16bf2e8 (stored by
 * FUN_00f2c5d0): runs FUN_013cf950 on the object, hands it to the listener
 * of every entry of its owner's table (slot 2 of each, the table and its
 * count read again after each call), then clears the int at +0x70. */
// NONMATCHING: IndVarSimplify, the base keeps the int index with movsxd in the loop where the build widens it (LSR then strides 0x18); 2 of 31
void FUN_00f50140(Object00f50140 *self) /* derived name */
{
    FUN_013cf950(self);
    for (int i = 0; i < self->owner->count; ++i) {
        Listener00f50140 *listener = self->owner->entries[i].listener;
        listener->vtable->notify(listener, self);
    }
    self->unknown70 = 0;
}
