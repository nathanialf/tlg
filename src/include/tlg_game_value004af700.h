/* src/include/tlg_game_value004af700.h: a value of four ints copied member
 * by member (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_VALUE004AF700_H
#define TLG_GAME_VALUE004AF700_H

/* derived name: a value of four ints (the eight bytes at a time loaded and
 * split, `mov dword [r15+0x50], eax; shr rax, 0x20; mov dword [r15+0x54],
 * eax`: the value passed in two registers and copied member by member;
 * 0x4af842 from 0x57d7870, 0x991f3e from 0x58224c0) */
struct Value004af700 { /* derived name */

    Value004af700() {}

    /* member by member, from a value passed by value */
    void set(Value004af700 other) /* derived name */
    {
        a = other.a;
        b = other.b;
        c = other.c;
        d = other.d;
    }

    int a; /* not traced */
    int b; /* not traced */
    int c; /* not traced */
    int d; /* not traced */
};

#endif
