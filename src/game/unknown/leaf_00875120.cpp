/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016c81c0.h"

/* derived names: the class whose vtable is at 0x16b4ce0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00b12590
 * and its destructor 0xb129d0, its row named for it, D15); the destructor
 * is not written here, its fields are not traced */
class Object016b4ce0 /* derived name */
{
  public:
    virtual ~Object016b4ce0();

  private:
    u8 unknown8[0xf8];
};

/* derived names: the class whose vtable is at 0x16af238
 * (config/vtables.derived.base.txt, stored by its creator FUN_00872a80 and
 * its destructors), over Object016c81c0 (the destructor tail-calls
 * 0xd687e0), holding an Object016b4ce0 at +0x98, the object the pointer at
 * 0x581e3a8 names while it lives (the script functions of 0x8753d0 and on
 * read it) */
class Object00875120 : public Object016c81c0 /* derived name */
{
  public:
    virtual ~Object00875120();

  private:
    Object016b4ce0 unknown98; /* +0x98 */
};

extern Object016b4ce0 *D_581e3a8;

/* derived names: the complete destructor: the pointer at 0x581e3a8
 * cleared, then the member at +0x98 and the base destroyed (0xb129d0, then
 * 0xd687e0 as a tail call). FUN_00875160, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. */
Object00875120::~Object00875120()
{
    D_581e3a8 = 0;
}
