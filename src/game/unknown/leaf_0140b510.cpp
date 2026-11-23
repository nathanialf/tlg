/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_array01343a80.h"

/* derived names: three cleared ints and an array of values with its lock,
 * made `count` long and cleared by a byte counter (`dec al; movzx eax, al`)
 * by the constructor (called by FUN_010b0530 and FUN_012bc3a0); not traced */
struct Record0140b510 { /* derived name */
    Record0140b510(unsigned count);

    int unknown0;              /* +0x0 */
    int unknown4;              /* +0x4 */
    int unknown8;              /* +0x8 */
    Array01343a80<u32> values; /* +0x10 */
};

/* FUN_0140b510 */
Record0140b510::Record0140b510(unsigned count) : unknown0(0), unknown4(0), unknown8(0)
{
    values.resize(count);
    for (u8 i = 0; i < count; ++i)
        values[i] = 0;
}
