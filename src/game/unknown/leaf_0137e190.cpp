/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: an object holding another at +0x148; the other fields are
 * not traced */
struct Object0137e190 { /* derived name */
    u8 unknown0[0x148];
    Object016b9108 *unknown148; /* +0x148 */
};

extern Type00503fb0 *D_5821210; /* derived name: the held object's type */

void FUN_0095b9a0(Object0137e190 *self, Object016b9108 *object); /* derived name; not traced */

/* derived name: FUN_0095b9a0 with the held object when it is of the type
 * D_5821210 points to (or one derived from it), else with null; a tail call */
// NONMATCHING: the walk's flag polarity (3/24): the base keeps "not found" (`mov sil,
// 1` in the loop, `xor esi, esi` on each found arm, `cmovne rax, rcx(0)`), the
// build "found" (`mov cl, 1` before the loop, `cmovne rsi, rax`)
void FUN_0137e190(Object0137e190 *self) /* derived name */
{
    Object016b9108 *object = self->unknown148;
    if (object && !object->isKindOf(D_5821210))
        object = 0;
    FUN_0095b9a0(self, object);
}
