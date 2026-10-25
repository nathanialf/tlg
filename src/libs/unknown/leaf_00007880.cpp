/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: slot 9 of the vtables at 0x168cbb0 and 0x16d3390 (the
 * second a game-region class sharing every slot from 2) returns the count at
 * +0x328, the number of 64-byte records that slot 6 (FUN_000076d0) walks
 * after storing the callback FUN_00007730 and its argument at +0x310. */
class Pool00007880 /* derived name */
{
  public:
    virtual ~Pool00007880();

    int FUN_00007880() const; /* vtable slot 9; derived name */

    u8 unknown8[0x320];
    int count; /* derived name */
};

int Pool00007880::FUN_00007880() const /* derived name */
{
    return count;
}
