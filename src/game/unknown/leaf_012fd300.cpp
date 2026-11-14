/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_format012fd300.h"

/* derived names: returns the unsigned int the kind of its argument (a format
 * word, tlg_game_format012fd300.h) selects in the table at 0x15253d0 (61
 * words, 0 for a kind above 60; its
 * first entries 0, 8, 16, 16, 32: a width in bits), a call from FUN_001a3e00
 * and FUN_001a6890. The table is the game's object, read PC-relative from 50
 * sites (0xb24837 and on), declared here and defined by the game module's
 * stand-in. What the kind names is not traced. */
extern const unsigned D_15253d0[61];

unsigned FUN_012fd300(const Format012fd300 *format) /* derived name */
{
    if (format->kind > 60)
        return 0;
    return D_15253d0[format->kind];
}
