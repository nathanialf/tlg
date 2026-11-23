/* src/include/tlg_game_object016d1e90.h: the class whose vtable is at
 * 0x16d1e90 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D1E90_H
#define TLG_GAME_OBJECT016D1E90_H

#include "tlg_game_node.h"
#include "tlg_game_object00ced570.h"

/* derived names: the class whose vtable is at 0x16d1e90
 * (config/vtables.derived.base.txt, stored by FUN_00ceea00 FUN_013b2b20
 * FUN_013b2bd0), derived from Object00ced570. 0x68 bytes (`mov edi,
 * 0x68` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00ceea00 sets them and its destructor FUN_013b2b20
 * tears them down.
 * The destructor is implicit: FUN_013b2b20 and the deleting
 * FUN_013b2bd0 sit in the stretch of inline functions (from 0x1340000)
 * while the constructor is out of line, so the class has no key function
 * and the unit that constructs it (leaf_00ceea00.cpp) emits the vtable
 * with both. */
class Object016d1e90 : public Object00ced570 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, `mov qword [r15+0x60], 0`
     * (the reference); the base's fields set before the vptr store */
    Object016d1e90(const Name &name) : Object00ced570(name) {}

  private:
    /* +0x60: a counted reference, empty from the constructor, released by
     * the destructor */
    Ref00503fb0<Object016b9108> held60;
};

#endif
