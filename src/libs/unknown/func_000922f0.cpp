/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

RefArrays::EntryId RefArrays::FUN_000922f0(hknpTaskInterface *task, int value8, int valueA)
{
    EntryId entryId;
    entryId.value = u16(array10.size);
    Entry10 &entry = array10.expandOne();
    entry.task = task;
    entry.unknown8 = u16(value8);
    entry.unknownA = u16(valueA);
    entry.unknownC = 0xffff;
    entry.unknownE = 0;
    return entryId;
}
