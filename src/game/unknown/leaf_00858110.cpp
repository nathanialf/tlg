/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_counted007262a0.h"

/* derived names: the object FUN_00858110 is handed, with the object it
 * holds at +0x28 */
struct Object00858110 : Object016b9108 { /* derived name */
    Counted007262a0 *held28;             /* +0x28 */
};

/* derived names: the object at 0x57c9390 as FUN_00858110 reads it: the
 * record at +0xc8, whose array of references is at +0x150 */
struct Record00858110 { /* derived name */
    u8 unknown0[0x150];
    Array007262a0 objects150; /* +0x150 */
};

struct Object057c9390_c8 { /* derived name */
    u8 unknown0[0xc8];
    Record00858110 *unknownc8; /* +0xc8 */
};

extern Object057c9390_c8 *D_57c9390;
extern const Type00503fb0 *D_59391e0; /* derived name: the object's type */
extern const Type00503fb0 *D_581cb60; /* derived name: the held object's type */

/* FUN_00858110: for an object of the type at 0x59391e0 (or one derived
 * from it) whose object at +0x28 is of the type at 0x581cb60: bit 0 of the
 * held object's flags cleared (slot 34 answers them, slot 35 takes them)
 * and a reference to it appended to the array at +0x150 of the global
 * object's record (FUN_007262a0, called with a temporary reference);
 * returns 1. Its callers are not traced. */
int FUN_00858110(Object00858110 *object) /* derived name */
{
    if (object->isKindOf(D_59391e0)) {
        Counted007262a0 *held = object->held28;
        if (held->isKindOf(D_581cb60)) {
            held->setFlags(held->flags() & ~1u);
            D_57c9390->unknownc8->objects150.push(Ref00503fb0<Counted007262a0>(held));
        }
    }
    return 1;
}
