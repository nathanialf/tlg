/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0139b6b0.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16d7820 (config/vtables.derived.base.txt), slot 0, its deleting one
 * FUN_01481620 at slot 1, the vtable also stored by FUN_01258730 and
 * FUN_0125e010: it stores the vtable and tail-calls 0x13e9a00, the
 * destructor of its member at +0x8 (which first tests the int at +0x8 of that
 * member), an array of tlg_game_object0139b6b0.h, as the derived complete
 * destructors are. The destructor is the class's key function, so this file
 * emits the vtable. */
class Object0147fb20 /* derived name */
{
  public:
    virtual ~Object0147fb20();

  private:
    Object013e9a00 unknown8; /* +0x8 */
};

Object0147fb20::~Object0147fb20() {}
