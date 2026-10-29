/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The twister's constructor; the state is allocated when it is first
 * seeded. */
MersenneTwister::MersenneTwister()
{
    state = 0;
}
