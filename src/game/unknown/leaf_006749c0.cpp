/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: counts the timer at +0x2c8 down by the elapsed time while
 * it is above zero, runs FUN_00822e90, then, when the int at +0x298 or bit 4
 * of the flags at +0x20 is set, runs FUN_0134d0e0 and clears both. The
 * function's pointer is at 0x16ac1e8, slot 11 of the vtable at 0x16ac180;
 * FUN_00822e90 is slot 11 of three vtables (0x16a89f8, 0x16aaf60, 0x16ab140):
 * the method this one overrides, so it takes the elapsed time too (the base
 * keeps it in xmm0 to the call and subtracts into the timer's register).
 * The compare is not below or equal, so an unordered timer counts down too.
 * Class and method unknown. */
struct Object006749c0 { /* derived name */
    u8 unknown0[0x20];
    u8 flags; /* +0x20 */
    u8 unknown21[0x298 - 0x21];
    int unknown298; /* +0x298 */
    u8 unknown29c[0x2c8 - 0x29c];
    float timer; /* +0x2c8 */
};

void FUN_00822e90(Object006749c0 *self, float elapsed); /* derived name */
void FUN_0134d0e0(Object006749c0 *self);                /* derived name */

void FUN_006749c0(Object006749c0 *self, float elapsed) /* derived name */
{
    if (!(self->timer <= 0.0f))
        self->timer -= elapsed;
    FUN_00822e90(self, elapsed);
    if (self->unknown298 != 0 || (self->flags & 0x10)) {
        FUN_0134d0e0(self);
        self->unknown298 = 0;
        self->flags &= ~0x10;
    }
}
