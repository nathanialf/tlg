/* src/include/tlg_game_object05adaaa8.h: the object the pointer at 0x5adaaa8
 * holds. derived names throughout; only the fields the matched functions
 * read are typed, each with the function that shows it. */
#ifndef TLG_GAME_OBJECT05ADAAA8_H
#define TLG_GAME_OBJECT05ADAAA8_H

#include "tlg_types.h"

struct Target0131e2d0;       /* derived name */
struct Member05adaaa8_10238; /* derived name */

struct Object05adaaa8 { /* derived name */
    u8 unknown0[0x100a0];
    /* +0x100a0: incremented atomically (`lock inc qword`) after each entry
     * FUN_0131e770 hands to FUN_0131e2d0 */
    long unknown100a0;
    u8 unknown100a8[0x10];
    Target0131e2d0 *unknown100b8; /* +0x100b8: FUN_0131e2d0's first argument (FUN_0131e770) */
    u8 unknown100c0[0x10238 - 0x100c0];
    Member05adaaa8_10238 *unknown10238; /* +0x10238: passed to FUN_01305ce0 by FUN_01499360 */
};

extern Object05adaaa8 *D_5adaaa8;

#endif
