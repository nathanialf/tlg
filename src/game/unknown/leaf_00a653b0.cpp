/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the accessor of the table of 2 named values: the guarded
 * static array at 0x58286d0 (guard 0x58286c8; its destructor
 * FUN_00a660b0 registered with __cxa_atexit) and the guarded static table
 * over it at 0x58286f0 (guard 0x58286e8, vtable 0x16ce520). Called by the
 * three slots of leaf_0138dc80.cpp. */
extern const char D_15cc29a[6]; /* "FALSE" */
extern const char D_15a56cb[5]; /* "TRUE" */

// NONMATCHING: the two residuals of tlg_game_name.h's accessors: the base drops the
// constant return (nothing in rax: IPSCCP zaps the returns of a local-linkage
// function only), and folds the vtable's address point into the `lea` (the
// class's key function, slot 3, is not yet in the module).
Object016ce520 &FUN_00a653b0()
{
    static NamedValue D_58286d0[] = {
        {D_15cc29a, {0x7f, 0x7f, 0x7f}, 0},
        {D_15a56cb, {0x00, 0x00, 0xff}, 1},
    };
    static Object016ce520 D_58286f0(D_58286d0);
    return D_58286f0;
}
