/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The platform object writer's destructor: the copier it built released,
 * then the cache it holds, if any. */
hkPlatformObjectWriter::~hkPlatformObjectWriter()
{
    copier->releaseReference();
    if (cache) {
        cache->removeReference();
    }
}
