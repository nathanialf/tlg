/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"
#include "tlg_types.h"

/* derived names: slot 14 of the vtable at 0x16ae4d0 (its pointer at
 * 0x16ae550), the reverse of slot 13 (FUN_008120f0): when the record the
 * pointer at +0x28 of its argument holds is set and its point at +0xf0
 * differs from the argument's at +0x50 in x, y or z, the argument's is
 * copied whole into it and bit 0 of the record's flags at +0x20 is set;
 * the object is unused. Class and method unknown. */
struct Object008120a0; /* derived name */

struct Record008120a0 { /* derived name */
    u8 unknown0[0x20];
    int flags; /* +0x20 */
    u8 unknown24[0xcc];
    Float4A position; /* +0xf0 */
};

struct Target008120a0 { /* derived name */
    u8 unknown0[0x28];
    Record008120a0 *record; /* +0x28 */
    u8 unknown30[0x20];
    Float4A position; /* +0x50 */
};

// NONMATCHING: address sinking (round 365B, single unit, 6/18, same size): the base forms the
// argument's point once (`lea rcx, [rsi+0x50]` before the first compare) and reads y and the
// copy through it (`[rcx+4]`, `[rcx]`), x and z folded from rsi; the build folds all three and
// forms the copy's address in its own block (`add rsi, 0x50`); lane() over Vec4 is 72 bytes
void FUN_008120a0(Object008120a0 *, Target008120a0 *target) /* derived name */
{
    if (Record008120a0 *record = target->record) {
        const Float4A &position = target->position;
        if (record->position.x != position.x || record->position.y != position.y ||
            record->position.z != position.z) {
            record->position = position;
            record->flags |= 1;
        }
    }
}
