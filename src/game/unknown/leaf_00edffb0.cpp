/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_types.h"
#include "tlg_game_memory.h"

/* derived names: two functions of the sound middleware's player morphing,
 * whose source file is named by the string D_15c2ffc
 * ("...\\sndx\\sndx_player_morph.c").
 *
 * FUN_00ee00b0 reports an error as FUN_00eeadf0 does for the transitions:
 * when bit 0 of the log mask D_179efa0 is set, or the count D_5a8e0b0 is not
 * zero, it hands the format and its arguments to the logger FUN_00ef9960 with
 * the file's name and the caller's line. It is file-local: its callers
 * (FUN_00edf960, FUN_00edffb0, FUN_00ee0010) all pass -7 and return -7
 * themselves, and they leave its first two arguments unset.
 *
 * FUN_00edffb0 (its address stored at 0x57ad798) reads the morph at an index
 * of a player's table of self-relative offsets (+0x90, the count at +0x98)
 * and stores its field at +0x2c into +0x30 of the third argument, returning
 * 0; a null player, an index out of range or an empty entry is reported at
 * line 274 and returns -7.
 *
 * FUN_00edf960 takes the morph a request names (its index at +0x28) from the
 * player at +0xa0 of a voice: it clears the voice's flag at +0x3f0, stores
 * the morph's offset from the player's data (+0x20) at +0x408 and clears the
 * 16 bytes at +0x3f4, returning 0; else it reports at line 83.
 *
 * FUN_00ee0010 finds the key entry of a morph: it clears the result (-1
 * without one), and when bit 0 of the morph's flags is set walks its entries
 * (after the array of 4-byte values at +0x34 counted by +0x2c; each a key
 * byte, then at +0x2 the self-relative offset of the next, 0 for none) for
 * the key, returning 0 found or not; a bad index is reported at line 294. */
extern u32 D_179efa0; /* the log mask */
/* volatile: no code of the executable stores to it (24 reads, each a
 * `cmp dword [rip], 0`, never merged into the mask's test), so it is a switch
 * set from outside the program's own flow. */
extern volatile s32 D_5a8e0b0; /* derived name */
extern const char D_15c2fdf[]; /* "Invalid morphing index (%d)\n" */
extern const char D_15c3038[]; /* "Unknown morphing data (%d)\n" */
extern const char D_15c2ffc[]; /* the source file's path */

int FUN_00ef9960(int, int, int code, const char *file, int line, const char *format,
                 va_list args); /* derived name */

// NONMATCHING: list-ilp order: the base takes the va_list's address and the
// overflow area (`lea rcx, [rbp-0x30]; lea r9, [rbp+0x10]`) before the argument
// registers, the build after them (so its zero is `mov edi, 0`, not `xor`)
static int FUN_00ee00b0(int code, int, int line, const char *format, ...) /* derived name */
{
    if ((D_179efa0 & 1) || D_5a8e0b0 != 0) {
        va_list args;
        va_start(args, format);
        FUN_00ef9960(0, 1, code, D_15c2ffc, line, format, args);
        va_end(args);
    }
    return code;
}

/* derived names: one key entry of a morph, the next at a self-relative
 * offset (a 16-bit `movsx` and a select for 0) */
struct MorphKey00ee0010 { /* derived name */
    u8 key;
    u8 unknown1;
    s16 next2; /* +0x2: from this field to the next entry, 0 for none */

    const MorphKey00ee0010 *next() const
    {
        return next2 != 0 ? reinterpret_cast<const MorphKey00ee0010 *>(
                                reinterpret_cast<const char *>(&next2) + next2)
                          : 0;
    }
};

struct Morph00edffb0 { /* derived name */
    u32 flags;         /* +0x0: bit 0, the morph has key entries */
    u8 unknown4[0x28];
    s32 unknown2c; /* +0x2c: also the count of the values at +0x34 */
    u8 unknown30[4];
    u32 values34[1]; /* +0x34: unknown2c of them, then the key entries */

    const MorphKey00ee0010 *firstKey() const
    {
        return reinterpret_cast<const MorphKey00ee0010 *>(&values34[(u32)unknown2c]);
    }
};

struct Player00edffb0 { /* derived name */
    u8 unknown0[0x20];
    const char *data20; /* +0x20 */
    u8 unknown28[0x68];
    s32 *morphs;    /* +0x90: self-relative offsets, 0 for none */
    u32 morphCount; /* +0x98 */
};

/* derived name: the morph at an index of a player's table, null for a null
 * player, an index out of range or an empty entry; inlined in the three
 * functions below. The offset is added to the slot's address as an integer
 * (the base's `add offset, slot`, the offset's register the sum); the index
 * is the helper's argument, so the range test reads `cmp [count], index`
 * (cookbook 1214). */
static inline const Morph00edffb0 *findMorph(const Player00edffb0 *player, u32 index)
{
    if (player && index < player->morphCount) {
        s32 *slot = &player->morphs[index];
        if (*slot != 0)
            return reinterpret_cast<const Morph00edffb0 *>(*slot + reinterpret_cast<s64>(slot));
    }
    return 0;
}

struct Result00edffb0 { /* derived name */
    u8 unknown0[0x30];
    s32 unknown30; /* +0x30 */
};

struct Request00edf960 { /* derived name */
    u8 unknown0[0x28];
    u32 morph28; /* +0x28: the morph's index */
};

struct Voice00edf960 { /* derived name */
    u8 unknown0[0xa0];
    const Player00edffb0 *player; /* +0xa0 */
    u8 unknowna8[0x348];
    u8 unknown3f0; /* +0x3f0 */
    u8 unknown3f1[3];
    u8 unknown3f4[0x10]; /* +0x3f4 */
    s64 morphOffset;     /* +0x408 */
};

int FUN_00edf960(Voice00edf960 *voice, const Request00edf960 *request) /* derived name */
{
    const Player00edffb0 *player = voice->player;
    u32 index = request->morph28;
    const Morph00edffb0 *morph = findMorph(player, index);
    if (morph) {
        voice->unknown3f0 = 0;
        voice->morphOffset = reinterpret_cast<const char *>(morph) - player->data20;
        clearMemory(voice->unknown3f4, sizeof(voice->unknown3f4));
        return 0;
    }
    return FUN_00ee00b0(-7, 0, 83, D_15c3038, index);
}

// NONMATCHING: greedy's assignment: the base keeps the table in rdi and the
// index in ecx, the build the reverse (rcx, edi); FUN_00edf960 is equal
int FUN_00edffb0(const Player00edffb0 *player, u32 index, Result00edffb0 *result) /* derived name */
{
    const Morph00edffb0 *morph = findMorph(player, index);
    if (morph) {
        result->unknown30 = morph->unknown2c;
        return 0;
    }
    return FUN_00ee00b0(-7, 0, 274, D_15c2fdf, index);
}

// NONMATCHING: block placement: the base lays the shared `ret` after the loop
// (the not-found exit falls into it) and gives the error call its own
// epilogue; the build jumps from the loop to the epilogue after the error
// call; the `mov [found], 0` is also scheduled after `test player`
int FUN_00ee0010(const Player00edffb0 *player, u32 index, int key,
                 const MorphKey00ee0010 **found) /* derived name */
{
    if (!found)
        return -1;
    *found = 0;
    const Morph00edffb0 *morph = findMorph(player, index);
    if (morph) {
        if (morph->flags & 1) {
            for (const MorphKey00ee0010 *entry = morph->firstKey(); entry; entry = entry->next()) {
                if (entry->key == key) {
                    *found = entry;
                    return 0;
                }
            }
        }
        return 0;
    }
    return FUN_00ee00b0(-7, 0, 294, D_15c2fdf, index);
}
