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

  private:
    u8 unknowne8[0x100];
    Name name1e8; /* +0x1e8 */
};

Object016ac8c8::~Object016ac8c8() {}
