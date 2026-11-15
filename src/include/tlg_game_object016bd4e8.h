/* src/include/tlg_game_object016bd4e8.h: the class whose vtable is at
 * 0x16bd4e8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BD4E8_H
#define TLG_GAME_OBJECT016BD4E8_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16bd4e8
 * (config/vtables.derived.base.txt, stored by FUN_00dfe810 FUN_00dff2f0
 * FUN_00dff3c0), derived from Object016b9108. 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00dfe810 sets them and its destructor FUN_00dff2f0
 * tears them down. The destructor is the class's key function
 * (leaf_00dff2f0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016bd4e8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array cleared
     * (`vmovdqu [r15+0x28], xmm0`), its owner index from the thread's heap and
     * its state, `mov dword [r15+0x40], 0` */
    Object016bd4e8(const Name &name) : Object016b9108(name), unknown40(0) {}

    virtual ~Object016bd4e8();

  private:
    /* +0x28: an array whose elements need no destructor: the destructor
     * only releases its block (`mov rax, [rbx+0x28]; ... cmp ecx, 0xa`) */
    Array01343a80<u32> array28;
    int unknown40; /* +0x40: zero from the constructor; not traced */
};

#endif
