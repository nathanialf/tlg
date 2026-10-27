/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The composite shape finishes itself (bit 2 of the flags when finishing),
 * the instances are left as loaded and the unserialized signals start
 * empty. */
// NONMATCHING: equal but the vtable: hknpCompoundShape's 0x1697900 has no row
// (the name is a fact, its slot 3 returns the class's hkClass; a ruling).
hknpCompoundShape::hknpCompoundShape(hkFinishLoadedObjectFlag flag)
    : hknpCompositeShape(flag), instances(flag)
{
}
