/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: a new pair's cache of type 1, one quad long, appended to the
 * writer: the header, the cleared fields, then the two bodies' ids. */
void FUN_001785a0(const hknpWorld *world, const hknpBody *bodyA, const hknpBody *bodyB,
                  hkBlockStreamWriter *writer) /* derived name */
{
    CollisionCache001785a0 *cache =
        static_cast<CollisionCache001785a0 *>(writer->reserve(sizeof(CollisionCache001785a0)));
    const CollisionCache001785a0::Header header = {1, 1};
    cache->header = header;
    cache->unknownE = 0;
    cache->unknownA = 0;
    cache->unknownC = 0;
    cache->bodyIdA = bodyA->id;
    cache->bodyIdB = bodyB->id;
    writer->advance(sizeof(CollisionCache001785a0));
}
