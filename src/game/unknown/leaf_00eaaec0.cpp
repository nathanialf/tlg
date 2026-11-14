/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_referenced.h"

/* derived names: the class whose vtable is at 0x16be6b8
 * (config/vtables.derived.base.txt; stored by its constructor FUN_00eaaa30):
 * its complete destructor 0xeaaec0 stores the vtable and releases the object
 * at +0x10; FUN_00eaaf10, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. The other members are
 * not traced. */
class Object00eaaec0 /* derived name */
{
  public:
    virtual ~Object00eaaec0();

  private:
    u8 unknown8[0x8];
    Referenced00eaaec0 *unknown10; /* +0x10 */
};

Object00eaaec0::~Object00eaaec0()
{
    unknown10->removeReference();
}
