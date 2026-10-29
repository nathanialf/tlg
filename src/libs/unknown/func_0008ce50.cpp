/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the cleanup callback of hkxVertexDescription's type info
 * (0x57c7f90): destroy the description in place, its declarations' names
 * from the last. */
void FUN_0008ce50(void *object) /* derived name */
{
    static_cast<hkxVertexDescription *>(object)->~hkxVertexDescription();
}
