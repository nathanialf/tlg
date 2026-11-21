/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object016c7948.h"

/* derived names: the class whose vtable is at 0x16ac180
 * (config/vtables.derived.base.txt), derived from Object016c7948: four Names (+0x2a0 to
 * +0x2ac).
 * Its complete destructor FUN_00674890 releases them in reverse order, then
 * tail-calls the base's destructor 0x8227e0; FUN_006749a0, slot 1, is the deleting
 * one. The destructor is the class's key function, so this file emits the
 * vtable. The other members are not traced. */
class Object016ac180 : public Object016c7948 /* derived name */
{
  public:
    virtual ~Object016ac180();

  private:
    u8 unknown298[0x8];
    Name name2a0; /* +0x2a0 */
    Name name2a4; /* +0x2a4 */
    Name name2a8; /* +0x2a8 */
    Name name2ac; /* +0x2ac */
};

Object016ac180::~Object016ac180() {}
