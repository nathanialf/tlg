/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void MersenneTwister::FUN_000106e0(u32 seed)
{
    if (!state) {
        state = static_cast<u32 *>(D_16dc070->temp58->blockAlloc(NUM_STATE_WORDS * sizeof(u32)));
    }
    state[0] = seed;
    for (int i = 1; i < NUM_STATE_WORDS; i++) {
        state[i] = 1812433253 * (state[i - 1] ^ (state[i - 1] >> 30)) + i;
    }
    index = 0;
}
