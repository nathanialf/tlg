/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16b4d30 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00b15960): it deletes the record it owns at +0x30 (a type with a
 * trivial destructor: operator delete alone) and clears the pointer, then
 * releases its Name at +0xc. FUN_00b1a4b0, slot 1, is the deleting one. The
 * class has no base. The destructor is the class's key function, so this file
 * emits the vtable. The other members are not traced. */
struct Record00b1a440 /* derived name */
{
    u8 unknown0[0x8]; /* not traced */
};

class Object016b4d30 /* derived name */
{
  public:
    virtual ~Object016b4d30();

  private:
    u8 unknown8[0x4];
    Name namec; /* +0xc */
    u8 unknown10[0x20];
    Record00b1a440 *owned30; /* +0x30 */
};

Object016b4d30::~Object016b4d30()
{
    if (owned30 != 0) {
        delete owned30;
        owned30 = 0;
    }
}
