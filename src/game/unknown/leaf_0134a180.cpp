/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16c7290
 * (config/vtables.derived.base.txt), with an array of Names at +0x10.
 * Its complete destructor FUN_0134a180 is the array's destructor inlined (each
 * name released first to last, then the block); FUN_0134a250, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. The other members are not traced. */
class Object016c7290 /* derived name */
{
  public:
    virtual ~Object016c7290();

  private:
    u8 unknown8[0x8];
    Array05943280<Name> names10; /* +0x10 */
};

Object016c7290::~Object016c7290() {}
