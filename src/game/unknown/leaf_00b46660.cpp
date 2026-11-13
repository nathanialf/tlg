/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0134f620.h"

/* derived names: the complete destructor of a class whose vtable is at
 * 0x16b6160 (config/vtables.derived.base.txt; stored by FUN_001bd010 FUN_00b46660 FUN_00b467e0),
 * slot 0 of it: it stores the vtable, calls the class's FUN_00b466a0 on the
 * object, then runs the destructors of its members in reverse order, FUN_0139b6b0 on the one at +0x28 and 0x134f620 on the one at +0x10,
 * each written as a free function on its record. FUN_00b467e0, slot 1, is the deleting one. The
 * destructor is the class's key function, so this file emits the vtable. */

struct Object0139b6b0 /* derived name */
{
    void *unknown0; /* +0x0: the 16-byte entries it releases */
    int unknown8;   /* +0x8: their count */
};

void FUN_0139b6b0(Object0139b6b0 *self); /* derived name */

class Object00b46660 /* derived name */
{
  public:
    virtual ~Object00b46660();
    void FUN_00b466a0(); /* derived name */

  private:
    u8 unknown8[0x8];
    Object0134f620 unknown10; /* +0x10 */
    Object0139b6b0 unknown28; /* +0x28 */
};

Object00b46660::~Object00b46660()
{
    FUN_00b466a0();
    FUN_0139b6b0(&unknown28);
}
