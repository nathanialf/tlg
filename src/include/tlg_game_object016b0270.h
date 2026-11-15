/* src/include/tlg_game_object016b0270.h: the class whose vtable is at
 * 0x16b0270 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B0270_H
#define TLG_GAME_OBJECT016B0270_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b0270
 * (config/vtables.derived.base.txt, stored by FUN_008c1e70 FUN_008c2000
 * FUN_008c20a0), derived from Object016b9108. 0x40 bytes (`mov edi,
 * 0x40` before operator new in the creator). Its own fields are traced
 * where its creator FUN_008c1e70 sets them and its destructor FUN_008c2000
 * tears them down. The destructor is the class's key function
 * (leaf_008c2000.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016b0270 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array cleared
     * (`vmovdqu [r15+0x28], xmm0`), its owner index from the thread's heap and
     * its state */
    Object016b0270(const Name &name) : Object016b9108(name) {}

    virtual ~Object016b0270();

  private:
    Array01343a80<Ref00503fb0<Node00503fb0>> record28; /* +0x28: an array of counted references */
};

#endif
