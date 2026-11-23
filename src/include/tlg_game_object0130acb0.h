/* src/include/tlg_game_object0130acb0.h: the class over JsUnknown whose
 * complete destructor is 0x130acb0 (its row _ZN14Object0130acb0D1Ev, D15;
 * JsUnknown.cpp, config/homes.base.txt). Its vtable is the row
 * _ZTV14Object0130acb0 (0x16c3990, config/vtables.derived.base.txt): the
 * destructor stores it, then JsUnknown's with ~JsUnknown's report inlined.
 * The destructors over it run it as a tail call. Every name here is
 * derived. The classes over it start their members at +0x30. */
#ifndef TLG_GAME_OBJECT0130ACB0_H
#define TLG_GAME_OBJECT0130ACB0_H

#include "tlg_types.h"

#include "tlg_game_jsunknown.h"
#include "tlg_game_object05adaaa8.h"

class Object0130acb0 : public JsUnknown /* derived name */
{
  public:
    /* derived name: the constructor every Create* inlines (0x131f450): no
     * private data, +0x28 and +0x2c 0 and -1, the device's count at +0x10090
     * taken up */
    explicit Object0130acb0(u32 kind) : JsUnknown(kind)
    {
        privateData20 = nullptr;
        unknown28 = 0;
        unknown2c = -1;
        __sync_fetch_and_add(&D_5adaaa8->unknown10090, 1);
    }

    /* leaf_0130acb0.cpp: the private data handed back, then JsUnknown's */
    virtual ~Object0130acb0();

  private:
    /* +0x20: the object's chain of the device's private data, linked
     * through their next pointers */
    PrivateData01306250 *privateData20;
    u32 unknown28; /* +0x28 */

  public:
    /* +0x2c: the device context's stamp at +0x47ac, written into a buffer
     * by its slot 16 (0x1319760) */
    u32 unknown2c;
};

#endif
