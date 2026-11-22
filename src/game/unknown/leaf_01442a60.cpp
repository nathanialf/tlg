/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_value004af700.h"
#include "tlg_simd.h"

/* derived name: the value every new element takes at +0x40 (`mov rsi,
 * [0x5ad45a0]; mov rdi, [0x5ad45a8]`, read once before the loop) */
extern Value004af700 D_5ad45a0;

/* derived names: the 0x50-byte, 16-byte aligned element of the array
 * FUN_0114db30 sizes: its constructor copies the value at 0x5ad45a0 to
 * +0x40 member by member, then clears the first 0x40 bytes (two 32-byte
 * stores, after the value's); the fields are not traced */
struct Record01442a60 { /* derived name */

    Record01442a60()
    {
        unknown40.set(D_5ad45a0);
        memset(unknown0, 0, sizeof(unknown0));
    }

    Vec4 unknown0[4];        /* +0x0 */
    Value004af700 unknown40; /* +0x40 */
};

/* FUN_01442a60: the array sized (emptied, the capacity made the count, the
 * block reallocated where it differs, then each element built) */
template void Array05943280<Record01442a60>::resize(unsigned);
