/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_009515f0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_creation.h"

/* derived names: a block of `size` bytes, 32-aligned, from the allocator the
 * pointer at 0x5821088 holds (its slot 4 with 0x20 and 1), under the spin
 * lock at 0x5821084 beside it; null for a size of 0 or without an
 * allocator. Called at 0x952a53 and 0x9532ad. The allocator's class and its
 * third argument are not traced. */
class Allocator05821088 /* derived name */
{
  public:
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    virtual void unknown3();
    virtual void *allocate(unsigned size, unsigned alignment, int unknown); /* derived name */
};

extern Lock059458a4 D_5821084;       /* derived name */
extern Allocator05821088 *D_5821088; /* derived name */

void *FUN_009515f0(unsigned size) /* derived name */
{
    D_5821084.lock();
    void *block = 0;
    if (size && D_5821088)
        block = D_5821088->allocate(size, 0x20, 1);
    D_5821084.unlock();
    return block;
}
