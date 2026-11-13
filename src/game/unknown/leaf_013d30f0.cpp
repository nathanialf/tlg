/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16d3750 (config/vtables.derived.base.txt): it stores the vtable and releases
 * the block of the array of ints at +0x18 (tlg_game_array.h: the count at
 * +0x20, the capacity at +0x24, the owner's index at +0x28). The destructor is
 * the class's key function, so this file emits the vtable; the deleting one
 * is the compiler's. The other members are not traced. */
class Object013d30f0 /* derived name */
{
  public:
    virtual ~Object013d30f0();
    virtual void reset(); /* derived name */

  private:
    u8 unknown8[0x10];
    Array05943280<u32> values; /* +0x18 */
};

Object013d30f0::~Object013d30f0() {}

/* derived name: slot 2 (FUN_013ce230): 28 entries, all zero (the array's
 * resize, then the entries cleared). */
// NONMATCHING: a register exchange (the parked class): in the clearing loop the base holds
// the block in rdx and the index in rcx, the build the reverse; the growth is the base's (39 of 42)
void Object013d30f0::reset()
{
    values.resize(28);
    for (unsigned i = 0; i < values.size(); i++)
        values[i] = 0;
}
