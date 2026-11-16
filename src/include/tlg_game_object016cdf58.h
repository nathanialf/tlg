/* src/include/tlg_game_object016cdf58.h: the class whose vtable is at
 * 0x16cdf58 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CDF58_H
#define TLG_GAME_OBJECT016CDF58_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_object05945a38.h"

/* derived name: the type of the object the constructor makes (`mov rsi,
 * [0x5822318]` at 0x995c59) */
extern Type00503fb0 *D_5822318;

/* derived name: the made object's class, one over the reference's (`cmp
 * rcx, rbx` at 0x995cd6, the new pointer first); not traced */
struct Value00995b40 : Object016b9108 {};

/* derived names: the class whose vtable is at 0x16cdf58
 * (config/vtables.derived.base.txt, stored by FUN_00995b40 FUN_01387a00
 * FUN_01387b20), derived from Object016b9108. 0x80 bytes (`mov edi,
 * 0x80` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00995b40 sets them and its destructor FUN_01387a00
 * tears them down. */
class Object016cdf58 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, three groups of
     * two pointers and an int cleared (+0x30, +0x50, +0x68: a 16-byte store
     * and `mov dword, 0` each), then an object of the type at 0x5822318 is
     * made under the empty name (FUN_00cbc5a0, mode 0) and the reference at
     * +0x68 set to it */
    Object016cdf58(const Name &name)
        : Object016b9108(name), unknown30(0), unknown38(0), unknown40(0), unknown50(0),
          unknown58(0), unknown60(0), unknown70(0), unknown78(0)
    {
        Value00995b40 *made =
            static_cast<Value00995b40 *>(FUN_00cbc5a0(D_5945a38, D_5822318, Name(), 0));
        held68.set(made);
    }

    virtual ~Object016cdf58();

  private:
    u8 unknown24[0xc];
    void *unknown30; /* +0x30: null from the constructor; not traced */
    void *unknown38; /* +0x38: null from the constructor; not traced */
    int unknown40;   /* +0x40: zero from the constructor; not traced */
    u8 unknown44[0xc];
    void *unknown50; /* +0x50: null from the constructor; not traced */
    void *unknown58; /* +0x58: null from the constructor; not traced */
    int unknown60;   /* +0x60: zero from the constructor; not traced */
    /* +0x68: a counted reference, set by the constructor, released by the
     * destructor */
    AtomicRef0045c470<Object016b9108> held68;
    /* +0x70: null from the constructor, cleared with the reference in one
     * 16-byte store with an int store after it (the vectoriser pairs two
     * pointers of one type); not traced */
    Object016b9108 *unknown70;
    int unknown78; /* +0x78: zero from the constructor; not traced */
};

/* derived name: the complete destructor FUN_01387a00: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_01387b20, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00995b40.cpp)
 * emits the vtable and both destructors. */
inline Object016cdf58::~Object016cdf58() {}

#endif
