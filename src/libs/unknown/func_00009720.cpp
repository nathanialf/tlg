/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void FUN_00009720()
{
    hkInplaceArray<SingletonRecord *, 128> records;
    for (SingletonRecord *record = D_57b80b8; record != HK_NULL; record = record->next) {
        if (*record->instance != HK_NULL && record->create != HK_NULL) {
            records.pushBack(record);
        }
    }
    for (int i = records.getSize() - 1; i >= 0; i--) {
        static_cast<hkReferencedObject *>(*records[i]->instance)->releaseReference();
        *records[i]->instance = HK_NULL;
    }
}
