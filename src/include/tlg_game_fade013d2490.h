/* src/include/tlg_game_fade013d2490.h: the fading state ten classes of the
 * game region share (docs/TARGETS.md), read from the bytes of FUN_013d2490
 * and its nine copies. Every name here is derived. */
#ifndef TLG_GAME_FADE013D2490_H
#define TLG_GAME_FADE013D2490_H

#include "tlg_types.h"

/* derived names: an entry of the fader's own array at +0x18, 0x80 bytes,
 * whose int at +0x40 the update clears */
struct FadeEntry013d2490 { /* derived name */
    u8 unknown0[0x40];
    int unknown40; /* +0x40 */
    u8 unknown44[0x3c];
};

/* derived names: an entry of the target's array, 0xa0 bytes, whose int at
 * +0x90 the update clears */
struct FadeTargetEntry013d2490 { /* derived name */
    u8 unknown0[0x90];
    int unknown90; /* +0x90 */
    u8 unknown94[0xc];
};

struct FadeTarget013d2490 {           /* derived name */
    FadeTargetEntry013d2490 *entries; /* +0x0 */
    u8 unknown8[0x10];
    int count; /* +0x18: read again each pass (`movsxd rax, [r8+0x18]`) */
};

struct FadeClock013d2490 { /* derived name */
    u8 unknown0[0x14];
    float step; /* +0x14: divided by the fade's length */
};

struct FadeOwner013d2490 { /* derived name */
    u8 unknown0[0x20];
    FadeClock013d2490 *clock; /* +0x20 */
    u8 unknown28[0x18];
    FadeTarget013d2490 *target; /* +0x40 */
};

/* derived names: the object of the ten classes: its state at +0x58 (1
 * fading in, 2 full, 3 fading out, 0 off) and level at +0x5c are stored as
 * one qword when a fade ends (`movabs rax, 0x3f80000000000002`) */
struct Fade013d2490 { /* derived name */
    u8 unknown0[0x10];
    FadeOwner013d2490 *owner;   /* +0x10 */
    FadeEntry013d2490 *entries; /* +0x18 */
    u8 unknown20[0x38];
    int state;   /* +0x58 */
    float level; /* +0x5c */
    u32 unknown60;
    float fadeIn;  /* +0x64: the fade-in's length */
    float fadeOut; /* +0x68: the fade-out's length */
    int unknown6c; /* +0x6c: cleared by the update */
};

#endif
