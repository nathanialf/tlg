/* src/include/tlg_game_string01342e50.h: a text of up to 255 characters
 * formatted in place (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_STRING01342E50_H
#define TLG_GAME_STRING01342E50_H

#include "tlg_libc.h"

/* derived names: a string of at most 255 characters and its length at
 * +0x100; FUN_01342e50 formats into it (vsnprintf with 0xff, its last byte
 * cleared first, the length the result or 255 when it is negative); the
 * callers (FUN_0082f550 and nine more) keep it on their frames */
struct String01342e50 {                   /* derived name */
    void format(const char *format, ...); /* derived name */

    char text[0x100];
    int length; /* +0x100 */
};

#endif
