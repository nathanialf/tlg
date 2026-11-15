/* src/include/tlg_game_object016bda38.h: the class whose vtable is at
 * 0x16bda38 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BDA38_H
#define TLG_GAME_OBJECT016BDA38_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: the record the pointer at 0x5938c40 holds, and the record
 * at its +0x38, whose object at +0x30 the constructor below takes. */
struct Member05938c40_38 {
    u8 unknown0[0x30];
    Node00503fb0 *unknown30;
};

struct Object05938c40 {
    u8 unknown0[0x38];
    Member05938c40_38 *unknown38;
};

extern Object05938c40 *D_5938c40;
#include "tlg_game_object00c55550.h"

/* derived names: the class whose vtable is at 0x16bda38
 * (config/vtables.derived.base.txt, stored by FUN_00e5a170 FUN_00e5a350), derived from
 * Object00c55550 (the class whose destructor is 0xc55550): the base's slots and fields are not traced,
 * so the bytes below the first member here are the base's or this class's.
 * Its own fields are traced only where its destructor FUN_00e5a350 tears them
 * down (the counted references at +0x260, +0x258, +0x250), the others where its
 * creator FUN_00e5a170 sets them. 0x2c0 bytes (`mov edi, 0x2c0` before
 * operator new). */
class Object016bda38 : public Object00c55550 /* derived name */
{
  public:
    /* inlined in the creator FUN_00e5a170: the base built from the name, the
     * vptr, the four ints at +0x238 from one constant (0, 1, 0, 64), 64 at
     * +0x248, the reference at +0x258 holding the object the global record's
     * member at +0x38 holds at +0x30 (`mov rax, [rcx+0x38]; mov rcx,
     * [rax+0x30]`, the count raised), the pointer at +0x2a0 cleared; then
     * the body: bits 0 and 3 set in the int at +0x238 (`or eax, 9`), then
     * the four pointers from +0x280 cleared (one 32-byte store after the
     * int's) */
    Object016bda38(const Name &name)
        : Object00c55550(name), unknown238(0), unknown23c(1), unknown240(0), unknown244(64),
          unknown248(64), held258(D_5938c40->unknown38->unknown30), unknown2a0(0)
    {
        unknown238 |= 9;
        unknown280 = 0;
        unknown288 = 0;
        unknown290 = 0;
        unknown298 = 0;
    }

    virtual ~Object016bda38();

  private:
    u8 unknown8[0x230];
    int unknown238; /* +0x238: zero from the constructor, then bits 0 and 3 set; not traced */
    int unknown23c; /* +0x23c: 1 from the constructor; not traced */
    int unknown240; /* +0x240: zero from the constructor; not traced */
    int unknown244; /* +0x244: 64 from the constructor; not traced */
    int unknown248; /* +0x248: 64 from the constructor; not traced */
    u8 unknown24c[0x4];
    /* +0x250: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held250;
    /* +0x258: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held258;
    /* +0x260: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Node00503fb0> held260;
    u8 unknown268[0x18];
    void *unknown280; /* +0x280: null from the constructor's body; not traced */
    void *unknown288; /* +0x288: null from the constructor's body; not traced */
    void *unknown290; /* +0x290: null from the constructor's body; not traced */
    void *unknown298; /* +0x298: null from the constructor's body; not traced */
    void *unknown2a0; /* +0x2a0: null from the constructor; not traced */
    u8 unknown2a8[0x18];
};

#endif
