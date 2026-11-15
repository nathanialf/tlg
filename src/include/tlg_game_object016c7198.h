/* src/include/tlg_game_object016c7198.h: the class whose vtable is at
 * 0x16c7198 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C7198_H
#define TLG_GAME_OBJECT016C7198_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16c7198
 * (config/vtables.derived.base.txt, stored by FUN_00218cf0 FUN_01346f70
 * FUN_01347010), derived from Object016b9108. 0x40 bytes (`mov edi,
 * 0x40` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00218cf0 sets them and its destructor FUN_01346f70
 * tears them down. The destructor is the class's key function
 * (leaf_01346f70.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016c7198 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array cleared
     * (`vmovdqu [r15+0x28], xmm0`), its owner index from the thread's heap and
     * its state */
    Object016c7198(const Name &name) : Object016b9108(name) {}

    virtual ~Object016c7198();

  private:
    Array01343a80<Ref00503fb0<Node00503fb0>> record28; /* +0x28: an array of counted references */
};

#endif
