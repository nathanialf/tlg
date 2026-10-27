/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the address of valueB of the entry at an index, the entries
 * following the owner's own bytes (the byte offset is an int). */
float *FUN_0002b030(Pair08Owner *self, int index) /* derived name */
{
    int offset = sizeof(Pair08Owner) + index * sizeof(Pair08Entry);
    Pair08Entry *entry = reinterpret_cast<Pair08Entry *>(reinterpret_cast<char *>(self) + offset);
    return &lane(entry->vectorB, 3);
}
