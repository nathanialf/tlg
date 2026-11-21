/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_shared.h"

/* derived names: the class whose vtable is at 0x16bd3b0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00b981a0
 * and its complete destructor FUN_00df0f40; home ComputeInterface.cpp, as
 * leaf_00df2f80.cpp reads it): four shared objects held at +0x30, +0x60,
 * +0xc0 and +0x630. The destructor's body hands the object to
 * FUN_00df1030; then the references are dropped, last first. FUN_00df1930,
 * slot 1, is the deleting one. The destructor is the class's key function,
 * so this file emits the vtable. The other members are not traced. */
class Object016bd3b0 /* derived name */
{
  public:
    virtual ~Object016bd3b0();

    void FUN_00df1030(); /* derived name; not traced */

  private:
    u8 unknown8[0x28];
    SharedRef00901550<Shared00901550> shared30; /* +0x30 */
    u8 unknown38[0x28];
    SharedRef00901550<Shared00901550> shared60; /* +0x60 */
    u8 unknown68[0x58];
    SharedRef00901550<Shared00901550> sharedc0; /* +0xc0 */
    u8 unknownc8[0x568];
    SharedRef00901550<Shared00901550> shared630; /* +0x630 */
};

Object016bd3b0::~Object016bd3b0()
{
    FUN_00df1030();
}
