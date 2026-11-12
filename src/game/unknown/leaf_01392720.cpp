/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object0134f620.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16b53f8 (config/vtables.derived.base.txt; stored also by FUN_00b1f8c0):
 * it stores the vtable, runs 0x134f620, the destructor of its member at
 * +0x58 (which frees the pointers in the array at +0x0 of that member counted
 * by the int at +0x8), written as a free function on that record, and runs
 * its base's destructor FUN_00ca38f0 as a tail call. FUN_01392750, slot 1, is
 * the deleting one. FUN_00ca38f0 stores its own class's vtable (0x16b8d40,
 * unnamed) first: the base destructor, its row named for it (D15). The
 * destructor is the class's key function, so this file
 * emits the vtable. */

class Object00ca38f0 /* derived name */
{
  public:
    virtual ~Object00ca38f0();
};

class Object01392720 : public Object00ca38f0 /* derived name */
{
  public:
    virtual ~Object01392720();

  private:
    u8 unknown8[0x50];
    Object0134f620 unknown58; /* +0x58 */
};

Object01392720::~Object01392720() {}
