/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The cleanup callback of hknpSparseCompactMap<hkUint16>'s type info
 * (0x57befa0, set at 0x38ab2): the map destroyed in place, its arrays'
 * storage given back. */
void FUN_000389a0(void *object) /* derived name */
{
    static_cast<hknpSparseCompactMap<u16> *>(object)->~hknpSparseCompactMap();
}
