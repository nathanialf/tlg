/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void FUN_00009550()
{
    SingletonRecord **prev = &D_57b80b8;
    SingletonRecord *cur = D_57b80b8;

    /* The records whose create function found what it needs not made yet,
     * taken off the list to be tried again. */
    hkArray<SingletonRecord *>::Temp again;

    while (cur != HK_NULL) {
        if (*cur->instance == HK_NULL && cur->create != HK_NULL) {
            hkReferencedObject *object = cur->create();
            if (object == HK_NULL) {
                again.pushBack(cur);
                cur = cur->next;
                (*prev)->next = HK_NULL;
                *prev = cur;
                continue;
            }
            *cur->instance = object;
        }
        prev = &cur->next;
        cur = cur->next;
    }

    /* Each record tried again until every one is made, each made one
     * linked back at the end of the list. */
    while (again.getSize() != 0) {
        for (int i = again.getSize() - 1; i >= 0; i--) {
            SingletonRecord *record = again[i];
            hkReferencedObject *object = record->create();
            if (object != HK_NULL) {
                *record->instance = object;
                *prev = record;
                prev = &record->next;
                again.removeAt(i);
            }
        }
    }
}
