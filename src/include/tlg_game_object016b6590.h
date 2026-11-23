/* src/include/tlg_game_object016b6590.h: the class whose vtable is at
 * 0x16b6590 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B6590_H
#define TLG_GAME_OBJECT016B6590_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b64a0.h"

/* derived names: the class whose vtable is at 0x16b6590
 * (config/vtables.derived.base.txt, stored by FUN_00b4bda0 FUN_00b4bf60
 * FUN_00b4c130), derived from Base016b64a0. 0x80 bytes (`mov edi,
 * 0x80` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00b4bda0 sets them and its destructor FUN_00b4bf60
 * tears them down. The destructor is the class's key function
 * (leaf_00b4bf60.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b6590 : public Base016b64a0 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 40 bytes from +0x48
     * cleared (`vmovups [r15+0x48], ymm0; mov qword [r15+0x68], 0`: a pointer,
     * the two names, a pointer and the array's block, count and capacity, a
     * run of zero stores made one memset), the array's owner index from the
     * thread's heap and its state, `movabs rax, 0x3f80000000000000` at +0x78
     * (the name and 1.0); the two pointers at +0x38 are the base's, cleared
     * before the vptr store */
    Object016b6590(const Name &name)
        : Base016b64a0(name), unknown48(0), unknown4c(0), unknown58(0), unknown5c(0),
          unknown7c(1.0f)
    {
    }

    virtual ~Object016b6590();

    /* slot 8, FUN_00b4c750 (leaf_00b4bf60.cpp) */
    virtual void slot8(); /* derived name */

  private:
    int unknown48; /* +0x48: zero from the constructor; cleared by slot 8 (`mov dword`) */
    int unknown4c; /* +0x4c: zero from the constructor; not traced */
    Name name50;   /* +0x50: empty from the constructor, released by the destructor */
    Name name54;   /* +0x54: empty from the constructor, released by the destructor */
    int unknown58; /* +0x58: zero from the constructor; slot 8 tests it (`cmp dword`) */
    int unknown5c; /* +0x5c: zero from the constructor; not traced */
    Array01343a80<Name> names60; /* +0x60: an array of Names, each released by the destructor */
    Name name78;                 /* +0x78: empty from the constructor, released by the destructor */
    float unknown7c;             /* +0x7c: 1.0 from the constructor; not traced */
};

#endif
