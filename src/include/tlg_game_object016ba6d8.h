/* src/include/tlg_game_object016ba6d8.h: the class whose vtable is at
 * 0x16ba6d8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BA6D8_H
#define TLG_GAME_OBJECT016BA6D8_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16ba6d8
 * (config/vtables.derived.base.txt, stored by FUN_00d4cdb0 FUN_00d4cf60
 * FUN_00d4d030), derived from Object01343880. 0x60 bytes (`mov edi,
 * 0x60` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00d4cdb0 sets them and its destructor FUN_00d4cf60
 * tears them down. The destructor is the class's key function
 * (leaf_00d4cf60.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016ba6d8 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword [r15+0x34], 1`,
     * the four floats at +0x38 from the constants at 0x1545f50 (1.0 four times) in one store,
     * the array cleared (`vmovups [r15+0x48], xmm0`), its owner index from the
     * thread's heap and its state */
    Object016ba6d8(const Name &name)
        : Object01343880(name), unknown34(1), unknown38(1.0f), unknown3c(1.0f), unknown40(1.0f),
          unknown44(1.0f)
    {
    }

    virtual ~Object016ba6d8();

  private:
    int unknown34;   /* +0x34: 1 from the constructor; not traced */
    float unknown38; /* +0x38: 1.0 from the constructor; not traced */
    float unknown3c; /* +0x3c: 1.0 from the constructor; not traced */
    float unknown40; /* +0x40: 1.0 from the constructor; not traced */
    float unknown44; /* +0x44: 1.0 from the constructor; not traced */
    /* +0x48: an array whose elements need no destructor: the destructor
     * only releases its block */
    Array01343a80<u32> array48;
};

#endif
