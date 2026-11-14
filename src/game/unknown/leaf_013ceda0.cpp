/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0134f620.h"

/* derived names: one 32-byte entry of the array at +0x118 of two holders
 * (0xf3de60, 0x13d2331): a counted reference to a node and an array of
 * such references. Its destructor tears the array down first (`lea rdi,
 * [r12+rbx+8]; call 0x134f620`), then releases the reference at +0x0. The
 * holders are not traced. */
struct Entry013ceda0 {              /* derived name */
    Ref00503fb0<Node00503fb0> node; /* +0x0 */
    Object0134f620 nodes;           /* +0x8 */
};

/* The destruction of the array's elements is a function of its own in the
 * executable (0x13ceda0): the member instantiated here. */
template void Array05943280<Entry013ceda0>::destroyElements();
