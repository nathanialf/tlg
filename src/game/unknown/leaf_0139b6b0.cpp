/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0139b6b0.h"

/* The destructor of an array of 16-byte records that each hold a counted
 * reference at +0x8 (tlg_game_object0139b6b0.h): the array's own member, a
 * function of its own in the executable, instantiated here. */
// NONMATCHING: a register exchange (greedy's assignment), 87 of 92, 310 bytes against 310: the base
// keeps the block in rcx and the index in rax (`mov rcx, [r14]; mov eax, r13d; shl rax, N`), the build
// the other way round; the two arrays whose element size is not a power of two are equal
template Array05943280<Entry0139b6b0>::~Array05943280();
