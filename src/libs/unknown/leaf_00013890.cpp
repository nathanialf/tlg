/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: a hash map's iterator test. The callers (nine, from
 * 0x17d7c6 to 0x180c0b) walk a map with it: FUN_00091600 returns the first
 * slot whose 24-byte entry has a key other than -1, as an opaque
 * pointer-sized iterator the callers pass whole; this tests that its slot
 * index is within the hash mask at +0xc; FUN_00091650 steps to the next. */
struct Map00013890 /* derived name */
{
    struct IteratorTag;
    typedef IteratorTag *Iterator;

    void *entries;
    int numEntries;
    int hashMod;

    bool FUN_00013890(Iterator it) const; /* derived name */
};

bool Map00013890::FUN_00013890(Iterator it) const /* derived name */
{
    int slot = static_cast<int>(reinterpret_cast<hkUlong>(it));
    return slot <= hashMod;
}
