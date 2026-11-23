/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"

#include "tlg_game_name.h"

/* derived names: three slots of 0x28 bytes, each 32 bytes of data and two
 * names, then 0x18 bytes (FUN_0136f080 makes the names empty, clears the set
 * and releases each slot's first name; FUN_007f1630, FUN_007f4cd0 and
 * FUN_007f9b40 clear it). The data's meaning is not traced. */
struct Slot0136efa0 { /* derived name */
    u8 unknown0[0x20];
    Name name20; /* +0x20 */
    Name name24; /* +0x24 */
};

struct Slots0136efa0 { /* derived name */
    void clear();

    Slot0136efa0 slots[3]; /* +0x0 */
    u32 unknown78[4];      /* +0x78 */
    u64 unknown88;         /* +0x88 */
};

/* FUN_0136efa0: each slot's data cleared and its second name released, then
 * the tail cleared */
void Slots0136efa0::clear()
{
    for (int i = 0; i < 3; ++i) {
        memset(slots[i].unknown0, 0, sizeof(slots[i].unknown0));
        slots[i].name24.release();
    }
    for (int i = 0; i < 4; ++i)
        unknown78[i] = 0;
    unknown88 = 0;
}
