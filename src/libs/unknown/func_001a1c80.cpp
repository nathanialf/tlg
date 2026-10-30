/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkResult FUN_001a1c80(const hkClass *klass, const hkClassMember *member, int memberIndex,
                      hkStreamWriter *writer) /* derived name */
{
    hkResult result = klass->FUN_00004940(memberIndex, writer);
    if (member->type == hkClassMember::TYPE_STRUCT) {
        const hkClass *structClass = FUN_00004250(member);
        if (structClass) {
            const int numElements = FUN_00007e00(member) ? FUN_00007e00(member) : 1;
            for (int j = 0; j < numElements; j++) {
                for (int i = 0; i < structClass->FUN_00004350(); i++) {
                    if (FUN_001a1c80(structClass, &structClass->FUN_00004370(i), i, writer) ==
                        HK_SUCCESS) {
                        result = HK_SUCCESS;
                    }
                }
            }
        }
    }
    return result;
}
