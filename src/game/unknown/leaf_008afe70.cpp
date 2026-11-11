/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 2 of the vtable at 0x16af730, stored by FUN_0088b4e0 (an
 * object it builds with three pointers, at +0x8, +0x10 and +0x18; slots 0 and
 * 1 are 0x8afdd0 and 0x8afe20): passes "cansel" to FUN_0088b2b0, sets the
 * flags the pointers at +0x10 and +0x18 point to, and on the record the
 * pointer at +0x8 holds counts one in the int at +0x110 and stores -1 in the
 * int at +0x124. FUN_008b08e0 has the same body. The record's class and the
 * callee's result are not traced. Class and method unknown. */
struct Record008afe70 /* derived name */
{
    u8 unknown0[0x110];
    int unknown110; /* +0x110 */
    u8 unknown114[0x10];
    int unknown124; /* +0x124 */
};

struct Object008afe70 /* derived name */
{
    u8 unknown0[8];
    Record008afe70 *unknown8; /* +0x8 */
    bool *unknown10;          /* +0x10 */
    bool *unknown18;          /* +0x18 */
};

void FUN_0088b2b0(const char *name); /* derived name */

void FUN_008afe70(Object008afe70 *self) /* derived name */
{
    Record008afe70 *record = self->unknown8;
    FUN_0088b2b0("cansel");
    *self->unknown10 = true;
    record->unknown110++;
    record->unknown124 = -1;
    *self->unknown18 = true;
}
