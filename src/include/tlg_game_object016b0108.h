/* src/include/tlg_game_object016b0108.h: the class whose vtable is at
 * 0x16b0108 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B0108_H
#define TLG_GAME_OBJECT016B0108_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b0108
 * (config/vtables.derived.base.txt, stored by FUN_008c09f0 FUN_008c0b90
 * FUN_008c0c30), derived from Object016b9108. 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_008c09f0 sets them and its destructor FUN_008c0b90
 * tears them down. The destructor is the class's key function
 * (leaf_008c0b90.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b0108 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov dword` 0 at +0x24 and
     * +0x28, the array cleared (`vmovdqu [r15+0x30], xmm0`), its owner index
     * from the thread's heap and its lock */
    Object016b0108(const Name &name) : Object016b9108(name), unknown24(0), unknown28(0) {}

    virtual ~Object016b0108();

  private:
    int unknown24; /* +0x24: zero from the constructor; not traced */
    int unknown28; /* +0x28: zero from the constructor; not traced */
    u8 unknown2c[0x4];
    Array01343a80<Ref00503fb0<Node00503fb0>> record30; /* +0x30: an array of counted references */
};

#endif
