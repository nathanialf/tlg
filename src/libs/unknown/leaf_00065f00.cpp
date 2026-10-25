/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: one of the union-find owner's twelve records by index
 * (called at 0x6d787, 0x6d7a8 and 0x16e461, which resize its bit field). */
Record00065f00 *FUN_00065f00(Object00065f20 *self, int index) /* derived name */
{
    return &self->records[index];
}
