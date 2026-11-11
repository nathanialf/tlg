/* src/include/tlg_game_object05adaaa8.h: the object the pointer at 0x5adaaa8
 * holds. derived names throughout; only the fields the matched functions
 * read are typed, each with the function that shows it. */
#ifndef TLG_GAME_OBJECT05ADAAA8_H
#define TLG_GAME_OBJECT05ADAAA8_H

#include "tlg_types.h"

struct Target0131e2d0;       /* derived name */
struct Member05adaaa8_10238; /* derived name */

class Object05adaaa8 /* derived name */
{
  public:
    virtual void slot0();   /* derived name; not traced */
    virtual void slot1();   /* derived name; not traced */
    virtual void destroy(); /* derived name; slot 2 (FUN_013224a0) */

    /* derived name: the reference a holder drops (FUN_013224a0): the
     * count taken down atomically, slot 2 called for the last one, the
     * count returned read again after the decrement */
    long release()
    {
        if (__sync_fetch_and_sub(&references, 1) == 1)
            destroy();
        return references;
    }

    /* volatile: the count other threads take and drop while this one
     * releases (the base reads it again after the decrement) */
    volatile long references; /* +0x8 */
    u8 unknown10[0x100a0 - 0x10];
    /* +0x100a0: incremented atomically (`lock inc qword`) after each entry
     * FUN_0131e770 hands to FUN_0131e2d0 */
    long unknown100a0;
    u8 unknown100a8[0x8];
    long
        unknown100b0; /* +0x100b0: incremented as +0x100a0 is, after each entry FUN_013224a0 hands to +0x100e8 */
    Target0131e2d0 *unknown100b8; /* +0x100b8: FUN_0131e2d0's first argument (FUN_0131e770) */
    u8 unknown100c0[0x100e8 - 0x100c0];
    Target0131e2d0 *unknown100e8; /* +0x100e8: FUN_0131e2d0's first argument (FUN_013224a0) */
    u8 unknown100f0[0x10238 - 0x100f0];
    Member05adaaa8_10238 *unknown10238; /* +0x10238: passed to FUN_01305ce0 by FUN_01499360 */
};

extern Object05adaaa8 *D_5adaaa8;

#endif
