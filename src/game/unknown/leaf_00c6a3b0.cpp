/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: Bob Jenkins's lookup3 (hashlittle's word-aligned path, its
 * mix with the rotations 4, 6, 8, 16, 19, 4) over a running state of three
 * words: the key taken twelve bytes at a time while twelve or more are left
 * (lookup3 keeps the last twelve for its final mix; there is no final mix
 * here), the last 1 to 11 bytes added by a switch (the jump table 0x15595d4,
 * lengths 1 to 11). The one- and two-byte parts are read from the start of
 * the key, not from the words left (the base's `movzbl (%rsi)`, `movzwl
 * 0x4(%rsi)`). The state's owner and callers are not traced. */
struct HashState00c6a3b0 { /* derived name */
    u32 a, b, c;
};

static inline u32 rotate(u32 value, int count) /* derived name */
{
    return (value << count) | (value >> (32 - count));
}

// NONMATCHING: the base sinks the common adds of the words (a += k[0], b += k[1]) into the
// tails shared by lengths 5 to 7 and 9 to 11 (case 4 inside 8's block), the build only the
// varying one; the state's loads (a, b, c in the base) and the loop's adds are in another order
void FUN_00c6a3b0(HashState00c6a3b0 *state, const u32 *key, u32 length) /* derived name */
{
    u32 a = state->a;
    u32 b = state->b;
    u32 c = state->c;
    const u32 *k = key;
    while (length >= 12) {
        a += k[0];
        b += k[1];
        c += k[2];
        a -= c;
        a ^= rotate(c, 4);
        c += b;
        b -= a;
        b ^= rotate(a, 6);
        a += c;
        c -= b;
        c ^= rotate(b, 8);
        b += a;
        a -= c;
        a ^= rotate(c, 16);
        c += b;
        b -= a;
        b ^= rotate(a, 19);
        a += c;
        c -= b;
        c ^= rotate(b, 4);
        b += a;
        length -= 12;
        k += 3;
    }
    switch (length) {
    case 11:
        c += k[2] & 0xffffff;
        b += k[1];
        a += k[0];
        break;
    case 10:
        c += key[2] & 0xffff;
        b += k[1];
        a += k[0];
        break;
    case 9:
        c += key[2] & 0xff;
        b += k[1];
        a += k[0];
        break;
    case 8:
        b += k[1];
        a += k[0];
        break;
    case 7:
        b += k[1] & 0xffffff;
        a += k[0];
        break;
    case 6:
        b += key[1] & 0xffff;
        a += k[0];
        break;
    case 5:
        b += key[1] & 0xff;
        a += k[0];
        break;
    case 4:
        a += k[0];
        break;
    case 3:
        a += k[0] & 0xffffff;
        break;
    case 2:
        a += key[0] & 0xffff;
        break;
    case 1:
        a += key[0] & 0xff;
        break;
    }
    state->a = a;
    state->b = b;
    state->c = c;
}
