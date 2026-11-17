/* src/include/tlg_game_object016ba510.h: the class whose vtable is at
 * 0x16ba510 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BA510_H
#define TLG_GAME_OBJECT016BA510_H

#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"
#include "tlg_game_object05945a38.h"

/* derived name: the type of the object the constructor makes and holds at
 * +0x288 (`mov rsi, [0x5948890]` before FUN_00cbc5a0) */
extern Type00503fb0 *D_5948890;

/* derived names: the class of the object the constructor makes, with the
 * making as its own inline function: the name's temporary ends inside it,
 * so its release is gone once the call is known not to change it (the base
 * has none after the call at 0xd487db) */
struct Value00d48670 : Object016b9108 {
    static Value00d48670 *make()
    {
        return static_cast<Value00d48670 *>(FUN_00cbc5a0(D_5945a38, D_5948890, Name(), 0));
    }
};

/* derived names: the class whose vtable is at 0x16ba510
 * (config/vtables.derived.base.txt, stored by FUN_00d48670 FUN_013b8f60), derived from
 * Object016b85e0 (the class whose destructor is 0xc55550): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced where its destructor FUN_013b8f60 tears them
 * down (the counted references at +0x288, +0x260, +0x258, +0x250, +0x248,
 * +0x240) and where the creator FUN_00d48670 inlines its constructor; their
 * meaning is not traced. 0x290 bytes (the creator's `mov edi, 0x290`). */
class Object016ba510 : public Object016b85e0 /* derived name */
{
  public:
    /* inlined in the creator FUN_00d48670: the int at +0x238 and the
     * references empty, the three floats from +0x26c 0, 0 and 1.0 (the first
     * two merged into one store: three stores of one type), then
     * an object of the type at 0x5948890 made under the empty name
     * (FUN_00cbc5a0, mode 0) and held at +0x288; the two pointers at +0x278
     * are cleared after it (the body: their 16-byte store after the call) */
    Object016ba510(const Name &name)
        : Object016b85e0(name), unknown238(0), unknown26c(0.0f), unknown270(0.0f), unknown274(1.0f),
          held288(Value00d48670::make())
    {
        unknown278 = 0;
        unknown280 = 0;
    }

    virtual ~Object016ba510();

  private:
    u8 unknown8[0x230];
    int unknown238; /* +0x238: zero from the constructor; not traced */
    u8 unknown23c[0x4];
    /* +0x240: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held240;
    /* +0x248: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held248;
    /* +0x250: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held250;
    /* +0x258: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held258;
    /* +0x260: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held260;
    u8 unknown268[0x4];
    float unknown26c; /* +0x26c: zero from the constructor; not traced */
    float unknown270; /* +0x270: zero from the constructor; not traced */
    float unknown274; /* +0x274: 1.0 from the constructor; not traced */
    void *unknown278; /* +0x278: null from the constructor; not traced */
    void *unknown280; /* +0x280: null from the constructor; not traced */
    /* +0x288: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held288;
};

#endif
