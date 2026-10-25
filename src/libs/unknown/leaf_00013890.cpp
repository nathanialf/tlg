/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: a string map's iterator test (StringMap, tlg_hk_reflect.h).
 * The callers (nine, from 0x17d7c6 to 0x180c0b) walk a map with it: the
 * iterator is an opaque pointer-sized value the callers pass whole; this
 * tests that its slot index is within the hash mask at +0xc. */
bool StringMap::FUN_00013890(Iterator it) const /* derived name */
{
    int slot = static_cast<int>(reinterpret_cast<hkUlong>(it));
    return slot <= hashMod;
}
