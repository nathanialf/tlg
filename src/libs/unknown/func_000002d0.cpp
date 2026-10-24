/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the cleanup callback of hkMonitorStreamColorTable's type
 * info (stored at 0x57af3e8 by the initializer at 0x3f0): destroy the object
 * in place through its virtual destructor. hkUuidObject's type info holds
 * the same body as its cleanup (0x57b7ae8). */
void FUN_000002d0(void *object) /* derived name */
{
    static_cast<hkMonitorStreamColorTable *>(object)->~hkMonitorStreamColorTable();
}
