/* src/include/tlg_game_object016a9ce0.h: the class whose vtable is at
 * 0x16a9ce0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9CE0_H
#define TLG_GAME_OBJECT016A9CE0_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9ce0
 * (config/vtables.derived.base.txt, stored by FUN_00472250 FUN_004723e0
 * FUN_00472510), derived from Object016b9108. 0x40 bytes (`mov edi,
 * 0x40` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00472250 sets them and its destructor FUN_004723e0
 * tears them down. The destructor is the class's key function
 * (leaf_004723e0.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016a9ce0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array cleared
     * (`vmovdqu [r15+0x28], xmm0`), its owner index from the thread's heap and
     * its state */
    Object016a9ce0(const Name &name) : Object016b9108(name) {}

    virtual ~Object016a9ce0();

  private:
    Array01343a80<Name> names28; /* +0x28: an array of Names, each released by the destructor */
};

#endif
