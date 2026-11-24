/* src/include/tlg_game_hash00c6a3b0.h: Bob Jenkins's lookup3 over a running
 * state of three words (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_HASH00C6A3B0_H
#define TLG_GAME_HASH00C6A3B0_H

#include "tlg_types.h"

struct HashState00c6a3b0 { /* derived name */
    u32 a, b, c;
};

inline u32 rotate(u32 value, int count) /* derived name */
{
    return (value << count) | (value >> (32 - count));
}

/* lookup3's mix and final as lookup3.c itself gives them, macros over three
 * named words (FUN_013bad90): the mix after a block of twelve bytes is added
 * (the rotations 4, 6, 8, 16, 19, 4), the final mix with c the hash (14, 11,
 * 25, 16, 4, 14, 24). The macros never take the words' addresses, and the
 * phis where FUN_013bad90's paths join come out a, b, c; inline functions
 * over references give c, b, a, and the coalescer then keeps the start value
 * in c's register where the base keeps it in a's (0x13bae76: `mov esi, edx;
 * mov eax, edx`). derived names */
#define HASH_MIX(a, b, c)                                                                          \
    do {                                                                                           \
        a -= c;                                                                                    \
        a ^= rotate(c, 4);                                                                         \
        c += b;                                                                                    \
        b -= a;                                                                                    \
        b ^= rotate(a, 6);                                                                         \
        a += c;                                                                                    \
        c -= b;                                                                                    \
        c ^= rotate(b, 8);                                                                         \
        b += a;                                                                                    \
        a -= c;                                                                                    \
        a ^= rotate(c, 16);                                                                        \
        c += b;                                                                                    \
        b -= a;                                                                                    \
        b ^= rotate(a, 19);                                                                        \
        a += c;                                                                                    \
        c -= b;                                                                                    \
        c ^= rotate(b, 4);                                                                         \
        b += a;                                                                                    \
    } while (0)

#define HASH_FINAL(a, b, c)                                                                        \
    do {                                                                                           \
        c ^= b;                                                                                    \
        c -= rotate(b, 14);                                                                        \
        a ^= c;                                                                                    \
        a -= rotate(c, 11);                                                                        \
        b ^= a;                                                                                    \
        b -= rotate(a, 25);                                                                        \
        c ^= b;                                                                                    \
        c -= rotate(b, 16);                                                                        \
        a ^= c;                                                                                    \
        a -= rotate(c, 4);                                                                         \
        b ^= a;                                                                                    \
        b -= rotate(a, 14);                                                                        \
        c ^= b;                                                                                    \
        c -= rotate(b, 24);                                                                        \
    } while (0)

/* lookup3's final mix of the three words, c the hash (the rotations 14,
 * 11, 25, 16, 4, 14, 24: FUN_00534330 after FUN_00c6a3b0) */
inline u32 finalHash(const HashState00c6a3b0 &state) /* derived name */
{
    u32 a = state.a;
    u32 b = state.b;
    u32 c = state.c;
    c ^= b;
    c -= rotate(b, 14);
    a ^= c;
    a -= rotate(c, 11);
    b ^= a;
    b -= rotate(a, 25);
    c ^= b;
    c -= rotate(b, 16);
    a ^= c;
    a -= rotate(c, 4);
    b ^= a;
    b -= rotate(a, 14);
    c ^= b;
    c -= rotate(b, 24);
    return c;
}

/* the key's words mixed into the state (leaf_00c6a3b0.cpp) */
void FUN_00c6a3b0(HashState00c6a3b0 *state, const u32 *key, u32 length); /* derived name */

#endif
