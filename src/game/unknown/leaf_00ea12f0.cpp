/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"

/* derived names: the function at 0x16be5a0 (+0x110 from the vtable stored at
 * 0x16be490): when its argument has a body (the record at +0x48, its body id
 * at +0x34 not 0x7fffffff, the invalid id), calls hknpWorld::FUN_0005bf80 (the
 * body's collision caches rebuilt) with the id on the world the record's index
 * at +0x30 selects in the array of 0x720-byte worlds at +0x38 of the object's
 * pointer at +0x268, a null world when that pointer is null; a tail call. The
 * classes are not traced. */
struct Body00ea12f0 { /* derived name */
    u8 unknown0[0x30];
    unsigned unknown30;
    int unknown34;
};

struct Argument00ea12f0 { /* derived name */
    u8 unknown0[0x48];
    Body00ea12f0 *unknown48;
};

struct Worlds00ea12f0 { /* derived name */
    u8 unknown0[0x38];
    hknpWorld *unknown38;
};

struct Object00ea12f0 { /* derived name */
    u8 unknown0[0x268];
    Worlds00ea12f0 *unknown268;
};

void FUN_00ea12f0(Object00ea12f0 *self, Argument00ea12f0 *argument) /* derived name */
{
    Body00ea12f0 *body = argument->unknown48;
    if (body == 0 || body->unknown34 == 0x7fffffff) {
        return;
    }
    hknpWorld *world = self->unknown268 != 0 ? &self->unknown268->unknown38[body->unknown30] : 0;
    world->FUN_0005bf80(body->unknown34);
}
