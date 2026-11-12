/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16a8fe8
 * (config/vtables.derived.base.txt, stored by FUN_003e1b40): two names, at
 * +0x14 and +0x30. Its slot 2 is the library's FUN_000069a0, slot 3
 * FUN_003e3c10 (declared; not traced). The other fields are not traced. */
class Object016a8fe8 /* derived name */
{
  public:
    virtual ~Object016a8fe8();
    virtual void slot2(); /* derived name; FUN_000069a0 */
    virtual void slot3(); /* derived name; FUN_003e3c10 */

  private:
    u8 unknown8[0xc];
    Name name14; /* +0x14 */
    u8 unknown18[0x18];
    Name name30; /* +0x30 */
};

/* derived name: the complete destructor: the body is empty and the names
 * are released, +0x30 then +0x14. FUN_0134f3b0, slot 1, is the deleting
 * one. The destructor is the class's key function, so this file emits the
 * vtable. */
Object016a8fe8::~Object016a8fe8() {}
