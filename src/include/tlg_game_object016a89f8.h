/* src/include/tlg_game_object016a89f8.h: the class whose vtable is at 0x16a89f8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A89F8_H
#define TLG_GAME_OBJECT016A89F8_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object016c7948.h"

/* derived names: the class whose vtable is at 0x16a89f8
 * (config/vtables.derived.base.txt, stored by its constructor FUN_0035b770,
 * its row named for it, D15, after Object016c7948's vtable), derived from
 * Object016c7948. 0x2a0 bytes (`mov edi, 0x2a0` before operator new in its
 * creator FUN_0035b380). Its complete destructor (leaf_0134de30.cpp) releases
 * the Name at +0x298, then tail-calls the base's (0x8227e0). The other
 * members are not traced. */
class Object016a89f8 : public Object016c7948 /* derived name */
{
  public:
    Object016a89f8(const Name &name); /* FUN_0035b770 */
    virtual ~Object016a89f8();

  private:
    Name name298; /* +0x298 */
};

#endif
