/* src/include/tlg_game_object016b0098.h: the class whose vtable is at
 * 0x16b0098 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B0098_H
#define TLG_GAME_OBJECT016B0098_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b0098
 * (config/vtables.derived.base.txt, stored by FUN_008c0230 FUN_008c03f0
 * FUN_008c0590), derived from Object016b9108. 0x60 bytes (`mov edi,
 * 0x60` before operator new in the creator). Its own fields are traced
 * where its creator FUN_008c0230 sets them and its destructor FUN_008c03f0
 * tears them down. The destructor is the class's key function
 * (leaf_008c03f0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b0098 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 28 bytes from +0x24
     * cleared by two 16-byte stores that overlap, the last one first (two ints,
     * the name and the first array's block, count and capacity: a run of zero
     * stores made one memset), each array's owner index from the thread's heap
     * and its state, the second array's block, count and capacity in one store */
    Object016b0098(const Name &name) : Object016b9108(name), unknown24(0), unknown28(0) {}

    virtual ~Object016b0098();

  private:
    int unknown24;               /* +0x24: zero from the constructor; not traced */
    int unknown28;               /* +0x28: zero from the constructor; not traced */
    Name name2c;                 /* +0x2c: empty from the constructor, released by the destructor */
    Array01343a80<Name> names30; /* +0x30: an array of Names, each released by the destructor */
    /* +0x48: an array whose elements need no destructor: the destructor
     * only releases its block */
    Array01343a80<u32> array48;
};

#endif
