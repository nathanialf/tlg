/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16b7128 (config/vtables.derived.base.txt; stored by the constructors
 * FUN_005330f0, FUN_00815930, FUN_0081e8d0 and FUN_00b91cc0 and by the
 * destructors FUN_00b89eb0 and FUN_00b89ed0): it stores the vtable, clears the
 * pointer at +0x20 and runs its base's destructor FUN_00bc3780 as a tail call.
 * FUN_00bc3780 stores its own class's vtable (0x16b7670, unnamed) after its
 * canary set-up and is tail-called the same way by the destructors
 * FUN_00bc3b10 and FUN_013c96e0 of two more classes: the base destructor, its
 * row named for it (D15). FUN_00b89ed0, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. */
class Object00bc3780 /* derived name */
{
  public:
    virtual ~Object00bc3780();
};

class Object00b89eb0 : public Object00bc3780 /* derived name */
{
  public:
    virtual ~Object00b89eb0();

  private:
    u8 unknown8[0x18];
    void *unknown20; /* +0x20 */
};

Object00b89eb0::~Object00b89eb0()
{
    unknown20 = 0;
}
