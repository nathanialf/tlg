/* src/include/tlg_game_object016cbb50.h: the class whose vtable is at
 * 0x16cbb50 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CBB50_H
#define TLG_GAME_OBJECT016CBB50_H

#include "tlg_game_name.h"
#include "tlg_game_object016cbae0.h"

/* derived names: the class whose vtable is at 0x16cbb50
 * (config/vtables.derived.base.txt, stored by FUN_007ad5e0 FUN_0136e240 FUN_0136e390), derived from Object016cbae0 (tlg_game_object016cbae0.h; itself derived from
 * Object016b9108): every slot from 2 is the base's. Its own fields
 * from +0x98 are traced only where its destructor FUN_0136e240 tears them down
 * (the Name at +0x9c); the rest are not traced. */
class Object016cbb50 : public Object016cbae0 /* derived name */
{
  public:
    /* inlined in the creator FUN_007ad5e0: Object016cbae0's constructor (its
     * fields before this class's vptr), the vptr, the empty name (one
     * 16-byte zero store with the base's names and int) */
    Object016cbb50(const Name &name) : Object016cbae0(name) {}

    /* no destructor is declared: the complete one FUN_0136e240 and the deleting
     * FUN_0136e390 sit in the stretch of inline functions (from 0x1340000),
     * away from the creator, so the class has no key function and the unit
     * that constructs it (leaf_007ad5e0.cpp) emits the vtable with both. An
     * implicit destructor carries the inline hint: the deleting one holds
     * the complete one's body, as the base's does, where a destructor
     * defined in a unit of its own left a call. */

  private:
    Name name9c; /* +0x9c: released by the destructor (`mov eax, [rbx+0x9c]; shl 5`) */
};

#endif
