/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: a packfile loaded in place unloaded: in every section,
 * each object a virtual fixup names cleaned up through the type info the
 * load stored in the fixup (its pointer in the fixup's second and third
 * words, high half first), a fixup the load could not resolve skipped. */
void FUN_0017e860(hkPackfileHeader *header) /* derived name */
{
    for (int sectionIndex = 0; sectionIndex < header->numSections; sectionIndex++) {
        const hkPackfileSectionHeader *section = header->getSectionHeader(header, sectionIndex);
        const int sizeofVirtualFixups = section->exportsOffset - section->virtualFixupsOffset;
        if (sizeofVirtualFixups) {
            const s32 *virtualFixups =
                hkAddByteOffsetConst(reinterpret_cast<const s32 *>(header),
                                     section->absoluteDataStart + section->virtualFixupsOffset);
            for (int i = 0;
                 i < (section->exportsOffset - section->virtualFixupsOffset) / int(sizeof(s32));
                 i += 3) {
                const int objectOffset = virtualFixups[i];
                if (objectOffset != -1) {
                    const hkTypeInfo *typeInfo = reinterpret_cast<const hkTypeInfo *>(
                        (hkUlong(u32(virtualFixups[i + 1])) << 32) | u32(virtualFixups[i + 2]));
                    if (typeInfo) {
                        typeInfo->FUN_00092fc0(
                            hkAddByteOffset(hkAddByteOffset(static_cast<void *>(header),
                                                            section->absoluteDataStart),
                                            objectOffset));
                    }
                }
            }
        }
    }
}
