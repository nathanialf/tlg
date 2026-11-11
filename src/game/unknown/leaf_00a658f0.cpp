/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the accessor of the table of 2 named values: the guarded
 * static array at 0x5828810 (guard 0x5828808; its destructor
 * FUN_00a662b0 registered with __cxa_atexit) and the guarded static table
 * over it at 0x5828830 (guard 0x5828828, vtable 0x16ce640). Called by the
 * three slots of leaf_0138dec0.cpp. */
extern const char D_15cc29a[6]; /* "FALSE" */
extern const char D_15a56cb[5]; /* "TRUE" */

// NONMATCHING: the two residuals of tlg_game_name.h's accessors: the base drops the
// constant return (nothing in rax: IPSCCP zaps the returns of a local-linkage
// function only), and folds the vtable's address point into the `lea` (the
// class's key function, slot 3, is not yet in the module).
Object016ce640 &FUN_00a658f0()
{
    static NamedValue D_5828810[] = {
        {D_15cc29a, {0x7f, 0x7f, 0x7f}, 0},
        {D_15a56cb, {0x00, 0x00, 0xff}, 1},
    };
    static Object016ce640 D_5828830(D_5828810);
    return D_5828830;
}
