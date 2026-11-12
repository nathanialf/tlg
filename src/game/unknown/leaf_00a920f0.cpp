/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: an entry of 0x5e0 bytes whose destructor is 0xa925e0 (it
 * releases the object at +0x5b0 first; its only callers are the two
 * destructors below, one call per entry). */
class Entry00a925e0 /* derived name */
{
  public:
    ~Entry00a925e0();

  private:
    u8 unknown0[0x5e0];
};

/* derived names: the class of the vtable at 0x16b2a88
 * (config/vtables.derived.base.txt; made by FUN_00a91e30): ten entries from
 * +0x10, destroyed last first. Its complete destructor 0xa920f0 and the
 * deleting one 0xa92190 are the compiler's. Slot 2 is FUN_000069a0. */
class Object016b2a88 /* derived name */
{
  public:
    virtual ~Object016b2a88();

  private:
    u8 unknown8[0x8];
    Entry00a925e0 entries[10]; /* +0x10 */
};

// NONMATCHING: the base computes the first entry's address before the first call and keeps
// it in r14 across the nine others (`lea r14, [rbx + 0x10]`, then `add rbx, 0x5f0` for the
// second entry), the build folds every address to rbx plus a constant (`add rbx, 0x10` last)
Object016b2a88::~Object016b2a88() {}
