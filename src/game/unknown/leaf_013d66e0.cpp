/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_object013d6840.h"

/* derived names: the class of the vtable at 0x16d3b98
 * (config/vtables.derived.base.txt; made by FUN_013d31a0): an owned block at
 * +0x18 and an Object013d6840 at +0x30 (its vtable 0x16d3b70 stored at
 * 0x13d66fa, its block at +0x48). Its complete destructor 0x13d66e0 runs the
 * member's destructor, inlined from leaf_013d6840.cpp, then releases the
 * block at +0x18, and calls no base; the deleting one 0x13d6790 is the
 * compiler's. The other members are not traced. */
class Object016d3b98 /* derived name */
{
  public:
    virtual ~Object016d3b98();

  private:
    u8 unknown8[0x10];
    OwnedBlock05943280 unknown18; /* +0x18 */
    u8 unknown20[0x10];
    Object013d6840 unknown30; /* +0x30 */
};

// NONMATCHING: the complete destructor 0x13d66e0 is equal in the whole module only (the member's
// destructor inlined from leaf_013d6840.cpp); the deleting one 0x13d6790 calls it there where the
// base inlines it (an inline-cost margin); the single-file module keeps the member's call in both
Object016d3b98::~Object016d3b98() {}
