/* src/include/tlg_game_object016c7948.h: the class whose vtable is at 0x16c7948
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C7948_H
#define TLG_GAME_OBJECT016C7948_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16c7948
 * (config/vtables.derived.base.txt), derived from Object016b85e0: the
 * constructors of the classes derived from it (FUN_00344a60, FUN_0035b770,
 * FUN_00510130, FUN_00510fa0, FUN_006743e0) call that class's constructor
 * 0xc55320 and store this vtable next, its own constructor inlined; its
 * complete destructor 0x8227e0 (its row named for it, D15) stores it, releases
 * the members at +0x258 to +0x290 and tail-calls the base's destructor
 * 0xc55550. Its data ends at +0x298, where Object016a89f8 keeps a Name
 * (leaf_0134de30.cpp); the base's 16-byte rows (`vmovaps [rbx+0x70]` in
 * 0xc55320) align the class. The destructor is not written, so nothing here
 * emits the vtable; the fields are not traced. */
class Object016c7948 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016c7948();

  protected:
    u8 unknown8[0x68];
    Float4A unknown70; /* +0x70: the base's; not traced */
    u8 unknown80[0x218];
};

#endif
