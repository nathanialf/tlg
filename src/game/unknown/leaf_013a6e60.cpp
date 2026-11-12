/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_namelist.h"

/* derived names: the class whose vtable is at 0x16d14a0
 * (config/vtables.derived.base.txt, stored by FUN_00c5a380): a list of 24
 * named values from +0x14, its count at +0x10, held in a
 * NamedValueList013883d0; its slot 2 is
 * FUN_013883d0's append. The other fields are not traced. */
class Object016d14a0 /* derived name */
{
  public:
    virtual ~Object016d14a0();

  private:
    u8 unknown8[8];
    NamedValueList013883d0<24> list; /* +0x10 */
};

/* derived name: the complete destructor: the body is empty and the names
 * are released from the last entry down. FUN_013a6ee0, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016d14a0::~Object016d14a0() {}
