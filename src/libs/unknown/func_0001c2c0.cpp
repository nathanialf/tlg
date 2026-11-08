/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: Havok's addPropertyInternal by its shape: the last entry
 * of the key first; a reference taken on the object unless asked not to,
 * the entry's old object released. */
void hkRefCountedProperties::FUN_0001c2c0(u16 key, hkReferencedObject *object,
                                          int referenceHandling)
{
    for (int i = entries.getSize() - 1; i >= 0; i--) {
        if (entries[i].key == key) {
            if (referenceHandling == 0) {
                entries[i].object = object;
            } else {
                entries[i].object = hkRefNew<hkReferencedObject>(object);
            }
            return;
        }
    }
    Entry &entry = entries.expandOne();
    entry.key = key;
    if (referenceHandling == 0) {
        entry.object = object;
    } else {
        entry.object.setAndDontIncrementRefCount(object);
    }
}
