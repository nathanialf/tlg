/* src/include/tlg_game_object016b0140.h: the class whose vtable is at
 * 0x16b0140 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B0140_H
#define TLG_GAME_OBJECT016B0140_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b0140
 * (config/vtables.derived.base.txt, stored by FUN_008c0cd0 FUN_008c0e60
 * FUN_008c0fc0), derived from Object016b9108. 0x58 bytes (`mov edi,
 * 0x58` before operator new in the creator). Its own fields are traced
 * where its creator FUN_008c0cd0 sets them and its destructor FUN_008c0e60
 * tears them down. The destructor is the class's key function
 * (leaf_008c0e60.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b0140 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 32 bytes from +0x28
     * cleared in one store (`vmovups [r15+0x28], ymm0`: the reference, the
     * name, an int and the array's block, count and capacity, a run of zero
     * stores made one memset), the array's owner index from the thread's heap
     * and its state, `mov dword [r15+0x50], 0` */
    Object016b0140(const Name &name) : Object016b9108(name), unknown34(0), unknown50(0) {}

    virtual ~Object016b0140();

  private:
    /* +0x28: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Node00503fb0> held28;
    Name name30;   /* +0x30: empty from the constructor, released by the destructor */
    int unknown34; /* +0x34: zero from the constructor; not traced */
    Array01343a80<Ref00503fb0<Node00503fb0>> record38; /* +0x38: an array of counted references */
    int unknown50; /* +0x50: zero from the constructor; not traced */
};

#endif
