/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the class test as an hkBool, forwarding to the hkClass
 * comparison FUN_00004210. The mesh code at 0xacf61, 0xad32b and 0xad854
 * tests an object's class (its vtable slot 3) against a known class with it
 * (at 0xacf61, hkMemoryMeshVertexBuffer's, from FUN_0002ae00). */
hkBool FUN_00185450(const hkClass *self, const hkClass *other) /* derived name */
{
    return FUN_00004210(self, other);
}
