/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16c7020
 * (config/vtables.derived.base.txt, stored by FUN_001bd010 and 42 other
 * functions that build it inline): 32 names from +0x14. Its slots 2 and 3
 * are pure (zero in the vtable, relocated at load), 4 and 5 point at
 * 0x1af750 and 0x21a00. The other fields are not traced. */
class Object016c7020 /* derived name */
{
  public:
    virtual ~Object016c7020();

  private:
    u8 unknown8[0xc];
    Name names[32]; /* +0x14 */
};

/* derived name: the complete destructor: the body is empty and the names
 * are released from the last down. FUN_01343010, slot 1, is the deleting
 * one. The destructor is the class's key function, so this file emits the
 * vtable. */
Object016c7020::~Object016c7020() {}
