/* src/include/tlg_game_object016cdd50.h: the class whose vtable is at
 * 0x16cdd50 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CDD50_H
#define TLG_GAME_OBJECT016CDD50_H

#include "tlg_game_node.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cdd50
 * (config/vtables.derived.base.txt, stored by FUN_009bb920 FUN_01384540
 * FUN_01384660), derived from Object016b9108. 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_009bb920 sets them and its destructor FUN_01384540
 * tears them down.
 * The destructor is implicit: FUN_01384540 and the deleting
 * FUN_01384660 sit in the stretch of inline functions (from 0x1340000)
 * while the constructor is out of line, so the class has no key function
 * and the unit that constructs it (leaf_009bb920.cpp) emits the vtable
 * with both. */
class Object016cdd50 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array cleared
     * (`vmovdqu [r15+0x28], xmm0`), its owner index from the thread's heap and
     * its state, `mov qword [r15+0x40], 0` */
    Object016cdd50(const Name &name) : Object016b9108(name) {}

  private:
    Array01343a80<Ref00503fb0<Object016b9108>> record28; /* +0x28: an array of counted references */
    /* +0x40: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held40;
};

#endif
