/* src/include/tlg_game_object05adaaa8.h: the object the pointer at 0x5adaaa8
 * holds. derived names throughout; only the fields the matched functions
 * read are typed, each with the function that shows it. */
#ifndef TLG_GAME_OBJECT05ADAAA8_H
#define TLG_GAME_OBJECT05ADAAA8_H

#include "tlg_types.h"

#include "tlg_game_jsvolatilememory.h"
#include "tlg_game_render_misc.h"

struct Target0131e2d0; /* derived name */

/* derived name: an entry of the device's private data (16 bytes: CreateDevice
 * chains them at that stride), the next free one at +0x4. An owner's
 * destructor (0x130acb0) walks its own chain of them through next, freeing
 * the block at +0x8 of each whose half-word at +0x2 is set. */
struct PrivateData01306250 {
    u16 unknown0;
    u16 unknown2;                            /* +0x2: set when the block at +0x8 is the entry's */
    OffsetPointer<PrivateData01306250> next; /* derived name; +0x4 */
    void *unknown8;                          /* +0x8: freed with free (0x130ad1f) */
};

class Object05adaaa8 /* derived name */
{
  public:
    virtual void slot0();   /* derived name; not traced */
    virtual void slot1();   /* derived name; not traced */
    virtual void destroy(); /* derived name; slot 2 (FUN_013224a0) */

    void *AllocateOnionMemory(u32 size, u32 alignment);   /* leaf_01306470.cpp */
    void DeallocatePrivateData(PrivateData01306250 *ptr); /* leaf_01306250.cpp */

    /* the private data's entries, as DeallocatePrivateData's check names
     * the count (0x10000 bytes of 16-byte entries from +0x88) */
    static const int kPrivateDataCountMax = 0x1000;

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
    u8 unknown10[0x88 - 0x10];
    PrivateData01306250 m_privateData[kPrivateDataCountMax]; /* +0x88 */
    PrivateData01306250 *m_freePrivateData;                  /* derived name; +0x10088 */
    /* +0x10090: decremented atomically (`lock dec qword`) by the destructor
     * 0x130acb0 after it hands back its private data */
    long unknown10090;
    u8 unknown10098[0x100a0 - 0x10098];
    /* +0x100a0: incremented atomically (`lock inc qword`) after each entry
     * FUN_0131e770 hands to FUN_0131e2d0 */
    long unknown100a0;
    /* +0x100a8: incremented atomically (`lock inc qword`) after each block
     * AllocateOnionMemory takes (0x13064a1) */
    long onionAllocations; /* derived name */
    long
        unknown100b0; /* +0x100b0: incremented as +0x100a0 is, after each entry FUN_013224a0 hands to +0x100e8 */
    Target0131e2d0 *unknown100b8; /* +0x100b8: FUN_0131e2d0's first argument (FUN_0131e770) */
    u8 unknown100c0[0x100e8 - 0x100c0];
    Target0131e2d0 *unknown100e8; /* +0x100e8: FUN_0131e2d0's first argument (FUN_013224a0) */
    u8 unknown100f0[0x10238 - 0x100f0];
    /* +0x10238: the volatile memory the contexts allocate from
     * (JsDeviceContext's slots 21 and 27) */
    JsVolatileMemory *volatileMemory; /* derived name */
};

extern Object05adaaa8 *D_5adaaa8;

#endif
