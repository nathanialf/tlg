/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 8 of the vtable at 0x16cf9f8 (its pointer at 0x16cfa48):
 * when the int at +0x60 is nonzero, dispatches on the unsigned int at +0x94
 * (0 to 3; any other value does nothing) to FUN_00b420f0, FUN_00b42220,
 * FUN_00b42350 or FUN_00b42480, a tail call with the object, the float argument
 * and that argument times 30 (frames at 30 per second). The callees' other
 * parameters are not traced. Class and method unknown. */
struct Object013999c0 /* derived name */
{
    u8 unknown0[0x60];
    int unknown60; /* +0x60 */
    u8 unknown64[0x30];
    unsigned unknown94; /* +0x94: the mode */
};

void FUN_00b420f0(Object013999c0 *self, float time, float frames); /* derived name */
void FUN_00b42220(Object013999c0 *self, float time, float frames); /* derived name */
void FUN_00b42350(Object013999c0 *self, float time, float frames); /* derived name */
void FUN_00b42480(Object013999c0 *self, float time, float frames); /* derived name */

// NONMATCHING: the switch's range check lays out the other way: the base falls
// through to the return (`jbe` to the table), where this falls through to the table
// (`ja` to the return); the rest is the same.
void FUN_013999c0(Object013999c0 *self, float time) /* derived name */
{
    if (!self->unknown60)
        return;
    float frames = time * 30.0f;
    switch (self->unknown94) {
    case 0:
        FUN_00b420f0(self, time, frames);
        break;
    case 1:
        FUN_00b42220(self, time, frames);
        break;
    case 2:
        FUN_00b42350(self, time, frames);
        break;
    case 3:
        FUN_00b42480(self, time, frames);
        break;
    }
}
