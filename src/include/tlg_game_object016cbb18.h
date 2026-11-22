/* src/include/tlg_game_object016cbb18.h: the class whose vtable is at
 * 0x16cbb18 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CBB18_H
#define TLG_GAME_OBJECT016CBB18_H

#include "tlg_game_node.h"
#include "tlg_game_object016cbae0.h"

/* derived names: the class whose vtable is at 0x16cbb18
 * (config/vtables.derived.base.txt, stored by FUN_007ad420 FUN_0136e4e0
 * FUN_0136e630), derived from Object016cbae0. 0xa0 bytes (`mov edi,
 * 0xa0` before operator new in the creator). Its own fields are traced
 * where its creator FUN_007ad420 sets them and its destructor FUN_0136e4e0
 * tears them down. The destructor is implicit
 * (see the class). */
class Object016cbb18 : public Object016cbae0 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the name at +0x9c: the 16
     * bytes from +0x90 cleared in one store with the base's two names and int
     * (a run of zero stores made one memset); every store of the base's
     * constructor comes before the vptr store */
    Object016cbb18(const Name &name) : Object016cbae0(name) {}

    /* no destructor is declared: the complete one FUN_0136e4e0 and the deleting
     * FUN_0136e630 sit in the stretch of inline functions (from 0x1340000),
     * away from the creator, so the class has no key function and the unit
     * that constructs it (leaf_007ad420.cpp) emits the vtable with both. An
     * implicit destructor carries the inline hint: the deleting one holds
     * the complete one's body, as the base's does, where a destructor
     * defined in a unit of its own left a call. */

  private:
    Name name9c; /* +0x9c: empty from the constructor, released by the destructor */
};

#endif
