/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: fills a pair of ints from its two arguments (the pair's
 * users in tlg_lib_unknown.h). */
void FUN_00006c30(SizePair00006c30 *self, int first, int second) /* derived name */
{
    self->first = first;
    self->second = second;
}
