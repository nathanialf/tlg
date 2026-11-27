/* src/include/tlg_game_string01331840.h: a text of up to 4095 characters
 * formatted in place (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_STRING01331840_H
#define TLG_GAME_STRING01331840_H

#include "tlg_types.h"
#include "tlg_libc.h"
#include "tlg_game_name.h"

/* derived names: FUN_01331840 formats into the text with vsnprintf at most
 * 0xfff characters (the last byte cleared first) and stores the length it
 * gives, 0xfff for an error, at +0x1000; the callers read the text back with
 * strlen. 0x1008 bytes on the callers' frames (`lea rdi, [rbp-0x1028]` with
 * the guard at -0x20, FUN_001b0f50), the last four not traced. */
struct String01331840 { /* derived name */
    char text[0x1000];
    int length;      /* +0x1000 */
    int unknown1004; /* +0x1004: not traced */
};

void FUN_01331840(String01331840 *string, const char *format, ...); /* derived name */
/* the same without the last byte cleared first (leaf_00317070.cpp) */
void FUN_00317070(String01331840 *string, const char *format, ...); /* derived name */
/* the arguments formatted after the text (leaf_01346a00.cpp) */
void FUN_01346a00(String01331840 *string, const char *format, ...); /* derived name */

inline Name::Name(const String01331840 &text)
    : index(text.text[0]
                ? FUN_013baad0(text.text, FUN_013bad90(text.text), strlen(text.text), false)
                : 0)
{
}

/* derived names: the same text of up to 0x7f characters, its length at
 * +0x80 (FUN_013709f0 appends to it; FUN_00847550 formats with it) */
struct String013709f0 { /* derived name */
    char text[0x80];
    int length; /* +0x80 */
};

/* derived names: a text of at most 127 characters in a 128-byte buffer and
 * its length at +0x80, made empty (the first and last bytes and the length
 * cleared: 0x489c8c to 0x489c9a); FUN_004a6d50 formats into it */
struct Text004a6d50 { /* derived name */

    Text004a6d50() : length(0)
    {
        text[0] = 0;
        text[sizeof text - 1] = 0;
    }

    char text[0x80];
    int length; /* +0x80 */
};

inline Name::Name(const Text004a6d50 &text)
    : index(text.text[0]
                ? FUN_013baad0(text.text, FUN_013bad90(text.text), strlen(text.text), false)
                : 0)
{
}

#endif
