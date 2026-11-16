/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_format012fd300.h"

/* the table of FUN_012fd300 (leaf_012fd300.cpp) */
extern const unsigned D_15253d0[61];

/* derived name: the count of FUN_012fd360's switch for a kind (16, 8 or 1) */
static inline unsigned kindScale(const Format012fd300 *format) /* derived name */
{
    switch (format->kind) {
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
        return 16;
    case 0x3b:
    case 0x3c:
        return 8;
    default:
        return 1;
    }
}

/* derived name: the table's word for the kind (FUN_012fd300) times the
 * kind's scale, 0 for a kind above 60 */
unsigned FUN_012fd320(const Format012fd300 *format) /* derived name */
{
    if (format->kind > 60)
        return 0;
    return D_15253d0[format->kind] * kindScale(format);
}
