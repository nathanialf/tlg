/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object01387dd0.h"

/* derived names: the class whose vtable is at 0x16b19c8
 * (config/vtables.derived.base.txt, stored by its constructor FUN_001bd010
 * and its destructors), with no base class: a locked array of Object01387dd0
 * at +0x10 (its lock word at +0x24, taken by FUN_009f57c0) and a record at
 * +0x28; the rest is not traced */
class Object016b19c8 /* derived name */
{
  public:
    virtual ~Object016b19c8();

  private:
    u8 unknown8[0x8];
    Array01343a80<Object01387dd0> array10; /* +0x10 */
    Object0134f620 record28;               /* +0x28 */

    friend void FUN_009f57c0(Object016b19c8 *self);
};

/* derived name: not traced; takes the array's lock first (0x9f57e9) */
void FUN_009f57c0(Object016b19c8 *self);

/* derived names: the complete destructor: FUN_009f57c0 first, then the
 * record at +0x28 and the array at +0x10 destroyed (each element through
 * 0x1387dd0, then the block given back). FUN_009f5960, slot 1, is the
 * deleting one; the base holds this body inlined in it where the build calls
 * it (three storers of the vtable: the inline-cost margin, not claimed). The
 * destructor is the class's key function, so this file emits the vtable. */
Object016b19c8::~Object016b19c8()
{
    FUN_009f57c0(this);
}
