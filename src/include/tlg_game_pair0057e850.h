/* src/include/tlg_game_pair0057e850.h: two floats assigned as one value
 * (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_PAIR0057E850_H
#define TLG_GAME_PAIR0057E850_H

/* derived name: two floats assigned as one value in a constructor's body
 * (0x57e96b: `movabs rdx, 0xbf800000bf800000` stored at +0x3c, the float
 * store at +0x38 before it left alone: three float members would give the
 * first two as the pair). The copy is a memcpy the instruction combiner
 * makes one 8-byte load and store before the value's constructor is
 * inlined; initialised in a member list it would be two float stores. The
 * same at 0x429acf (1.0 twice at +0x38 after 1.0 at +0x34) and 0x9b337b (0
 * and 20.0 at +0x2c after 0.1 at +0x28). */
struct Pair0057e850 {
    Pair0057e850() {}

    Pair0057e850(float a, float b) : unknown0(a), unknown4(b) {}

    float unknown0; /* not traced */
    float unknown4; /* not traced */
};

#endif
