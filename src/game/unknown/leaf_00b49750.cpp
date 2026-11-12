/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0134f620.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16b6288 (config/vtables.derived.base.txt; stored also by FUN_001bd010, which
 * stores the vtables 0x16b6110, 0x16b6188 and 0x16b6288 of three classes of
 * this shape): it stores the vtable and runs the destructors of its members
 * in reverse order, FUN_0139b6b0 on the one at +0x28 (which releases the
 * reference-counted pointers in the 16-byte entries of the array at +0x0
 * counted by the int at +0x8), then 0x134f620 on the one at +0x10 (which
 * frees the pointers in its array at +0x0 counted by the int at +0x8) as a
 * tail call, each written as a free function on its record. FUN_00b49780,
 * slot 1, is the deleting one. The destructor is the class's key function, so
 * this file emits the vtable. */
struct Object0139b6b0 /* derived name */
{
    void *unknown0; /* +0x0: the 16-byte entries it releases */
    int unknown8;   /* +0x8: their count */
};

void FUN_0139b6b0(Object0139b6b0 *self); /* derived name */

class Object00b49750 /* derived name */
{
  public:
    virtual ~Object00b49750();

  private:
    u8 unknown8[8];
    Object0134f620 unknown10; /* +0x10 */
    u8 unknown20[8];
    Object0139b6b0 unknown28; /* +0x28 */
};

Object00b49750::~Object00b49750()
{
    FUN_0139b6b0(&unknown28);
}
