/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: fills a pair of ints from its two arguments. The memory
 * system's constructor FUN_0000c270 builds one at its +0x10 from (0, 32768);
 * the game (0xe9963f) builds one on its stack from (1048576, 32768) and
 * hands it to FUN_00001140 while setting up memory. Class unknown. */
struct SizePair00006c30 {
    s32 first;
    s32 second;
};

void FUN_00006c30(SizePair00006c30 *self, int first, int second) /* derived name */
{
    self->first = first;
    self->second = second;
}
