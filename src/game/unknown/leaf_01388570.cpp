/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_namelist.h"

/* derived names: the class whose vtable is at 0x16cdff0
 * (config/vtables.derived.base.txt, stored by FUN_00a01a80): a list of 1024
 * named values from +0x14, its count at +0x10, held in a
 * NamedValueList013883d0; its slot 2 is
 * FUN_013883d0's append. The other fields are not traced. */
class Object016cdff0 /* derived name */
{
  public:
    virtual ~Object016cdff0();

  private:
    u8 unknown8[8];
    NamedValueList013883d0<1024> list; /* +0x10 */
};

/* derived name: the complete destructor: the body is empty and the names
 * are released from the last entry down. FUN_013885f0, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016cdff0::~Object016cdff0() {}
