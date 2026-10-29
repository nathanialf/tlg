/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The platform object writer's destructor: the copier it built released,
 * then the cache it holds, if any. */
// NONMATCHING: the copier's release keeps its count load apart from the
// compare (`mov eax, [rdi+8]; cmp eax, 0x10000`) where the compile folds it
// (`cmp dword [rdi+8], 0x10000`): 3.3's peephole refuses the fold when the
// loaded word has a DBG_VALUE (D30), so the base's first release holds the
// word in a named value; the cache's release folds as written (docs/NOTES.md,
// Round 54). The deleting destructor 0x19ab10 has the same residual.
hkPlatformObjectWriter::~hkPlatformObjectWriter()
{
    copier->removeReference();
    if (cache) {
        cache->removeReference();
    }
}
