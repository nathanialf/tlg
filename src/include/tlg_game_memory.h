/* The game's zeroing of a block by its address's alignment: four bytes at a
 * time when the address is a multiple of 4, else one byte at a time when it
 * is odd, else two. The loops become memset; the game region's release
 * functions (0xed5260, 0xefa990, 0xf00480, 0xf0a2d0) keep the two alignment
 * tests in front of the one zeroing the three ways lower to. derived name. */
#ifndef TLG_GAME_MEMORY_H
#define TLG_GAME_MEMORY_H

#include "tlg_types.h"

inline void clearMemory(void *memory, unsigned long size) /* derived name */
{
    if (((unsigned long)memory & 3) == 0) {
        u32 *words = (u32 *)memory;
        for (unsigned long i = 0; i < size / 4; i++) {
            words[i] = 0;
        }
    } else if ((unsigned long)memory & 1) {
        u8 *bytes = (u8 *)memory;
        for (unsigned long i = 0; i < size; i++) {
            bytes[i] = 0;
        }
    } else {
        u16 *halves = (u16 *)memory;
        for (unsigned long i = 0; i < size / 2; i++) {
            halves[i] = 0;
        }
    }
}

#endif
