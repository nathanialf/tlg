/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkBinaryPackfileWriter::FUN_00181c00(PackfileSections00181c00 &headers) const
{
    const int numSections = sectionTags.getSize();
    headers.sections.setSize(numSections);
    FUN_00018160(headers.sections.data, -1, numSections * sizeof(hkPackfileSectionHeader));
    for (int i = 0; i < sectionTags.getSize(); i++) {
        FUN_00017fd0(headers.sections[i].sectionTag, sectionTags[i],
                     sizeof(headers.sections[i].sectionTag));
    }
}
