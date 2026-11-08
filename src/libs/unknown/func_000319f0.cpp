/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: FUN_00031a30 with the record's own count, type and flags. */
void FUN_000319f0(const Pair08Owner *self, Pair08Target *target, hkBlockStreamReader *reader,
                  CacheWriter00031a30 *writer, hkBlockStreamBlock **blockOut)
{
    FUN_00031a30(self, target, self->count, self->type, self->unknown4, reader, writer, blockOut);
}
