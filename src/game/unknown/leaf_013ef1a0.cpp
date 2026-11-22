/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d51e0.h"

/* derived name: the complete destructor (tlg_game_object016d51e0.h). The
 * destructor is the class's key function, so this file emits the vtable. */
Object016d51e0::~Object016d51e0() {}

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
    Name unknown70; /* +0x70 */
};

// NONMATCHING: the deleting destructor FUN_013ef0d0: the base inlines this complete destructor into it (205 bytes);
// the build calls it (the class of 0x134dd20: an inline-cost margin on the deleting destructor)
Object016c0bc0::~Object016c0bc0() {}
