/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the accessor of the table of 9 named values: the guarded
 * static array at 0x58288c0 (guard 0x58288b8; its destructor
 * FUN_00a663f0 registered with __cxa_atexit) and the guarded static table
 * over it at 0x5828938 (guard 0x5828930, vtable 0x16ce6d0). Called by the
 * three slots of leaf_0138dfe0.cpp. */
extern const char D_15a56a5[8]; /* "Nothing" */
extern const char D_15a56d4[6]; /* "Floor" */
extern const char D_15a56da[5]; /* "Wall" */
extern const char D_15a56df[5]; /* "Roof" */
extern const char D_15a56e4[6]; /* "Fence" */
extern const char D_15a56ea[7]; /* "Pillar" */
extern const char D_15a56f1[6]; /* "Torch" */
extern const char D_15a9055[7]; /* "Switch" */
extern const char D_15a56f7[4]; /* "Far" */

// NONMATCHING: the two residuals of tlg_game_name.h's accessors: the base drops the
// constant return (nothing in rax: IPSCCP zaps the returns of a local-linkage
// function only), and folds the vtable's address point into the `lea` (the
// class's key function, slot 3, is not yet in the module).
Object016ce6d0 &FUN_00a65bd0()
{
    static NamedValue D_58288c0[] = {
        {D_15a56a5, {0x7f, 0x7f, 0x7f}, 0}, {D_15a56d4, {0x7f, 0x40, 0x00}, 1},
        {D_15a56da, {0x00, 0x7f, 0x00}, 2}, {D_15a56df, {0x40, 0x7f, 0xbf}, 3},
        {D_15a56e4, {0x00, 0xff, 0xff}, 4}, {D_15a56ea, {0x7f, 0xbf, 0x40}, 5},
        {D_15a56f1, {0xff, 0x00, 0x7f}, 6}, {D_15a9055, {0x00, 0x00, 0x7f}, 7},
        {D_15a56f7, {0xbf, 0xbf, 0xbf}, 8},
    };
    static Object016ce6d0 D_5828938(D_58288c0);
    return D_5828938;
}
