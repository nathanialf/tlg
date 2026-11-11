/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_types.h"

/* derived names: two functions of the sound middleware's player transitions,
 * whose source file is named by the string D_15c3941
 * ("...\\sndx\\sndx_player_trans.c").
 *
 * FUN_00eeadf0 reports an error: when bit 0 of the log mask D_179efa0 is set,
 * or the count D_5a8e0b0 is not zero, it hands the format and its arguments
 * to the logger FUN_00ef9960 with the file's name and the caller's line, and
 * it returns the error code it was given, so a caller returns its result. Its
 * second parameter is not read (the callers leave rsi unset: the argument is
 * dropped at every call site in the module).
 *
 * FUN_00eeac70 reads the transition at an index of a player's table of
 * self-relative offsets (+0x80, the count at +0x88) and stores its field at
 * +0x1c into +0x30 of the third argument, returning 0; a null player, an
 * index out of range or an empty entry is reported at line 3767 and returns
 * -7. */
extern u32 D_179efa0; /* the log mask */
/* volatile: no code of the executable stores to it (52 reads in the sound
 * code, each a fresh compare, never merged into the mask's test), so it is a
 * switch set from outside the program's own flow. */
extern volatile s32 D_5a8e0b0; /* derived name */
extern const char D_15c3922[]; /* "Invalid transition index (%d)\n" */
extern const char D_15c3941[]; /* the source file's path */

int FUN_00ef9960(int, int, int code, const char *file, int line, const char *format,
                 va_list args); /* derived name */

// NONMATCHING: list-ilp order, the base computes the va_list's address first
// (`lea rcx, [rbp - 0x30]`) and stores it to the stack argument before the
// file name's `lea`; the build computes the overflow area into rcx first.
int FUN_00eeadf0(int code, int, int line, const char *format, ...) /* derived name */
{
    if ((D_179efa0 & 1) || D_5a8e0b0 != 0) {
        va_list args;
        va_start(args, format);
        FUN_00ef9960(0, 1, code, D_15c3941, line, format, args);
        va_end(args);
    }
    return code;
}

struct Transition00eeac70 { /* derived name */
    u8 unknown0[0x1c];
    s32 unknown1c; /* +0x1c */
};

struct Player00eeac70 { /* derived name */
    u8 unknown0[0x80];
    s32 *transitions;    /* +0x80: self-relative offsets, 0 for none */
    u32 transitionCount; /* +0x88 */
};

struct Result00eeac70 { /* derived name */
    u8 unknown0[0x30];
    s32 unknown30; /* +0x30 */
};

// NONMATCHING: FunctionAttrs infers `returned` on FUN_00eeadf0's code
// (FunctionAttrs.cpp:482) and EarlyCSE's known bits (ValueTracking.cpp:1395)
// put -7 in the result's phi, so the call is no tail call; the base jumps to
// FUN_00eeadf0 and its other callers read eax (0xee7c6e).
int FUN_00eeac70(const Player00eeac70 *player, u32 index, Result00eeac70 *result) /* derived name */
{
    if (player && index < player->transitionCount) {
        s32 *slot = &player->transitions[index];
        if (*slot != 0) {
            const Transition00eeac70 *transition = reinterpret_cast<const Transition00eeac70 *>(
                reinterpret_cast<const char *>(slot) + *slot);
            if (transition) {
                result->unknown30 = transition->unknown1c;
                return 0;
            }
        }
    }
    return FUN_00eeadf0(-7, 0, 3767, D_15c3922, index);
}
