/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 96 of 108, same size: only the last block's registers. The
// base computes the last word's address (`mov rax, [r12]; sar edx, 5;
// movsxd rdx, edx`) before the mask (`mov esi, -1; shl esi, cl`), lastBit in
// edx and its rounded copy in eax; here the mask comes first and the two
// registers trade. Every spelling of the tail tried (a named index, a pointer,
// the mask first, the size read once) compiles the same (docs/NOTES.md,
// Round 66A).
/* The words for the new size; the bits gained, from the old size to the
 * new one, set to the value; then the bits of the last word past the size
 * set to it too. */
void hkBitField::FUN_00047b30(int startBit, int numBits, int fillValue) /* derived name */
{
    const int oldNumBits = storage.numBits;
    storage.numBits = numBits;
    storage.words.setSize((numBits + 31) >> 5);
    if (oldNumBits < numBits) {
        const u32 fill = u32(-fillValue);
        const u32 startMask = ~0u << (oldNumBits & 31);
        const u32 endMask = ~(~0u << (numBits & 31));
        u32 *words = storage.words.data;
        const int startWord = oldNumBits >> 5;
        const int endWord = numBits >> 5;
        if (startWord == endWord) {
            const u32 mask = startMask & endMask;
            if (mask) {
                words[startWord] = (words[startWord] & ~mask) | (fill & mask);
            }
        } else {
            words[startWord] = (words[startWord] & ~startMask) | (fill & startMask);
            if (endMask) {
                words[endWord] = (words[endWord] & ~endMask) | (fill & endMask);
            }
            u32 *middle = &words[startWord + 1];
            for (int n = endWord - startWord - 1; n > 0; n--) {
                *middle++ = fill;
            }
        }
    }
    if (numBits) {
        const int lastBit = storage.numBits - 1;
        const int numBitsInLastWord = storage.numBits - (lastBit & ~31);
        if (numBitsInLastWord < 32) {
            u32 &lastWord = storage.words.data[lastBit >> 5];
            const u32 mask = ~0u << numBitsInLastWord;
            if (fillValue) {
                lastWord |= mask;
            } else {
                lastWord &= ~mask;
            }
        }
    }
}
