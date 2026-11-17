/* src/include/tlg_game_object016b0468.h: the class whose vtable is at 0x16b0468
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B0468_H
#define TLG_GAME_OBJECT016B0468_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b0468
 * (config/vtables.derived.base.txt, stored by its creator FUN_008edda0, where
 * its constructor is inlined, and by its complete destructor 0x8edf10, not
 * written), derived from Object01343880. 0x60 bytes (`mov edi, 0x60` before
 * operator new in the creator). Its fields are traced only where the creator
 * sets them. */
class Object016b0468 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: Object01343880's, the vptr, then zero from
     * +0x34 to the end (two overlapping 32-byte stores) */
    Object016b0468(const Name &name) : Object01343880(name), unknown34() {}

    virtual ~Object016b0468();

  private:
    int unknown34[0xb]; /* +0x34: zero from the constructor; not traced */
};

#endif
