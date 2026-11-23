/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_object013d6840.h"

/* derived names: the class of the vtable at 0x16d3b98
 * (config/vtables.derived.base.txt; made by FUN_013d31a0): an array of 32-bit
 * values at +0x18 and an Object013d6840 at +0x30 (its vtable 0x16d3b70 stored
 * at 0x13d66fa, its values at +0x48). Its complete destructor 0x13d66e0 runs
 * the member's destructor, inlined from leaf_013d6840.cpp, then releases the
 * block of the values at +0x18, and calls no base; the deleting one 0x13d6790
 * is the compiler's. The other members are not traced. */
class Object016d3b98 /* derived name */
{
  public:
    virtual ~Object016d3b98();

    /* slot 2 (FUN_013d4910, also called directly by FUN_013d3b20): the
     * values made 64 zeros, then the member's own reset (0x13d4870) in line */
    virtual void reset(); /* derived name */

  private:
    u8 unknown8[0x10];
    Array05943280<u32> values18; /* +0x18 */
    Object013d6840 unknown30;    /* +0x30 */
};

Object016d3b98::~Object016d3b98() {}

void Object016d3b98::reset()
{
    values18.resize(64);
    for (unsigned i = 0; i < values18.size(); ++i)
        values18[i] = 0;
    unknown30.reset();
}
