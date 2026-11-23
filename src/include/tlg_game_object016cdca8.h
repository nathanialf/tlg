/* src/include/tlg_game_object016cdca8.h: the class whose vtable is at
 * 0x16cdca8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CDCA8_H
#define TLG_GAME_OBJECT016CDCA8_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_pair0057e850.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cdca8
 * (config/vtables.derived.base.txt, stored by FUN_009b5d10 FUN_01385b80), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields from +0x28
 * are traced where its creator FUN_009b5d10 sets them and its destructor
 * FUN_01385b80 tears them down. 0xc0 bytes (`mov edi, 0xc0` before operator
 * new).
 * The destructor is implicit: FUN_01385b80 and the deleting
 * FUN_01385c20 sit in the stretch of inline functions (from 0x1340000)
 * while the constructor is out of line, so the class has no key function
 * and the unit that constructs it (leaf_009b5d10.cpp) emits the vtable
 * with both. */
class Object016cdca8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator FUN_009b5d10: the base built from the name, the
     * vptr, the two arrays empty (each lock word stored apart), the floats in
     * their order (the eight from +0x60 one store, the four from +0x80 one
     * more: the link's vectoriser, after the unit's) and the int; then the
     * body: the two-float value at +0xb4 */
    Object016cdca8(const Name &name)
        : Object016b9108(name), unknown60(0.3f), unknown64(0.1f), unknown68(0.0f), unknown6c(1.0f),
          unknown70(0.35f), unknown74(0.1f), unknown78(0.0f), unknown7c(1.0f), unknown80(0.4f),
          unknown84(0.1f), unknown88(0.0f), unknown8c(1.0f), unknown90(0.25f), unknown94(0.45f),
          unknown98(0.8f), unknown9c(1), unknowna0(-10.0f), unknowna4(50.0f), unknowna8(15.0f),
          unknownac(10.0f), unknownb0(25.0f)
    {
        unknownb4 = Pair0057e850(10.0f, 0.0f);
    }

  private:
    u8 unknown24[0x4];
    /* +0x28: an array of counted references with its lock, torn down by the
     * destructor (`lea rdi, [rbx+0x28]; call 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> record28;
    /* +0x40: the same kind of array, torn down by the destructor (`lea rdi,
     * [rbx+0x40]; call 0x134f620`) */
    Array01343a80<Ref00503fb0<Object016b9108>> record40;
    u8 unknown58[0x8];
    float unknown60;        /* +0x60: 0.3 from the constructor; not traced */
    float unknown64;        /* +0x64: 0.1 from the constructor; not traced */
    float unknown68;        /* +0x68: zero from the constructor; not traced */
    float unknown6c;        /* +0x6c: 1.0 from the constructor; not traced */
    float unknown70;        /* +0x70: 0.35 from the constructor; not traced */
    float unknown74;        /* +0x74: 0.1 from the constructor; not traced */
    float unknown78;        /* +0x78: zero from the constructor; not traced */
    float unknown7c;        /* +0x7c: 1.0 from the constructor; not traced */
    float unknown80;        /* +0x80: 0.4 from the constructor; not traced */
    float unknown84;        /* +0x84: 0.1 from the constructor; not traced */
    float unknown88;        /* +0x88: zero from the constructor; not traced */
    float unknown8c;        /* +0x8c: 1.0 from the constructor; not traced */
    float unknown90;        /* +0x90: 0.25 from the constructor; not traced */
    float unknown94;        /* +0x94: 0.45 from the constructor; not traced */
    float unknown98;        /* +0x98: 0.8 from the constructor; not traced */
    int unknown9c;          /* +0x9c: 1 from the constructor; not traced */
    float unknowna0;        /* +0xa0: -10.0 from the constructor; not traced */
    float unknowna4;        /* +0xa4: 50.0 from the constructor; not traced */
    float unknowna8;        /* +0xa8: 15.0 from the constructor; not traced */
    float unknownac;        /* +0xac: 10.0 from the constructor; not traced */
    float unknownb0;        /* +0xb0: 25.0 from the constructor; not traced */
    Pair0057e850 unknownb4; /* +0xb4: 10.0 and 0 from the constructor; not traced */
    u8 unknownbc[0x4];
};

#endif
