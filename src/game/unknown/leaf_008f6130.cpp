/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

#include "tlg_math.h"
#include "tlg_game_array.h"

/* derived names: an object of the tree FUN_008f4020 walks, its four floats
 * at +0x50 handed out by value (read before the array is grown: `vmovups
 * xmm0, [rdi+0x50]` first) */
struct Object008f6130 { /* derived name */

    Float4 value() const /* derived name */
    {
        return unknown50;
    }

    u8 unknown0[0x50];
    Float4 unknown50; /* +0x50 */
};

/* derived names: a callback FUN_008f4020 passes to FUN_01370670 (lea at
 * 0x8f4697) with the array at +0x70 of its object as its context: the
 * object's four floats appended to the array */
void FUN_008f6130(Object008f6130 *object, Array05943280<Float4> *values) /* derived name */
{
    values->push(object->value());
}
