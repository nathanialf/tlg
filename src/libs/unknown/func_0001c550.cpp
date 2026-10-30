/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the entries searched from the last for the key. */
hkReferencedObject *hkRefCountedProperties::FUN_0001c550(u16 key) const
{
    const Entry *entry = entries.data;
    for (int i = entries.size - 1; i >= 0; i--) {
        if (entry[i].key == key) {
            return entry[i].object.pntr;
        }
    }
    return 0;
}
