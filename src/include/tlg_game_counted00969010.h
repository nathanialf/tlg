/* src/include/tlg_game_counted00969010.h: the class of the objects the
 * append FUN_00969010 takes references to, and the record that holds the
 * array (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_COUNTED00969010_H
#define TLG_GAME_COUNTED00969010_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: one of the root class's (the count at +0x8), made by slot
 * 9 of the objects FUN_00963120 to FUN_00964020 hold; not traced further.
 * The array of references to it has its append as a function of its own in
 * the executable, FUN_00969010 (leaf_00969010.cpp), called from 11 sites in
 * 6 functions. */
struct Counted00969010 : Object016b9108 {}; /* derived name */

typedef Array05943280<Ref00503fb0<Counted00969010>> Array00969010; /* derived name */

/* derived names: the bases a made object has behind the root class's
 * part, each a vtable pointer as far as the six functions show, named for
 * the array of the record a pointer to it goes in: +0x60 (the base at +0x38
 * of FUN_00963610's and FUN_00963260's objects, at +0x28 of FUN_00963950's),
 * +0x78 (at +0x40 of FUN_00963260's), +0x90 (at +0x28 of FUN_00964020's, at
 * +0x40 of FUN_00963950's), +0xb0 (at +0x50 of FUN_00963950's); and the one
 * at +0x30 of FUN_00963260's object, whose slot 1 answers an int. Their
 * slots are not traced. */
struct Part00969010_60 {  /* derived name */
    virtual void slot0(); /* derived name; not traced */
};

struct Part00969010_78 {  /* derived name */
    virtual void slot0(); /* derived name; not traced */
};

struct Part00969010_90 {  /* derived name */
    virtual void slot0(); /* derived name; not traced */
};

struct Part00969010_b0 {  /* derived name */
    virtual void slot0(); /* derived name; not traced */
};

struct Part00963260_30 {  /* derived name */
    virtual void slot0(); /* derived name; not traced */
    virtual int slot1();  /* derived name */
};

/* derived names: what the record's first member points to, as the six
 * functions read it */
struct Owner00963120 { /* derived name */
    u8 unknown0[8];
    void *unknown8; /* +0x8 */
    u8 unknown10[8];
    int unknown18; /* +0x18: FUN_00963260 stores a made object's answer */
    u8 unknown1c[8];
    int flags24; /* +0x24: FUN_00963260 stores the holder's flags */
    u8 unknown28[8];
    char *unknown30; /* +0x30: FUN_00963260 hands on its +0x190 too */
    void *unknown38; /* +0x38 */
};

/* derived names: the record FUN_00963120 to FUN_00964020 fill, each from
 * one of the holder's objects: the object each one makes is kept at its
 * own offset, a reference to it appended to the array at +0x30 and, for
 * some, a pointer to one of its bases to the arrays at +0x60, +0x78,
 * +0x90 and +0xb0. Offsets and widths from the six functions' loads and stores. */
struct Record00963120 {   /* derived name */
    Owner00963120 *owner; /* +0x0 */
    void *unknown8;       /* +0x8 */
    u8 unknown10[8];
    Counted00969010 *made18;                  /* +0x18: FUN_00963120's */
    Counted00969010 *made20;                  /* +0x20: FUN_00963260's */
    Counted00969010 *made28;                  /* +0x28: FUN_00963830's */
    Array00969010 objects;                    /* +0x30 */
    Array05943280<Counted00969010 *> made48;  /* +0x48: FUN_00963950's */
    Array05943280<Part00969010_60 *> parts60; /* +0x60 */
    Array05943280<Part00969010_78 *> parts78; /* +0x78 */
    Array05943280<Part00969010_90 *> parts90; /* +0x90 */
    Counted00969010 *madea8;                  /* +0xa8: FUN_00963610's */
    Array05943280<Part00969010_b0 *> partsb0; /* +0xb0 */
    Counted00969010 *madec8;                  /* +0xc8: FUN_00964020's */
};

/* derived names: one of the holder's objects, of the root class's, with
 * the function that makes the object at slot 9 of its vtable (`call [rax +
 * 0x48]`); slots 5 to 8 are not traced. Each kind takes its own
 * arguments. */
struct Maker00969010 : Object016b9108 { /* derived name */
    virtual void slot5();               /* derived name; not traced */
    virtual void slot6();               /* derived name; not traced */
    virtual void slot7();               /* derived name; not traced */
    virtual void slot8();               /* derived name; not traced */
};

/* derived names: the holder, as the six functions read it */
struct Holder00963120 { /* derived name */
    u8 unknown0[0x40];
    Maker00969010 *maker40;                    /* +0x40 */
    Array05943280<Object016b9108 *> objects48; /* +0x48 */
    u8 unknown60[0x18];
    Maker00969010 *maker78; /* +0x78 */
    Maker00969010 *maker80; /* +0x80 */
    void *unknown88;        /* +0x88 */
    u8 unknown90[8];
    Maker00969010 *maker98; /* +0x98 */
    Maker00969010 *makera0; /* +0xa0 */
    int flagsa8;            /* +0xa8 */
};

#endif
