/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the accessor of the table of 2 named values: the guarded
 * static array at 0x58287c0 (guard 0x58287b8; its destructor
 * FUN_00a66230 registered with __cxa_atexit) and the guarded static table
 * over it at 0x58287e0 (guard 0x58287d8, vtable 0x16ce5f8). Called by the
 * three slots of leaf_0138de30.cpp. */
extern const char D_15cc29a[6]; /* "FALSE" */
extern const char D_15a56cb[5]; /* "TRUE" */

// NONMATCHING: the two residuals of tlg_game_name.h's accessors: the base drops the
// constant return (nothing in rax: IPSCCP zaps the returns of a local-linkage
// function only), and folds the vtable's address point into the `lea` (the
// class's key function, slot 3, is not yet in the module).
Object016ce5f8 &FUN_00a657a0()
{
    static NamedValue D_58287c0[] = {
        {D_15cc29a, {0x7f, 0x7f, 0x7f}, 0},
        {D_15a56cb, {0xff, 0x00, 0x00}, 1},
    };
    static Object016ce5f8 D_58287e0(D_58287c0);
    return D_58287e0;
}
