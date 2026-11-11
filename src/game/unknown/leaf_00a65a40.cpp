/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the accessor of the table of 3 named values: the guarded
 * static array at 0x5828860 (guard 0x5828858; its destructor
 * FUN_00a66330 registered with __cxa_atexit) and the guarded static table
 * over it at 0x5828890 (guard 0x5828888, vtable 0x16ce688). Called by the
 * three slots of leaf_0138df50.cpp. */
extern const char D_15cc29a[6]; /* "FALSE" */
extern const char D_14cc6f5[3]; /* "IN" */
extern const char D_15a56d0[4]; /* "OUT" */

// NONMATCHING: the two residuals of tlg_game_name.h's accessors: the base drops the
// constant return (nothing in rax: IPSCCP zaps the returns of a local-linkage
// function only), and folds the vtable's address point into the `lea` (the
// class's key function, slot 3, is not yet in the module).
Object016ce688 &FUN_00a65a40()
{
    static NamedValue D_5828860[] = {
        {D_15cc29a, {0x7f, 0x7f, 0x7f}, 0},
        {D_14cc6f5, {0xff, 0x00, 0x00}, 1},
        {D_15a56d0, {0xff, 0x00, 0xff}, 2},
    };
    static Object016ce688 D_5828890(D_5828860);
    return D_5828890;
}
