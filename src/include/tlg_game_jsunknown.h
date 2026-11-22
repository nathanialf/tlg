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

class JsUnknown
{
  public:
    /* slots 0 and 1 (0x13246a0, 0x1324770) */
    virtual ~JsUnknown();
    /* slot 2 (0x1324850): the object deleted through its deleting destructor */
    virtual void Destroy(); /* derived name */

    /* derived name: a reference dropped (JsView's destructor, 0x1326bd6): the
     * count taken down atomically, slot 2 called for the last one, the count
     * returned read again after the decrement (as the device's release) */
    long Release()
    {
        if (__sync_fetch_and_sub(&m_referenceCount, 1) == 1)
            Destroy();
        return m_referenceCount;
    }

  protected:
    /* +0x8: checked to be 0 by the destructor; volatile: the count other
     * threads take and drop while this one releases (read again after the
     * decrement) */
    volatile long m_referenceCount;
};

#endif
