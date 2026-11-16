/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00774560.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16ad3b8 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_0077bd10): it stores the vtable, releases its Name at +0xfc, then
 * tail-calls its base's destructor (0x774560). FUN_0077be50, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. The other members are not traced. */
class Object016ad3b8 : public Object00774560 /* derived name */
{
  public:
    virtual ~Object016ad3b8();
    virtual void slot14(Pose0077bac0 *pose); /* FUN_0077c5a0 */

  private:
    u8 unknowne8[0x14];
    Name namefc; /* +0xfc */
};

Object016ad3b8::~Object016ad3b8() {}

/* derived name: slot 14: the body at +0x68 turned by the pose's rotation (the
 * body read once for the product and its store) and moved by the pose's
 * position (the body read again); FUN_0077bac0's body */
void Object016ad3b8::slot14(Pose0077bac0 *pose)
{
    follow(pose);
}
