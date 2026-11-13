/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object00c55550.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16a9e70 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_0047e4e0): it stores the vtable, releases its Name at +0x248, then
 * tail-calls its base's destructor (0xc55550). FUN_00490090, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. The other members are not traced. */
class Object016a9e70 : public Object00c55550 /* derived name */
{
  public:
    virtual ~Object016a9e70();

  private:
    u8 unknown8[0x240];
    Name name248; /* +0x248 */
};

Object016a9e70::~Object016a9e70() {}
