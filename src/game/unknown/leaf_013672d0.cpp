/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0139b6b0.h"

/* derived names: one of the seven 0xc0-byte records at +0x3f0 of the
 * object below, each emptied by FUN_01361760; not traced */
struct Slot013672d0 /* derived name */
{
    void FUN_01361760(); /* derived name */

    u8 unknown0[0xc0];
};

/* derived names: the object at +0x4630 of the objects FUN_007189f0 and
 * FUN_00733470 reset through FUN_013672d0: the 16-byte records with a
 * counted reference at +0x88, an int at +0xa8, seven records at +0x3f0 and
 * a point at +0x930. Their meaning is not traced. */
struct Object013672d0 /* derived name */
{
    /* 0x13672d0: the int cleared, the seven records emptied in turn, the
     * point cleared, then the int cleared again and the records'
     * references dropped (the count cleared, the block kept) */
    void reset(); /* derived name */

    /* the int at +0xa8 and the records together */
    void clearEntries() /* derived name */
    {
        unknownA8 = 0;
        entries.removeAll();
    }

    u8 unknown0[0x88];
    Array05943280<Entry0139b6b0> entries; /* +0x88 */
    u8 unknownA0[0x8];
    int unknownA8; /* +0xa8 */
    u8 unknownAc[0x344];
    Slot013672d0 slots[7]; /* +0x3f0 */
    Float4A unknown930;    /* +0x930 */
};

// NONMATCHING: instruction order only: the base stores the point at +0x930 before the int at
// +0xa8 (the source's order), the build the int first; the rest equal.
void Object013672d0::reset()
{
    unknownA8 = 0;
    for (int i = 0; i < 7; i++)
        slots[i].FUN_01361760();
    unknown930 = Float4A(0.0f, 0.0f, 0.0f, 0.0f);
    clearEntries();
}
