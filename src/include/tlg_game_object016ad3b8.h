/* src/include/tlg_game_object016ad3b8.h: the class whose vtable is at 0x16ad3b8
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AD3B8_H
#define TLG_GAME_OBJECT016AD3B8_H

#include "tlg_game_object00774560.h"
#include "tlg_game_name.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16ad3b8 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_0077bd10): it stores the vtable, releases its Name at +0xfc, then
 * tail-calls its base's destructor (0x774560). FUN_0077be50, slot 1, is the
 * deleting one. The destructor is the class's key function, so leaf_0077bdf0.cpp
 * emits the vtable. The other members are not traced. */
class Object016ad3b8 : public Object00774560 /* derived name */
{
  public:
    Object016ad3b8(const Name &name); /* 0x77bd10, its row named after it (D15) */
    virtual ~Object016ad3b8();
    virtual void slot14(Pose0077bac0 *pose); /* FUN_0077c5a0 */

  private:
    Name namefc; /* +0xfc */
};

#endif
