/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_simd.h"

/* derived names: the 0x40-byte, 16-byte aligned element of the array
 * FUN_00482b90 and FUN_0048e8d0 empty: a Name at +0x0 is all its
 * destructor releases; the other fields are not traced */
struct Record01352cf0 { /* derived name */
    Name name;          /* +0x0 */
    Vec4 unknown10[3];  /* +0x10 */
};

/* FUN_01352cf0: the array emptied and its capacity set (each Name
 * released, the count cleared, the block reallocated where the capacity
 * differs) */
template void Array05943280<Record01352cf0>::clear(unsigned);
