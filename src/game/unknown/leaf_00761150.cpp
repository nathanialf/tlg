/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00774560.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16ac8c8 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00760f90): it stores the vtable, releases its Name at +0x1e8, then
 * tail-calls its base's destructor (0x774560). FUN_007611b0, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. The other members are not traced. */
class Object016ac8c8 : public Object00774560 /* derived name */
{
  public:
    virtual ~Object016ac8c8();
    virtual void slot14(Pose0077bac0 *pose); /* FUN_00762b30 */

  private:
    u8 unknownfc[0x14];
    Vector0077bac0 unknown110; /* +0x110: scaled by +0x174 in slot 14 */
    u8 unknown11c[0x58];
    float unknown174; /* +0x174 */
    u8 unknown178[0x6c];
    int unknown1e4; /* +0x1e4: slot 14 scales +0x110 when it is 1 */
    Name name1e8;   /* +0x1e8 */
};

Object016ac8c8::~Object016ac8c8() {}

/* derived name: slot 14: the body put back home (Object00774560::goHome),
 * then, when the int at +0x1e4 is 1 and the body is held (+0x1330), the
 * vector at +0x110 scaled by the float at +0x174; the pose is not read */
void Object016ac8c8::slot14(Pose0077bac0 *)
{
    goHome();
    if (unknown1e4 == 1 && unknown68->unknown1330)
        unknown110 = unknown174 * unknown110;
}
