/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_buffer00d650e0.h"
#include "tlg_game_object00d30550.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16baa48 (config/vtables.derived.base.txt; made by FUN_00d64f10): it
 * stores the vtable, passes the object to FUN_00d65170, destroys the buffer
 * at +0x50 and runs its base's destructor FUN_00d30550 as a tail call.
 * FUN_00d655d0, slot 1, is the deleting one; slot 2 is FUN_00cb66f0. The
 * destructor is the class's key function, so this file emits the vtable. */
class Object016baa48 : public Object00d30550 /* derived name */
{
  public:
    virtual ~Object016baa48();

  private:
    u8 unknown8[0x48];
    Buffer00d650e0 unknown50; /* +0x50 */
};

void FUN_00d65170(Object016baa48 *self); /* derived name */

Object016baa48::~Object016baa48()
{
    FUN_00d65170(this);
}
