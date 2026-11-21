/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16d5548 (config/vtables.derived.base.txt): it stores the vtable and releases
 * the array at +0x18 (its block, tlg_game_block.h). The destructor is
 * the class's key function, so this file emits the vtable; the deleting one
 * is the compiler's. The other members are not traced. */
class Object013f9a30 /* derived name */
{
  public:
    virtual ~Object013f9a30();

    /* slot 2 (FUN_013f6fd0): the values made 472 zeros, the block reallocated
     * to exactly 472 when the capacity differs */
    virtual void reset(); /* derived name */

  private:
    u8 unknown8[0x10];
    Array05943280<u32> values18; /* +0x18: owned by the object, released by the destructor */
};

Object013f9a30::~Object013f9a30() {}

void Object013f9a30::reset()
{
    values18.resize(472);
    for (unsigned i = 0; i < values18.size(); ++i)
        values18[i] = 0;
}
