/* src/include/tlg_game_object05adaaa8.h: the render's device, the object the
 * pointer at 0x5adaaa8 holds (render/ps4/JsDevice.cpp and JsDevice.h). The
 * class name is its inline AddDelayDeleteObject's report
 * ("m_deleteObjectCount < JsDevice::kDeleteObjectMax", 0x15cc886, at
 * 0x130b0ef, over the object 0x5adaaa8 points at); the names the reports
 * spell are facts, the rest derived, and only the fields the matched
 * functions read are typed, each with the function that shows it. */
#ifndef TLG_GAME_OBJECT05ADAAA8_H
#define TLG_GAME_OBJECT05ADAAA8_H

#include "tlg_types.h"

/* The render library's utilities as JsDevice.h includes them (0x15cefab),
 * unless the including unit gives its own path first. */
#ifndef RENDER_UTIL_DIR
#define RENDER_UTIL_DIR /* derived name */ "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4/util/"
#endif

/* The device's header, as AddDelayDeleteObject's report names it
 * (0x15cc8b7). */
#define JS_DEVICE_H /* derived name */ "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4/JsDevice.h"

#include "tlg_game_assert.h"
#include "tlg_game_jsvolatilememory.h"
#include "tlg_game_render_mutex.h"
#include "tlg_game_render_misc.h"

struct Target0131e2d0; /* derived name */
class JsUnknown;       /* tlg_game_jsunknown.h */
class Object0130acb0;  /* tlg_game_object0130acb0.h */
class Object016c3b40;  /* tlg_game_object01499f30.h */
struct QueryDesc01499f30;
class Object016d7fd0; /* tlg_game_jsrasterizerstate.h */
struct JsRasterizerDesc;

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

class JsDevice
{
  public:
    virtual void slot0();   /* derived name; not traced */
    virtual void slot1();   /* derived name; not traced */
    virtual void destroy(); /* derived name; slot 2 (FUN_013224a0) */

    /* leaf_01306470.cpp: the label (6 for a query's block, 0x130ab59; 5 from
     * 0x13255c9) is not read */
    void *AllocateOnionMemory(u32 size, u32 alignment, u32 label);
    void DeallocatePrivateData(PrivateData01306250 *ptr); /* leaf_01306250.cpp */
    /* leaf_0131f450.cpp */
    void CreateRasterizerState(const JsRasterizerDesc *pRasterizerDesc,
                               Object016d7fd0 **ppRasterizerState);
    /* leaf_0130a930.cpp: 0, or -2 for no description or an unknown kind */
    int CreateQuery(const QueryDesc01499f30 *pDesc, Object016c3b40 **ppQuery); /* derived name */

    /* the objects whose last reference went, deleted later (0x130af40) */
    static const int kDeleteObjectMax = 0x4000;

    /* JsDevice.h:294 (its report): the object's delay set, the object
     * added once, the report when the list is full; defined after
     * Object0130acb0 (tlg_game_object0130acb0.h) */
    inline void AddDelayDeleteObject(Object0130acb0 *object);

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
    u8 unknown10[0x28 - 0x10];
    /* +0x28 and +0x30: the start and end of an array of objects, each
     * appended by its constructor (FUN_0131e9d0) and erased by its destructor
     * (FUN_0131f080), the slot cleared first, the rest moved down with
     * memmove; +0x48 and +0x50 another (FUN_01326700) */
    void **objects28;    /* derived name */
    void **objects28End; /* derived name */
    u8 unknown38[0x48 - 0x38];
    void **objects48;    /* derived name */
    void **objects48End; /* derived name */
    u8 unknown58[0x88 - 0x58];
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
    /* +0x10240: the frame an object's stamp is compared with (0x130b0a7) */
    s64 frame;                                    /* derived name */
    u32 m_deleteObjectCount;                      /* +0x10248 */
    JsUnknown *m_deleteObjects[kDeleteObjectMax]; /* derived name; +0x10250 */
    u8 unknown30250[0x30278 - 0x30250];
    /* +0x30278: the state CreateRasterizerState hands out for no
     * description, a reference taken */
    Object016d7fd0 *defaultRasterizerState; /* derived name */
    u8 unknown30280[0x302b8 - 0x30280];
    /* +0x302b8: held while queries are made and objects handed back
     * (0x130a930, 0x130af40) */
    Mutex m_mutex; /* derived name */
};

extern JsDevice *D_5adaaa8;

#endif
