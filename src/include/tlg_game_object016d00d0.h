/* src/include/tlg_game_object016d00d0.h: the class whose vtable is at
 * 0x16d00d0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D00D0_H
#define TLG_GAME_OBJECT016D00D0_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived name: the class between Object016b9108 and Object016d00d0: its
 * constructor, inlined, clears the 16 bytes at +0x28 BEFORE the derived
 * class's vptr store (`vmovdqu [r15+0x28], xmm0`, 0xb4aa9f); its own vptr
 * store is dead. Two pointers; not traced. */
class Base016d00d0 : public Object016b9108 /* derived name */
{
  public:
    Base016d00d0(const Name &name) : Object016b9108(name), unknown28(0), unknown30(0) {}

  private:
    void *unknown28; /* +0x28: null from the constructor; not traced */
    void *unknown30; /* +0x30: null from the constructor; not traced */
};

/* derived names: the class whose vtable is at 0x16d00d0
 * (config/vtables.derived.base.txt, stored by FUN_00b4a980 FUN_0139c190
 * FUN_0139c250), derived from Base016d00d0. 0x50 bytes (`mov edi,
 * 0x50` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00b4a980 sets them and its destructor FUN_0139c190
 * tears them down. The destructor is the class's key function
 * (leaf_0139c190.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016d00d0 : public Base016d00d0 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 20 bytes from +0x38
     * cleared (`vmovdqu [r15+0x38], xmm0; mov dword [r15+0x48], 0`: the name
     * and four ints, a run of zero stores made one memset), 1.0 at +0x4c;
     * the base's two pointers cleared before the vptr store */
    Object016d00d0(const Name &name)
        : Base016d00d0(name), unknown3c(0), unknown40(0), unknown44(0), unknown48(0),
          unknown4c(1.0f)
    {
    }

    virtual ~Object016d00d0();

  private:
    Name name38;     /* +0x38: empty from the constructor, released by the destructor */
    int unknown3c;   /* +0x3c: zero from the constructor; not traced */
    int unknown40;   /* +0x40: zero from the constructor; not traced */
    int unknown44;   /* +0x44: zero from the constructor; not traced */
    int unknown48;   /* +0x48: zero from the constructor; not traced */
    float unknown4c; /* +0x4c: 1.0 from the constructor; not traced */
};

#endif
