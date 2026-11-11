/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16b1ba0 (config/vtables.derived.base.txt; stored by FUN_001bd010 FUN_00a073a0 FUN_00a07510),
 * slot 0 of it: it stores the vtable, calls the class's FUN_00a073e0 on the
 * object, then runs the destructors of its members in reverse order, FUN_0134f620 on the one at +0x28 and FUN_0134f620 on the one at +0x10,
 * each written as a free function on its record. FUN_00a07510, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. */
struct Object0134f620 /* derived name */
{
    u8 unknown0[8];
    int unknown8; /* +0x8: tested first */
};

void FUN_0134f620(Object0134f620 *self); /* derived name */

class Object00a073a0 /* derived name */
{
  public:
    virtual ~Object00a073a0();
    void FUN_00a073e0(); /* derived name */

  private:
    u8 unknown8[0x8];
    Object0134f620 unknown10; /* +0x10 */
    u8 unknown1c[0xc];
    Object0134f620 unknown28; /* +0x28 */
};

Object00a073a0::~Object00a073a0()
{
    FUN_00a073e0();
    FUN_0134f620(&unknown28);
    FUN_0134f620(&unknown10);
}
