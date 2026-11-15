/* src/include/tlg_game_object016cbd10.h: the class whose vtable is at
 * 0x16cbd10 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CBD10_H
#define TLG_GAME_OBJECT016CBD10_H

#include "tlg_game_name.h"
#include "tlg_game_object016cbca0.h"

/* derived names: the class whose vtable is at 0x16cbd10
 * (config/vtables.derived.base.txt, stored by FUN_007ae280 FUN_0136d4c0 FUN_0136d610), derived from Object016cbca0 (tlg_game_object016cbca0.h; itself derived from
 * Object016b9108): every slot from 2 is the base's. Its own fields
 * from +0x88 are traced only where its destructor FUN_0136d4c0 tears them down
 * (the Name at +0x88); the rest are not traced. */
class Object016cbd10 : public Object016cbca0 /* derived name */
{
  public:
    /* inlined in the creator FUN_007ae280: the base's constructor, then the vptr
     * and the empty name at +0x88 */
    Object016cbd10(const Name &name) : Object016cbca0(name) {}

    virtual ~Object016cbd10();

  private:
    Name name88; /* +0x88: released by the destructor (`mov eax, [rbx+0x88]; shl 5`) */
};

#endif
