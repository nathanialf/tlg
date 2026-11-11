/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_types.h"

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
 * line 274 and returns -7. */
extern u32 D_179efa0; /* the log mask */
/* volatile: no code of the executable stores to it (24 reads, each a
 * `cmp dword [rip], 0`, never merged into the mask's test), so it is a switch
 * set from outside the program's own flow. */
extern volatile s32 D_5a8e0b0; /* derived name */
extern const char D_15c2fdf[]; /* "Invalid morphing index (%d)\n" */
extern const char D_15c2ffc[]; /* the source file's path */

int FUN_00ef9960(int, int, int code, const char *file, int line, const char *format,
                 va_list args); /* derived name */

// NONMATCHING: written without its other two callers (FUN_00edf960 at line 83,
// FUN_00ee0010 at line 294), IPSCCP folds the one caller's line and format into
// the body; the three must be in this file together.
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

struct Morph00edffb0 { /* derived name */
    u8 unknown0[0x2c];
    s32 unknown2c; /* +0x2c */
};

struct Player00edffb0 { /* derived name */
    u8 unknown0[0x90];
    s32 *morphs;    /* +0x90: self-relative offsets, 0 for none */
    u32 morphCount; /* +0x98 */
};

struct Result00edffb0 { /* derived name */
    u8 unknown0[0x30];
    s32 unknown30; /* +0x30 */
};

int FUN_00edffb0(const Player00edffb0 *player, u32 index, Result00edffb0 *result) /* derived name */
{
    if (player && index < player->morphCount) {
        s32 *slot = &player->morphs[index];
        if (*slot != 0) {
            const Morph00edffb0 *morph = reinterpret_cast<const Morph00edffb0 *>(
                reinterpret_cast<const char *>(slot) + *slot);
            if (morph) {
                result->unknown30 = morph->unknown2c;
                return 0;
            }
        }
    }
    return FUN_00ee00b0(-7, 0, 274, D_15c2fdf, index);
}
