/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkClassEnum::FUN_00014e80(hkStreamWriter *writer) const
{
    hkOArchive archive(writer, false);
    archive.FUN_000089f0(name, FUN_00017fe0(name));
    const int numItemsToWrite = numItems;
    for (int i = 0; i < numItemsToWrite; i++) {
        const Item &item = items[i];
        archive.FUN_000089f0(item.name, FUN_00017fe0(item.name));
        archive.FUN_0000a7a0(item.value);
    }
    archive.FUN_0000a7a0(numItemsToWrite);
}
