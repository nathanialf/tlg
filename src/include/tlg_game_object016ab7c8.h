/* src/include/tlg_game_object016ab7c8.h: the class whose vtable is at
 * 0x16ab7c8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AB7C8_H
#define TLG_GAME_OBJECT016AB7C8_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived name: two floats assigned as one value (0x57e96b: `movabs rdx,
 * 0xbf800000bf800000` stored at +0x3c, the float store at +0x38 before it
 * left alone: three float members would give the first two as the pair) */
struct Pair0057e850 {
    Pair0057e850() {}

    Pair0057e850(float a, float b) : unknown0(a), unknown4(b) {}

    float unknown0; /* not traced */
    float unknown4; /* not traced */
};

/* derived names: the class whose vtable is at 0x16ab7c8
 * (config/vtables.derived.base.txt, stored by FUN_0057e850 FUN_0057e9d0
 * FUN_0057eaf0), derived from Object016b9108: slots 5 and 6 are its own
 * (0x1af750, `ret`, defined in the class; FUN_00c1b350, declared, its body
 * is not a member yet). 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_0057e850 sets them and its destructor FUN_0057e9d0
 * tears them down. */
class Object016ab7c8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov qword
     * [r15+0x30], 0` FIRST (the reference, a member), then the body's
     * assignments: 0x54 and 0 from +0x24, 1.0 at +0x38, -1.0 twice from +0x3c
     * in one `movabs` that the 1.0 before it is not part of: the two are one
     * value of two floats, assigned whole */
    Object016ab7c8(const Name &name) : Object016b9108(name)
    {
        unknown24 = 0x54;
        unknown28 = 0;
        unknown38 = 1.0f;
        unknown3c = Pair0057e850(-1.0f, -1.0f);
    }

    virtual ~Object016ab7c8();

    virtual void slot5() {} /* derived name; 0x1af750 */

    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    int unknown24; /* +0x24: 0x54 from the constructor; not traced */
    int unknown28; /* +0x28: zero from the constructor; not traced */
    /* +0x30: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held30;
    float unknown38;        /* +0x38: 1.0 from the constructor; not traced */
    Pair0057e850 unknown3c; /* +0x3c: -1.0 twice from the constructor; not traced */
};

/* derived name: the complete destructor FUN_0057e9d0: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_0057eaf0, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_0057e850.cpp)
 * emits the vtable and both destructors. */
inline Object016ab7c8::~Object016ab7c8() {}

#endif
