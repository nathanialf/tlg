/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 9 of the class at 0x168d8f0 returns its name, the
 * string at +0x70 without the ownership bit (hkMemoryMeshBody's slot 20
 * holds the same body). */
const char *Class168d8f0::FUN_0000dcb0() const /* derived name */
{
    return name.cString();
}
