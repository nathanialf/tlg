/* src/include/tlg_game_object016cacb8.h: the class whose vtable is at
 * 0x16cacb8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CACB8_H
#define TLG_GAME_OBJECT016CACB8_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: four ints, and a pair of them made from one value passed
 * by value (0x421a14 to 0x421a5e: the 16 bytes at 0x57d3f20 read as two
 * 8-byte halves, the calling convention's form of the argument, and stored
 * int by int into both). What the four ints are is not traced. */
struct Value00421900 { /* derived name */

    /* member by member (the eight int stores) */
    Value00421900 &operator=(const Value00421900 &other)
    {
        a = other.a;
        b = other.b;
        c = other.c;
        d = other.d;
        return *this;
    }

    int a, b, c, d;
};

struct Pair00421900 { /* derived name */

    Pair00421900(Value00421900 value)
    {
        first = value;
        second = value;
    }

    Value00421900 first;  /* +0x0 */
    Value00421900 second; /* +0x10 */
};

extern Value00421900 D_57d3f20;

/* derived names: the class whose vtable is at 0x16cacb8
 * (config/vtables.derived.base.txt, stored by FUN_00421900 FUN_01350410
 * FUN_01350530), derived from Object016b9108. 0x50 bytes (`mov edi,
 * 0x50` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00421900 sets them and its destructor FUN_01350410
 * tears them down. */
class Object016cacb8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov qword
     * [r15+0x28], 0`, then the four ints at 0x57d3f20 copied twice, from
     * +0x30 and from +0x40 (read once as two 8-byte halves, stored as eight
     * ints: the value was passed by value) */
    Object016cacb8(const Name &name) : Object016b9108(name), unknown30(D_57d3f20) {}

    virtual ~Object016cacb8();

  private:
    /* +0x28: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held28;
    Pair00421900 unknown30; /* +0x30: the value at 0x57d3f20 twice; not traced */
};

/* derived name: the complete destructor FUN_01350410: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_01350530, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00421900.cpp)
 * emits the vtable and both destructors. */
inline Object016cacb8::~Object016cacb8() {}

#endif
