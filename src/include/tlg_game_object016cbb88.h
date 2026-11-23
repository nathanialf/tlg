/* src/include/tlg_game_object016cbb88.h: the class whose vtable is at
 * 0x16cbb88 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CBB88_H
#define TLG_GAME_OBJECT016CBB88_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cbb88
 * (config/vtables.derived.base.txt, stored by FUN_007ad7a0 FUN_0136e0a0
 * FUN_0136e170), derived from Object016b9108. 0x40 bytes (`mov edi,
 * 0x40` before operator new in the creator). Its own fields are traced
 * where its creator FUN_007ad7a0 sets them and its destructor FUN_0136e0a0
 * tears them down.
 * The destructor is implicit: FUN_0136e0a0 and the deleting
 * FUN_0136e170 sit in the stretch of inline functions (from 0x1340000)
 * while the constructor is out of line, so the class has no key function
 * and the unit that constructs it (leaf_007ad7a0.cpp) emits the vtable
 * with both. */
class Object016cbb88 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 20 bytes from +0x24
     * cleared (`vmovdqu [r15+0x24], xmm0; mov dword [r15+0x34], 0`: the name
     * and the array's block, count and capacity, a run of zero stores the
     * compiler made one memset), the array's owner index from the thread's
     * heap and its state */
    Object016cbb88(const Name &name) : Object016b9108(name) {}

  private:
    Name name24; /* +0x24: empty from the constructor, released by the destructor */
    Array01343a80<Ref00503fb0<Object016b9108>> record28; /* +0x28: an array of counted references */
};

#endif
