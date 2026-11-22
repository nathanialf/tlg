/* src/include/tlg_game_object016cbdf0.h: the class whose vtable is at
 * 0x16cbdf0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CBDF0_H
#define TLG_GAME_OBJECT016CBDF0_H

#include "tlg_game_name.h"
#include "tlg_game_object016cbd80.h"

/* derived names: the class whose vtable is at 0x16cbdf0
 * (config/vtables.derived.base.txt, stored by FUN_007ae910 FUN_0136cbe0 FUN_0136cd30), derived from Object016cbd80 (tlg_game_object016cbd80.h; itself derived from
 * Object016b9108): every slot from 2 is the base's. Its own fields
 * from +0x88 are traced only where its destructor FUN_0136cbe0 tears them down
 * (the Name at +0x88); the rest are not traced. */
class Object016cbdf0 : public Object016cbd80 /* derived name */
{
  public:
    /* inlined in the creator FUN_007ae910: the base's constructor, then the vptr
     * and the empty name at +0x88 */
    Object016cbdf0(const Name &name) : Object016cbd80(name) {}

    /* no destructor is declared: the complete one FUN_0136cbe0 and the deleting
     * FUN_0136cd30 sit in the stretch of inline functions (from 0x1340000),
     * away from the creator, so the class has no key function and the unit
     * that constructs it (leaf_007ae910.cpp) emits the vtable with both. An
     * implicit destructor carries the inline hint: the deleting one holds
     * the complete one's body, as the base's does, where a destructor
     * defined in a unit of its own left a call. */

  private:
    Name name88; /* +0x88: released by the destructor (`mov eax, [rbx+0x88]; shl 5`) */
};

#endif
