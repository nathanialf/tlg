/* src/include/tlg_game_object016cbe28.h: the class whose vtable is at
 * 0x16cbe28 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CBE28_H
#define TLG_GAME_OBJECT016CBE28_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cbe28
 * (config/vtables.derived.base.txt, stored by FUN_007aeac0 FUN_0136ca40
 * FUN_0136cb10), derived from Object016b9108. 0x40 bytes (`mov edi,
 * 0x40` before operator new in the creator). Its own fields are traced
 * where its creator FUN_007aeac0 sets them and its destructor FUN_0136ca40
 * tears them down.
 * The destructor is implicit: FUN_0136ca40 and the deleting
 * FUN_0136cb10 sit in the stretch of inline functions (from 0x1340000)
 * while the constructor is out of line, so the class has no key function
 * and the unit that constructs it (leaf_007aeac0.cpp) emits the vtable
 * with both. */
class Object016cbe28 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 20 bytes from +0x24
     * cleared (`vmovdqu [r15+0x24], xmm0; mov dword [r15+0x34], 0`: the name
     * and the array's block, count and capacity, a run of zero stores the
     * compiler made one memset), the array's owner index from the thread's
     * heap and its state */
    Object016cbe28(const Name &name) : Object016b9108(name) {}

  private:
    Name name24; /* +0x24: empty from the constructor, released by the destructor */
    Array01343a80<Ref00503fb0<Object016b9108>> record28; /* +0x28: an array of counted references */
};

#endif
