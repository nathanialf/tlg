/* src/include/tlg_game_object016b7cd0.h: the class whose vtable is at
 * 0x16b7cd0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B7CD0_H
#define TLG_GAME_OBJECT016B7CD0_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b7cd0
 * (config/vtables.derived.base.txt, stored by FUN_00bef8c0 FUN_00bf0180
 * FUN_00bf0290), derived from Object016b9108. 0x58 bytes (`mov edi,
 * 0x58` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00bef8c0 sets them and its destructor FUN_00bf0180
 * tears them down. The destructor is the class's key function
 * (leaf_00bf0180.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b7cd0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the two arrays, each
     * cleared (`vmovdqu [r15+0x28], xmm0`, `vmovdqu [r15+0x40], xmm0`) with its
     * owner index from the thread's heap and its lock */
    Object016b7cd0(const Name &name) : Object016b9108(name) {}

    virtual ~Object016b7cd0();

  private:
    u8 unknown24[0x4];
    /* +0x28: an array whose elements need no destructor: the destructor
     * only releases its block (`mov rax, [rbx+0x28]; ... cmp ecx, 0xa`) */
    Array01343a80<u32> array28;
    /* +0x40: an array whose elements need no destructor: the destructor
     * only releases its block (`mov rax, [rbx+0x40]; ... cmp ecx, 0xa`) */
    Array01343a80<u32> array40;
};

#endif
