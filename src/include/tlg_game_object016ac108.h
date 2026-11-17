/* src/include/tlg_game_object016ac108.h: the class whose vtable is at 0x16ac108
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AC108_H
#define TLG_GAME_OBJECT016AC108_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object016aeab0.h"

/* derived names: the class whose vtable is at 0x16ac108
 * (config/vtables.derived.base.txt, stored by its creator FUN_00670560, where
 * its constructor is inlined), derived from Object016aeab0 (its constructor's stores
 * come first in the creator, the base's vptr store dead). 0x270 bytes
 * (`mov edi, 0x270` before operator new in the creator). Its fields are
 * traced only where the creator sets them; its destructor is not written. */
class Object016ac108 : public Object016aeab0 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, then 0 at +0x25c (the -1 at +0x258 is its base's, from the constructor with a value) */
    Object016ac108(const Name &name) : Object016aeab0(name, -1), unknown25c(0) {}

    virtual ~Object016ac108();

  private:
    int unknown25c; /* +0x25c: 0 from the constructor */
    u8 unknown260[0x10];
};

#endif
