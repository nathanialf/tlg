/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aed28.h"
#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16b5d88 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00b42f60): it stores the vtable, releases its Name at +0x584, then
 * tail-calls its base's destructor (0x83df00). FUN_00b43120, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. The other members are not traced. */
class Object016b5d88 : public Object016aed28 /* derived name */
{
  public:
    virtual ~Object016b5d88();

  private:
    u8 unknown580[0x4];
    Name name584; /* +0x584 */
};

Object016b5d88::~Object016b5d88() {}
