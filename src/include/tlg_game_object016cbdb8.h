/* src/include/tlg_game_object016cbdb8.h: the class whose vtable is at
 * 0x16cbdb8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CBDB8_H
#define TLG_GAME_OBJECT016CBDB8_H

#include "tlg_game_name.h"
#include "tlg_game_object016cbd80.h"

/* derived names: the class whose vtable is at 0x16cbdb8
 * (config/vtables.derived.base.txt, stored by FUN_007ae760 FUN_0136ce80 FUN_0136cfd0), derived from Object016cbd80 (tlg_game_object016cbd80.h; itself derived from
 * Object016b9108): every slot from 2 is the base's. Its own fields
 * from +0x88 are traced only where its destructor FUN_0136ce80 tears them down
 * (the Name at +0x88); the rest are not traced. */
class Object016cbdb8 : public Object016cbd80 /* derived name */
{
  public:
    /* inlined in the creator FUN_007ae760: the base's constructor, then the vptr
     * and the empty name at +0x88 */
    Object016cbdb8(const Name &name) : Object016cbd80(name) {}

    virtual ~Object016cbdb8();

  private:
    Name name88; /* +0x88: released by the destructor (`mov eax, [rbx+0x88]; shl 5`) */
};

#endif
