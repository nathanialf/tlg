/* src/include/tlg_game_object016aca58.h: the class whose vtable is at 0x16aca58
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ACA58_H
#define TLG_GAME_OBJECT016ACA58_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_object00774560.h"

/* derived names: the class whose vtable is at 0x16aca58
 * (config/vtables.derived.base.txt, stored by its creator FUN_00765490, where
 * its constructor is inlined after Object00774560's, 0x774370, called out of
 * line), derived from Object00774560. 0x100 bytes (`mov edi, 0x100`
 * before operator new in the creator). Its fields are traced only where the
 * creator sets them; its destructor is not written. */
class Object016aca58 : public Object00774560 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, then nothing of its own */
    Object016aca58(const Name &name) : Object00774560(name) {}

    virtual ~Object016aca58();
};

#endif
