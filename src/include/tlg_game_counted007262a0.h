/* src/include/tlg_game_counted007262a0.h: the class of the objects the
 * append FUN_007262a0 takes references to (game region; docs/TARGETS.md).
 * Every name here is derived. */
#ifndef TLG_GAME_COUNTED007262A0_H
#define TLG_GAME_COUNTED007262A0_H

#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: one of the root class's (the count at +0x8), of the type
 * at 0x581cb60 where FUN_00858110 appends a reference to it; slot 34 of
 * its vtable answers flags and slot 35 takes them (`call [rax+0x110]`, the
 * function at +0x118 read before it); the slots between are not traced.
 * The array of references to it has its append as a function of its own
 * in the executable, FUN_007262a0 (leaf_007262a0.cpp), called from 4 sites
 * in 3 functions. */
struct Counted007262a0 : Object016b9108 { /* derived name */
    virtual void slot5();                 /* derived name; not traced */
    virtual void slot6();                 /* derived name; not traced */
    virtual void slot7();                 /* derived name; not traced */
    virtual void slot8();                 /* derived name; not traced */
    virtual void slot9();                 /* derived name; not traced */
    virtual void slot10();                /* derived name; not traced */
    virtual void slot11();                /* derived name; not traced */
    virtual void slot12();                /* derived name; not traced */
    virtual void slot13();                /* derived name; not traced */
    virtual void slot14();                /* derived name; not traced */
    virtual void slot15();                /* derived name; not traced */
    virtual void slot16();                /* derived name; not traced */
    virtual void slot17();                /* derived name; not traced */
    virtual void slot18();                /* derived name; not traced */
    virtual void slot19();                /* derived name; not traced */
    virtual void slot20();                /* derived name; not traced */
    virtual void slot21();                /* derived name; not traced */
    virtual void slot22();                /* derived name; not traced */
    virtual void slot23();                /* derived name; not traced */
    virtual void slot24();                /* derived name; not traced */
    virtual void slot25();                /* derived name; not traced */
    virtual void slot26();                /* derived name; not traced */
    virtual void slot27();                /* derived name; not traced */
    virtual void slot28();                /* derived name; not traced */
    virtual void slot29();                /* derived name; not traced */
    virtual void slot30();                /* derived name; not traced */
    virtual void slot31();                /* derived name; not traced */
    virtual void slot32();                /* derived name; not traced */
    virtual void slot33();                /* derived name; not traced */
    virtual u32 flags();                  /* derived name; slot 34 */
    virtual void setFlags(u32 flags);     /* derived name; slot 35 */
};

typedef Array05943280<Ref00503fb0<Counted007262a0>> Array007262a0; /* derived name */

#endif
