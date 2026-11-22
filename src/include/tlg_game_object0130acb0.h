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
    /* leaf_0130acb0.cpp: the private data handed back, then JsUnknown's */
    virtual ~Object0130acb0();

  private:
    u8 unknown10[0x10];
    /* +0x20: the object's chain of the device's private data, linked
     * through their next pointers */
    PrivateData01306250 *privateData20;
    u8 unknown28[0x4];

  public:
    /* +0x2c: the device context's stamp at +0x47ac, written into a buffer
     * by its slot 16 (0x1319760) */
    u32 unknown2c;
};

#endif
