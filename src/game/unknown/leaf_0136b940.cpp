/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_namelist.h"

/* derived names: the class whose vtable is at 0x16cb8b0
 * (config/vtables.derived.base.txt, stored by FUN_0077c7f0): a list of 15
 * named values from +0x14, its count at +0x10, held in a
 * NamedValueList013883d0; its slot 2 is
 * FUN_013883d0's append. The other fields are not traced. */
class Object016cb8b0 /* derived name */
{
  public:
    virtual ~Object016cb8b0();

  private:
    u8 unknown8[8];
    NamedValueList013883d0<15> list; /* +0x10 */
};

/* derived name: the complete destructor: the body is empty and the names
 * are released from the last entry down. FUN_0136bba0, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016cb8b0::~Object016cb8b0() {}
