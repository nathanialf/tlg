/* src/include/tlg_game_object0092cba0.h: the object FUN_0092cba0 sets a
 * counted reference of (game region; docs/TARGETS.md). Every name here is
 * derived. */
#ifndef TLG_GAME_OBJECT0092CBA0_H
#define TLG_GAME_OBJECT0092CBA0_H

#include "tlg_game_node.h"

/* derived names: the object set: a class of its own over the counted one
 * (the pointer is converted before the exchange: AtomicRef0045c470's set) */
class Value0092cba0 : public Object016b9108 /* derived name */
{
};

/* derived names: an object of the root class with the counted reference at
 * +0x260 FUN_0092cba0 sets; FUN_00202f60 makes one of the type at 0x5820840
 * and calls its slot 27 (`call [rax+0xd8]`) with nothing else. The class's
 * vtable and its other fields are not traced. */
class Object0092cba0 : public Object016b9108 /* derived name */
{
  public:
    virtual void slot5();  /* derived name; not traced */
    virtual void slot6();  /* derived name; not traced */
    virtual void slot7();  /* derived name; not traced */
    virtual void slot8();  /* derived name; not traced */
    virtual void slot9();  /* derived name; not traced */
    virtual void slot10(); /* derived name; not traced */
    virtual void slot11(); /* derived name; not traced */
    virtual void slot12(); /* derived name; not traced */
    virtual void slot13(); /* derived name; not traced */
    virtual void slot14(); /* derived name; not traced */
    virtual void slot15(); /* derived name; not traced */
    virtual void slot16(); /* derived name; not traced */
    virtual void slot17(); /* derived name; not traced */
    virtual void slot18(); /* derived name; not traced */
    virtual void slot19(); /* derived name; not traced */
    virtual void slot20(); /* derived name; not traced */
    virtual void slot21(); /* derived name; not traced */
    virtual void slot22(); /* derived name; not traced */
    virtual void slot23(); /* derived name; not traced */
    virtual void slot24(); /* derived name; not traced */
    virtual void slot25(); /* derived name; not traced */
    virtual void slot26(); /* derived name; not traced */
    virtual void slot27(); /* derived name; not traced */

    u8 unknown24[0x23c];
    AtomicRef0045c470<Object016b9108> unknown260; /* +0x260 */
};

void FUN_0092cba0(Object0092cba0 *self, Value0092cba0 *value); /* derived name */

#endif
