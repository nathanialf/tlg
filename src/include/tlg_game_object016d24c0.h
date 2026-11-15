/* src/include/tlg_game_object016d24c0.h: the class whose vtable is at
 * 0x16d24c0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D24C0_H
#define TLG_GAME_OBJECT016D24C0_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16d24c0
 * (config/vtables.derived.base.txt, stored by FUN_00d63c20 FUN_013ba620
 * FUN_013ba6f0), derived from Object016b9108. 0x40 bytes (`mov edi,
 * 0x40` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00d63c20 sets them and its destructor FUN_013ba620
 * tears them down. The destructor is the class's key function
 * (leaf_013ba620.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016d24c0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 20 bytes from +0x24
     * cleared (`vmovdqu [r15+0x24], xmm0; mov dword [r15+0x34], 0`: the name
     * and the array's block, count and capacity, a run of zero stores the
     * compiler made one memset), the array's owner index from the thread's
     * heap and its state */
    Object016d24c0(const Name &name) : Object016b9108(name) {}

    virtual ~Object016d24c0();

  private:
    Name name24; /* +0x24: empty from the constructor, released by the destructor */
    Array01343a80<Ref00503fb0<Node00503fb0>> record28; /* +0x28: an array of counted references */
};

#endif
