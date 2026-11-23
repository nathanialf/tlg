/* src/include/tlg_game_jsunknown.h: the render's reference-counted root
 * class (render/ps4/JsUnknown.cpp, as its destructor's report names the
 * file). The class name is its destructor's report ("~JsUnknown", 0x15cec51)
 * and the field's name the report's condition; its vtable is the row
 * _ZTV9JsUnknown (0x16c3c58, config/vtables.derived.base.txt). */
#ifndef TLG_GAME_JSUNKNOWN_H
#define TLG_GAME_JSUNKNOWN_H

#include "tlg_types.h"

/* The class's source file, as the reports name it (0x15cec18). */
#define JS_UNKNOWN_CPP /* derived name */                                                          \
    "D:\\trico\\engine\\anzu\\engine_src\\render\\ps4\\JsUnknown.cpp"

/* derived name: the counter the objects' serials are taken from */
extern long D_179f2a8;

class JsUnknown
{
  public:
    /* derived name: the constructor every Create* inlines (0x131f450): the
     * count 1, the kind, then the serial from the counter 0x179f2a8, taken
     * atomically (`lock xadd`) */
    explicit JsUnknown(u32 kind) : m_referenceCount(1)
    {
        m_kind = kind;
        m_serial = __sync_fetch_and_add(&D_179f2a8, 1);
    }

    /* slots 0 and 1 (0x13246a0, 0x1324770) */
    virtual ~JsUnknown();
    /* slot 2 (0x1324850): the object deleted through its deleting destructor */
    virtual void Destroy(); /* derived name */

    /* derived name: a reference taken (`lock inc`, CreateRasterizerState's
     * default state) */
    void AddRef()
    {
        __sync_fetch_and_add(&m_referenceCount, 1);
    }

    /* derived name: a reference dropped (JsView's destructor, 0x1326bd6): the
     * count taken down atomically, slot 2 called for the last one, the count
     * returned read again after the decrement (as the device's release).
     * Relaxed: where the object's type is known (0x130a930) the vptr stored
     * before the decrement is forwarded past it and slot 2 called directly
     * (the only direct call of 0x130af40 in the base) */
    long Release()
    {
        if (__atomic_fetch_sub(&m_referenceCount, 1, __ATOMIC_RELAXED) == 1)
            Destroy();
        return m_referenceCount;
    }

  protected:
    /* +0x8: checked to be 0 by the destructor; volatile: the count other
     * threads take and drop while this one releases (read again after the
     * decrement) */
    volatile long m_referenceCount;
    long m_serial; /* +0x10 (derived name) */
    u32 m_kind;    /* +0x18: 7 for a rasterizer state (derived name) */
};

#endif
