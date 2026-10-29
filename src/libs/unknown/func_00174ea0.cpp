/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: a writer bound to the end of the object's stream, the pair
 * walk run into it, the writer finished. */
void FUN_00174ea0(Streams00174ea0 *self, hknpWorld *world, BlockCache *cache,
                  const hkBlockStreamRange *range, void *entries)
{
    hkBlockStreamWriter writer;
    writer.FUN_000938c0(cache, &self->stream400);
    FUN_00174100(world->pointer268, world, range, &writer, entries);
    writer.FUN_00093a10();
}
