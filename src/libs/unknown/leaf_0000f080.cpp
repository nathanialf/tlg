/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: a stack allocator (vtable address point 0x168da10: slot 2
 * FUN_0000ef00 bumps the cursor at +0x18 within the end at +0x20, falling
 * back to FUN_0000f090) keeps its implementation at +8. FUN_0000f090
 * increments the implementation's count at +0x20 when it hands a block to
 * the large allocator at +0x40, and FUN_0000ef70 decrements it on the free.
 * This getter returns that count; the identical bodies of slot 0 of three
 * game-region vtables (0x16d37a8, 0x16d3c18, 0x16d6970) were folded onto it. */
struct StackAllocatorImpl /* derived name */
{
    u8 unknown0[0x20];
    s32 numLargeAllocations; /* derived name */
};

class StackAllocator /* derived name */
{
  public:
    virtual ~StackAllocator();
    int FUN_0000f080() const; /* derived name */

    StackAllocatorImpl *impl; /* derived name */
};

int StackAllocator::FUN_0000f080() const /* derived name */
{
    return impl->numLargeAllocations;
}
