/* src/include/tlg_game_object016b0370.h: the class whose vtable is at
 * 0x16b0370 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B0370_H
#define TLG_GAME_OBJECT016B0370_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b0370
 * (config/vtables.derived.base.txt, stored by FUN_008e2730 FUN_008e28d0
 * FUN_008e29a0), derived from Object016b9108. 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_008e2730 sets them and its destructor FUN_008e28d0
 * tears them down. The destructor is the class's key function
 * (leaf_008e28d0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b0370 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword [r15+0x24], 0`
     * (the name), the array cleared (`vmovdqu [r15+0x30], xmm0`), its owner
     * index from the thread's heap and its state, then the body's `mov qword
     * [r15+0x28], 0` */
    Object016b0370(const Name &name) : Object016b9108(name)
    {
        unknown28 = 0;
    }

    virtual ~Object016b0370();

  private:
    Name name24;     /* +0x24: empty from the constructor, released by the destructor */
    void *unknown28; /* +0x28: null from the constructor's body; not traced */
    Array01343a80<Ref00503fb0<Object016b9108>> record30; /* +0x30: an array of counted references */
};

#endif
