/* src/include/tlg_game_object016d25b0.h: the class whose vtable is at
 * 0x16d25b0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D25B0_H
#define TLG_GAME_OBJECT016D25B0_H

#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16d25b0
 * (config/vtables.derived.base.txt, stored by FUN_00d745a0 FUN_013bb900
 * FUN_013bba20), derived from Object01343880. 0xc0 bytes (`mov edi,
 * 0xc0` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00d745a0 sets them and its destructor FUN_013bb900
 * tears them down. */
class Object016d25b0 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword
     * [rbx+0x40], 0x101`, 32 bytes cleared at +0x50, 1.0, 0 and 1.0 from
     * +0x70, 16 bytes cleared at +0x7c, 1.0 twice from +0x8c, four floats at
     * +0xa0 from the constants at 0x1546840 (0, 0, 0, 1.0), `mov qword
     * [rbx+0xb8], 0`. The widths of the cleared fields are read from the
     * stores the vectoriser made of them (four 8-byte fields in one 32-byte
     * store, four 4-byte ones in a 16-byte store between floats left alone) */
    Object016d25b0(const Name &name)
        : Object01343880(name), unknown40(0x101), unknown50(0), unknown58(0), unknown60(0),
          unknown68(0), unknown70(1.0f), unknown74(0.0f), unknown78(1.0f), unknown7c(0),
          unknown80(0), unknown84(0), unknown88(0), unknown8c(1.0f), unknown90(1.0f),
          unknowna0(0.0f), unknowna4(0.0f), unknowna8(0.0f), unknownac(1.0f)
    {
    }

    virtual ~Object016d25b0();

  private:
    u8 unknown34[0xc];
    int unknown40; /* +0x40: 0x101 from the constructor; not traced */
    u8 unknown44[0xc];
    void *unknown50; /* +0x50: null from the constructor; not traced */
    void *unknown58; /* +0x58: null from the constructor; not traced */
    void *unknown60; /* +0x60: null from the constructor; not traced */
    void *unknown68; /* +0x68: null from the constructor; not traced */
    float unknown70; /* +0x70: 1.0 from the constructor; not traced */
    float unknown74; /* +0x74: 0.0 from the constructor; not traced */
    float unknown78; /* +0x78: 1.0 from the constructor; not traced */
    int unknown7c;   /* +0x7c: zero from the constructor; not traced */
    int unknown80;   /* +0x80: zero from the constructor; not traced */
    int unknown84;   /* +0x84: zero from the constructor; not traced */
    int unknown88;   /* +0x88: zero from the constructor; not traced */
    float unknown8c; /* +0x8c: 1.0 from the constructor; not traced */
    float unknown90; /* +0x90: 1.0 from the constructor; not traced */
    u8 unknown94[0xc];
    float unknowna0; /* +0xa0: 0.0 from the constructor; not traced */
    float unknowna4; /* +0xa4: 0.0 from the constructor; not traced */
    float unknowna8; /* +0xa8: 0.0 from the constructor; not traced */
    float unknownac; /* +0xac: 1.0 from the constructor; not traced */
    u8 unknownb0[0x8];
    /* +0xb8: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> heldb8;
};

/* derived name: the complete destructor FUN_013bb900: the body is empty; the
 * members are released, last first, then the base's destructor is inlined.
 * FUN_013bba20, slot 1, is the deleting one and holds this one inlined.
 * Defined here, so the unit that creates the object (leaf_00d745a0.cpp)
 * emits the vtable and both destructors. */
inline Object016d25b0::~Object016d25b0() {}

#endif
