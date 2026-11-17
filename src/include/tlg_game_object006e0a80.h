/* src/include/tlg_game_object006e0a80.h: the class whose vtable is at
 * 0x16ac720 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT006E0A80_H
#define TLG_GAME_OBJECT006E0A80_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16ac720
 * (config/vtables.derived.base.txt, stored by its creator FUN_006e0770, where
 * its constructor is inlined after Object016b85e0's), derived from Object016b85e0. 0x250 bytes
 * (`mov edi, 0x250` before operator new in the creator). Its destructor (leaf_006e0a80.cpp, the class's key function) tears the array at +0x238 down (0x134f620). */
class Object006e0a80 : public Object016b85e0 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array
     * at +0x238 (its block, count and capacity cleared in one store, its owner
     * index from the thread's heap, its lock free) */
    Object006e0a80(const Name &name) : Object016b85e0(name) {}

    virtual ~Object006e0a80();

  private:
    u8 unknown8[0x230];
    Array01343a80<Ref00503fb0<Object016b9108>>
        record238; /* +0x238: an array of counted references */
};

#endif
