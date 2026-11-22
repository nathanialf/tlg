/* src/include/tlg_game_object016aa0d0.h: the class whose vtable is at 0x16aa0d0 and
 * whose complete destructor is 0x4af8a0, a base of other game classes (game
 * region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016AA0D0_H
#define TLG_GAME_OBJECT016AA0D0_H

#include "tlg_game_object016b9108.h"
#include "tlg_game_node.h"
#include "tlg_math.h"
#include "tlg_game_value004af700.h"

/* derived name: the value the constructor copies to +0x50 (`mov rax,
 * [0x57d7870]; mov rcx, [0x57d7878]`) */
extern Value004af700 D_57d7870;

/* derived names: a three-float vector, the offset slot 8 adds to the
 * position at +0x40 (0.2 of it) */
struct Vec3057d78a0 { /* derived name */
    float x;
    float y;
    float z;
};

extern Vec3057d78a0 D_57d78a0;

/* derived names: the class whose vtable is at 0x16aa0d0
 * (config/vtables.derived.base.txt, stored by FUN_004af700 FUN_004af8a0 FUN_004b16e0 FUN_004b7d80), derived from
 * Object016b9108: its slots 2 to 4 are the base's, slots 5 to 11 its own (declared; their bodies
 * are not written here).
 * Its own fields are traced only where its destructor FUN_004af8a0 tears them
 * down (the counted references at +0x30, +0x28); the rest are not traced. */
class Object016aa0d0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creators (FUN_004af700, FUN_004b60b0, FUN_004b0570):
     * the base built from the name, the vptr (dead in the derived classes'),
     * the two references cleared in one store, -1 at +0x38, `mov byte
     * [r15+0x3c], 0`, the aligned 16 bytes at +0x40 cleared (`vmovdqa`), then
     * the value at 0x57d7870 copied to +0x50 in the body */
    Object016aa0d0(const Name &name)
        : Object016b9108(name), unknown38(-1), unknown3c(false), unknown40(0.0f, 0.0f, 0.0f, 0.0f)
    {
        unknown50.set(D_57d7870);
    }

    virtual ~Object016aa0d0();
    virtual void slot5(); /* derived name; FUN_004afa60, not traced */
    virtual void slot6(); /* derived name; FUN_000042d0, not traced */
    /* slot 7, FUN_004b00f0: a count of points, none here (4 in
     * Object016aa1b0, 1 in Object016aa320) */
    virtual int slot7() const; /* derived name */
    /* slot 8, FUN_004b00a0: the point of an index, here the position at
     * +0x40 moved by 0.2 of the vector at 0x57d78a0 (its w kept), whatever
     * the index; returned through the hidden pointer (Float4) */
    virtual Float4 slot8(int index) const; /* derived name */
    virtual void slot9();                  /* derived name; FUN_004aff80, not traced */
    virtual void slot10();                 /* derived name; FUN_004affa0, empty */
    virtual void slot11();                 /* derived name; FUN_004affb0, not traced */

  protected:
    u8 unknown24[0x4];
    /* +0x28: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held28;
    /* +0x30: a counted reference, released by the destructor (the pointer
     * cleared, `cmp dword [r+8], 0xdeadc0de`, the count dropped) */
    Ref00503fb0<Object016b9108> held30;
    int unknown38;           /* +0x38: -1 from the constructor; not traced */
    bool unknown3c;          /* +0x3c: false from the constructor; not traced */
    Float4A unknown40;       /* +0x40: zero from the constructor; the position slot 8 moves */
    Value004af700 unknown50; /* +0x50: the value at 0x57d7870 from the constructor; not traced */
};

#endif
