/* src/include/tlg_game_object0130acb0.h: the class over JsUnknown whose
 * complete destructor is 0x130acb0 (its row _ZN14Object0130acb0D1Ev, D15;
 * JsUnknown.cpp, config/homes.base.txt). Its vtable is the row
 * _ZTV14Object0130acb0 (0x16c3990, config/vtables.derived.base.txt): the
 * destructor stores it, then JsUnknown's with ~JsUnknown's report inlined.
 * The destructors over it run it as a tail call. Every name here is
 * derived; its members are not traced. */
#ifndef TLG_GAME_OBJECT0130ACB0_H
#define TLG_GAME_OBJECT0130ACB0_H

#include "tlg_types.h"

#include "tlg_game_jsunknown.h"

class Object0130acb0 : public JsUnknown /* derived name */
{
  public:
    virtual ~Object0130acb0();
};

#endif
