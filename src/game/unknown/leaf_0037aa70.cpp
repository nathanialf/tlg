/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0134f620.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16a8d88 (config/vtables.derived.base.txt, stored by this destructor
 * alone): it stores the vtable and tail-calls 0x134f620, the destructor
 * of its member at +0x10 (which frees the pointers in the array at +0x0 of
 * that member counted by the int at +0x8), written as a free function on
 * that record, as the derived complete destructors are. The destructor is
 * the class's key function, so this file emits the vtable. */

class Object0037aa70 /* derived name */
{
  public:
    virtual ~Object0037aa70();

  private:
    u8 unknown8[8];
    Object0134f620 unknown10; /* +0x10 */
};

Object0037aa70::~Object0037aa70() {}
