/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: builds a 32-bit word for an index (unsigned: zero-extended):
 * the low byte of the int the table at 0x15574b0 holds at the index, the low 4
 * bits of the int the table at 0x15574c0 holds at the index shifted to bits 8
 * to 11, and the constant bits 0x924000. Called from FUN_001adf20 (0x1adf91).
 * The two tables are the game's objects, declared (their content not claimed). */
extern const u32 D_15574b0[];
extern const u32 D_15574c0[];

u32 FUN_012fd1f0(unsigned index) /* derived name */
{
    return 0x924000 | (D_15574c0[index] & 0xf) << 8 | (D_15574b0[index] & 0xff);
}
