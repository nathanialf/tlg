/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known.
 * Each file holds one function, named by its address until a real name and
 * home are found; a function moves out of here when either is. */
#include "tlg_types.h"

/* derived name: a two-word record reset to (0, 2). Unknown owner. */
struct PairRecord {
    s64 first;
    s64 second;
};

void FUN_000104b0(PairRecord *r) /* derived name */
{
    r->first = 0;
    r->second = 2;
}
