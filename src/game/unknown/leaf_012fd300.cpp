/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the unsigned int the byte its argument points to
 * selects in the table at 0x15253d0 (61 words, 0 for a byte above 60; its
 * first entries 0, 8, 16, 16, 32: a width in bits), a call from FUN_001a3e00
 * and FUN_001a6890. The table is the game's object, read PC-relative from 50
 * sites (0xb24837 and on), declared here and defined by the game module's
 * stand-in. What the byte names is not traced. */
extern const unsigned D_15253d0[61];

// NONMATCHING: the bound test is `cmp rcx, 0x3c` (i64, the index's width) where the base's is `cmp ecx, 0x3c`; the byte switched at i32, as 0x12fd360's switch on a byte is in the base and not in 4.0.0 (InstCombine visitSwitchInst, NOTES round 132B): the table may be a switch's lookup table merged module-wide, not tested
unsigned FUN_012fd300(const u8 *type) /* derived name */
{
    if (*type > 60)
        return 0;
    return D_15253d0[*type];
}
