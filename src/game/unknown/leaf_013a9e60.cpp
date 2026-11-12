/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"

/* derived names: the class whose destructor is 0xd30550 (its row named for
 * it, D15; leaf_013a9fb0.cpp) */
class Object00d30550 /* derived name */
{
  public:
    virtual ~Object00d30550();
};

/* derived names: the class of the vtable at 0x16d15b0
 * (config/vtables.derived.base.txt; made by FUN_00c688c0), derived from
 * Object00d30550: owned blocks at +0x70 and +0x88. Its complete destructor
 * 0x13a9e60 releases the block at +0x88, then the one at +0x70, then runs
 * the base's as a tail call; the deleting one 0x13a9f00 is the compiler's.
 * The other members are not traced. */
class Object016d15b0 : public Object00d30550 /* derived name */
{
  public:
    virtual ~Object016d15b0();

  private:
    u8 unknown8[0x68];
    OwnedBlock05943280 unknown70; /* +0x70 */
    u8 unknown78[0x10];
    OwnedBlock05943280 unknown88; /* +0x88 */
};

// NONMATCHING: the deleting destructor 0x13a9f00 calls this one (28 bytes) where the base inlines it
// (an inline-cost margin); this complete destructor is equal
Object016d15b0::~Object016d15b0() {}
