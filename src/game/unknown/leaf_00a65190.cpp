/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the accessor of the table of 5 named values: the guarded
 * static array at 0x5828660 (guard 0x5828658; its destructor
 * FUN_00a65f80 registered with __cxa_atexit) and the guarded static table
 * over it at 0x58286a8 (guard 0x58286a0, vtable 0x16ce4d8). Called by the
 * three slots of leaf_0138dbf0.cpp. */
extern const char D_15a56a5[8];  /* "Nothing" */
extern const char D_15a56ad[5];  /* "Slip" */
extern const char D_15a56b2[8];  /* "Stumble" */
extern const char D_15a56ba[10]; /* "ForceSlip" */
extern const char D_15a56c4[7];  /* "NoJump" */

// NONMATCHING: the two residuals of tlg_game_name.h's accessors: the base drops the
// constant return (nothing in rax: IPSCCP zaps the returns of a local-linkage
// function only), and folds the vtable's address point into the `lea` (the
// class's key function, slot 3, is not yet in the module).
Object016ce4d8 &FUN_00a65190()
{
    static NamedValue D_5828660[] = {
        {D_15a56a5, {0x7f, 0x7f, 0x7f}, 0}, {D_15a56ad, {0x40, 0x00, 0x00}, 1},
        {D_15a56b2, {0x40, 0x40, 0x00}, 2}, {D_15a56ba, {0x00, 0x00, 0x40}, 3},
        {D_15a56c4, {0xbf, 0x10, 0x10}, 4},
    };
    static Object016ce4d8 D_58286a8(D_5828660);
    return D_58286a8;
}
