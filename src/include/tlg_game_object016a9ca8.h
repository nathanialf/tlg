/* src/include/tlg_game_object016a9ca8.h: the class whose vtable is at
 * 0x16a9ca8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9CA8_H
#define TLG_GAME_OBJECT016A9CA8_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9ca8
 * (config/vtables.derived.base.txt, stored by FUN_00471e10 FUN_00471fd0
 * FUN_00472110), derived from Object016b9108. 0x58 bytes (`mov edi,
 * 0x58` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00471e10 sets them and its destructor FUN_00471fd0
 * tears them down. The destructor is the class's key function
 * (leaf_00471fd0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016a9ca8 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 20 bytes from +0x24
     * cleared (`vmovdqu [r15+0x24], xmm0; mov dword [r15+0x34], 0`: the name
     * and the first array's block, count and capacity, a run of zero stores
     * made one memset), the second array (`vmovdqu [r15+0x40], xmm0`), each
     * array with its owner index from the thread's heap and its lock */
    Object016a9ca8(const Name &name) : Object016b9108(name) {}

    virtual ~Object016a9ca8();

  private:
    Name name24; /* +0x24: empty from the constructor, released by the destructor */
    /* +0x28: an array whose elements need no destructor: the destructor
     * only releases its block (`mov rax, [rbx+0x28]; ... cmp ecx, 0xa`) */
    Array01343a80<u32> array28;
    /* +0x40: an array whose elements need no destructor: the destructor
     * only releases its block (`mov rax, [rbx+0x40]; ... cmp ecx, 0xa`) */
    Array01343a80<u32> array40;
};

#endif
