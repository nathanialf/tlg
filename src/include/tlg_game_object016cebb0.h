/* src/include/tlg_game_object016cebb0.h: the class whose vtable is at
 * 0x16cebb0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CEBB0_H
#define TLG_GAME_OBJECT016CEBB0_H

#include "tlg_game_node.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cebb0
 * (config/vtables.derived.base.txt, stored by FUN_00b008e0 FUN_0138f190
 * FUN_0138f2b0), derived from Object016b9108. 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00b008e0 sets them and its destructor FUN_0138f190
 * tears them down.
 * The destructor is implicit: FUN_0138f190 and the deleting
 * FUN_0138f2b0 sit in the stretch of inline functions (from 0x1340000)
 * while the constructor is out of line, so the class has no key function
 * and the unit that constructs it (leaf_00b008e0.cpp) emits the vtable
 * with both. */
class Object016cebb0 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the reference and the
     * array cleared (`vmovdqu [r15+0x28], xmm0; mov qword [r15+0x38], 0`), the
     * array's owner index from the thread's heap and its state */
    Object016cebb0(const Name &name) : Object016b9108(name) {}

  private:
    /* +0x28: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held28;
    Array01343a80<Ref00503fb0<Object016b9108>> record30; /* +0x30: an array of counted references */
};

#endif
