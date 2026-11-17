/* src/include/tlg_game_object016adc50.h: the class whose vtable is at 0x16adc50
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ADC50_H
#define TLG_GAME_OBJECT016ADC50_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16adc50
 * (config/vtables.derived.base.txt, stored by its creator FUN_007a0840, where
 * its constructor is inlined after Object00774560's, 0x774370, called out of
 * line), derived from Object00774560. 0x100 bytes (`mov edi, 0x100`
 * before operator new in the creator). Its fields are traced only where the
 * creator sets them; its destructor is not written. */
class Object016adc50 : public Object00774560 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, then the body: 0.2 at the base's +0x7c */
    Object016adc50(const Name &name) : Object00774560(name)
    {
        unknown7c = 0.2f;
    }

    virtual ~Object016adc50();
};

#endif
