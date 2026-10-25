/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the accessed member as an array of pointers, one element by
 * index (the link resolver at 0x17f91a stores an object through element 0). */
void *&hkClassMemberAccessor::FUN_001841d0(int index) const /* derived name */
{
    return static_cast<void **>(address)[index];
}
