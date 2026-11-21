/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d51e0.h"

/* derived names: the class whose vtable is at 0x16c0bc0
 * (config/vtables.derived.base.txt; made by FUN_01006780 after
 * Object016d51e0's constructor), derived from Object016d51e0 with a Name at
 * +0x70. Its complete destructor FUN_013eeff0 releases the Name, then runs
 * the base's destructor, inlined from leaf_013ef1a0.cpp; FUN_013ef0d0, slot
 * 1, is the deleting one. The destructor is the class's key function, so
 * this file emits the vtable. The other members are not traced. */
class Object016c0bc0 : public Object016d51e0 /* derived name */
{
  public:
    virtual ~Object016c0bc0();

  private:
    u8 unknown34[0x3c];
    Name unknown70; /* +0x70 */
};

// NONMATCHING: the base's destructor (FUN_013ef1a0, leaf_013ef1a0.cpp) is kept as a tail call where the base
// inlines it (its Name at +0x30 and its block): an inline-cost margin under the module
Object016c0bc0::~Object016c0bc0() {}
