/* src/include/tlg_game_object016b00d0.h: the class whose vtable is at
 * 0x16b00d0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B00D0_H
#define TLG_GAME_OBJECT016B00D0_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b00d0
 * (config/vtables.derived.base.txt, stored by FUN_008c05b0 FUN_008c0770
 * FUN_008c08b0), derived from Object016b9108. 0x58 bytes (`mov edi,
 * 0x58` before operator new in the creator). Its own fields are traced
 * where its creator FUN_008c05b0 sets them and its destructor FUN_008c0770
 * tears them down. The destructor is the class's key function
 * (leaf_008c0770.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016b00d0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, an int and the first
     * array cleared in 20 bytes (`vmovdqu [r15+0x24], xmm0; mov dword
     * [r15+0x34], 0`), the second array (`vmovdqu [r15+0x40], xmm0`), each
     * with its owner index from the thread's heap and its state */
    Object016b00d0(const Name &name) : Object016b9108(name), unknown24(0) {}

    virtual ~Object016b00d0();

  private:
    int unknown24; /* +0x24: zero from the constructor; not traced */
    Array01343a80<Ref00503fb0<Object016b9108>> record28; /* +0x28: an array of counted references */
    Array01343a80<Name> names40; /* +0x40: an array of Names, each released by the destructor */
};

#endif
