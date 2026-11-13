/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_object00c55550.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16d16a0 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00ca2720): it stores the vtable, releases its Name at +0x238, then
 * tail-calls its base's destructor (0xc55550). FUN_013abe70, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. The other members are not traced. */
class Object016d16a0 : public Object00c55550 /* derived name */
{
  public:
    virtual ~Object016d16a0();

  private:
    u8 unknown8[0x230];
    Name name238; /* +0x238 */
};

Object016d16a0::~Object016d16a0() {}
