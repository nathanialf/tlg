/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the cleanup callback of hkMonitorStreamColorTable's type
 * info (stored at 0x57af3e8 by the initializer at 0x3f0): destroy the object
 * in place through its virtual destructor. The type infos of the other
 * polymorphic classes hold the same body as their cleanup (hkUuidObject at
 * 0x57b7ae8, hkSimpleLocalFrame, hkGeometry, hkcdShape and the hkcd planar
 * classes); an identical body at 0x37d0 has no reference (folded). */
void FUN_000002d0(void *object) /* derived name */
{
    static_cast<hkMonitorStreamColorTable *>(object)->~hkMonitorStreamColorTable();
}
