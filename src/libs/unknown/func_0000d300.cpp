/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the cleanup callback of hkRefCountedProperties::Entry's
 * type info: destroy the entry in place, which releases its object's
 * reference. */
void hkRefCountedProperties::Entry::FUN_0000d300(void *object)
{
    static_cast<Entry *>(object)->~Entry();
}
