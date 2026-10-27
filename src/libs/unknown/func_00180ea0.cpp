/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The fields are read through packfileData, not this (0x180ea2 on); the
 * address is summed as an integer, the sections' start first (0x180ed3). */
const hkPackfileSectionHeader *hkPackfileHeader::getSectionHeader(const void *packfileData,
                                                                  int i) const /* derived name */
{
    const hkPackfileHeader *header = static_cast<const hkPackfileHeader *>(packfileData);
    if (header->numSections == 0) {
        return 0;
    }
    hkUlong sectionsOffset = sizeof(hkPackfileHeader);
    if (header->fileVersion == 10 || header->fileVersion == 11) {
        sectionsOffset += header->predicateArraySizePlusPadding;
    }
    int sectionHeaderSize;
    if (header->fileVersion < 11) {
        sectionHeaderSize = 0x30;
    } else {
        sectionHeaderSize = header->fileVersion == 11 ? int(sizeof(hkPackfileSectionHeader)) : 0;
    }
    hkUlong sections = reinterpret_cast<hkUlong>(packfileData) + sectionsOffset;
    return reinterpret_cast<const hkPackfileSectionHeader *>(sections + sectionHeaderSize * i);
}
