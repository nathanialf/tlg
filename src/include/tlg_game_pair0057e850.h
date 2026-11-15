/* src/include/tlg_game_pair0057e850.h: two floats assigned as one value
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_PAIR0057E850_H
#define TLG_GAME_PAIR0057E850_H

/* derived name: two floats assigned as one value (0x57e96b: `movabs rdx,
 * 0xbf800000bf800000` stored at +0x3c, the float store at +0x38 before it
 * left alone: three float members would give the first two as the pair;
 * also 0xa52322: 1.0 at +0x44, then 1.0 and 0.6 at +0x48 in one store) */
struct Pair0057e850 {
    Pair0057e850() {}

    Pair0057e850(float a, float b) : unknown0(a), unknown4(b) {}

    float unknown0; /* not traced */
    float unknown4; /* not traced */
};

#endif
