/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_hash00c6a3b0.h"
#include "tlg_game_name.h"

/* derived names: the hash of a name's string, Bob Jenkins's lookup3 in its
 * big-endian form (hashbig, its byte-wise tail: the last bytes of a word
 * added from the top, `shl ecx, 0x18` for the first), the key read twelve
 * bytes at a time as three words while more than twelve are left, the rest
 * by a switch (the jump table 0x1559c24, lengths 0 to 12; none left returns
 * c without the final mix). The words start from the string's whole length
 * (`lea edx, [rcx+0x6b6f7265]`: 0xdeadbeef and the seed 0x8cc1b376), but
 * only its first 31 bytes are hashed (`cmovb` against 0x1f), so at most two
 * blocks: the second follows the first with no test after it. */
unsigned FUN_013bad90(const char *string) /* derived name */
{
    size_t length = strlen(string);
    u32 a, b, c;
    a = b = c = 0xdeadbeef + u32(length) + 0x8cc1b376;
    length = length < 31 ? length : 31;
    const u32 *k = reinterpret_cast<const u32 *>(string);
    if (length > 12) {
        a += k[0];
        b += k[1];
        c += k[2];
        HASH_MIX(a, b, c);
        length -= 12;
        k += 3;
        if (length > 12) {
            a += k[0];
            b += k[1];
            c += k[2];
            HASH_MIX(a, b, c);
            length -= 12;
            k += 3;
        }
    }
    const u8 *k8 = reinterpret_cast<const u8 *>(k);
    switch (length) {
    case 12:
        c += k[2];
        b += k[1];
        a += k[0];
        break;
    case 11:
        c += u32(k8[10]) << 8;
    case 10:
        c += u32(k8[9]) << 16;
    case 9:
        c += u32(k8[8]) << 24;
    case 8:
        b += k[1];
        a += k[0];
        break;
    case 7:
        b += u32(k8[6]) << 8;
    case 6:
        b += u32(k8[5]) << 16;
    case 5:
        b += u32(k8[4]) << 24;
    case 4:
        a += k[0];
        break;
    case 3:
        a += u32(k8[2]) << 8;
    case 2:
        a += u32(k8[1]) << 16;
    case 1:
        a += u32(k8[0]) << 24;
        break;
    case 0:
        return c;
    }
    HASH_FINAL(a, b, c);
    return c;
}
