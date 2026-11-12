/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: an array of 16-byte block records (+0x0, the count at
 * +0x8), each with a state in the low four bits of its first byte (0 free,
 * 2 merged away), a flag in bit 4 and a size at +0xc. FUN_013ace60 frees
 * block i, merging the free block after it and then itself into a free
 * block before it, the survivor's flag taken from the block merged in. */
struct Block013ace60 { /* derived name */
    u8 state : 4;
    u8 flag : 1;
    u8 unknown1[0xb];
    int size; /* +0xc */
};

struct Blocks013ace60 {    /* derived name */
    Block013ace60 *blocks; /* +0x0 */
    int count;             /* +0x8 */
};

// NONMATCHING: block placement of the merged index's constant: for i = 0 the base gives the
// join its 0 in a block of its own (`xor eax, eax; jmp`), the build sets it before the
// `test esi, esi` of the first block; every other instruction equal
void FUN_013ace60(Blocks013ace60 *list, int i) /* derived name */
{
    if (i < 0)
        return;
    if (i < list->count && list->blocks[i + 1].state == 0) {
        list->blocks[i].size += list->blocks[i + 1].size;
        list->blocks[i].flag = list->blocks[i + 1].flag;
        list->blocks[i + 1].state = 2;
        list->blocks[i + 1].flag = 0;
    }
    if (i > 0 && list->blocks[i - 1].state == 0) {
        list->blocks[i - 1].size += list->blocks[i].size;
        list->blocks[i - 1].flag = list->blocks[i].flag;
        list->blocks[i].state = 2;
        list->blocks[i].flag = 0;
        i--;
    }
    list->blocks[i].state = 0;
}
