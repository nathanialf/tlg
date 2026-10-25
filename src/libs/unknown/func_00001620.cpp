/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: slot 12 of TwoBaseAllocator's primary vtable returns the
 * object as its second base, `this` + 8 with no null check. The same body
 * fills slot 12 of the allocator built by FUN_00012160 (0x168e300) and of
 * two further tables (0x16d36d8, 0x16d3a78). */
AllocatorInterface *TwoBaseAllocator::FUN_00001620() /* derived name */
{
    return this;
}
