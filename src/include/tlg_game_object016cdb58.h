/* src/include/tlg_game_object016cdb58.h: the class whose vtable is at
 * 0x16cdb58 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CDB58_H
#define TLG_GAME_OBJECT016CDB58_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cdb58
 * (config/vtables.derived.base.txt, stored by FUN_009b5290 FUN_01386600
 * FUN_013866a0), derived from Object016b9108. 0x60 bytes (`mov edi,
 * 0x60` before operator new in the creator). Its own fields are traced
 * where its creator FUN_009b5290 sets them and its destructor FUN_01386600
 * tears them down.
 * The destructor is implicit: FUN_01386600 and the deleting
 * FUN_013866a0 sit in the stretch of inline functions (from 0x1340000)
 * while the constructor is out of line, so the class has no key function
 * and the unit that constructs it (leaf_009b5290.cpp) emits the vtable
 * with both. */
class Object016cdb58 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the two arrays, each
     * cleared (`vmovdqu [r15+0x28], xmm0`, `vmovdqu [r15+0x40], xmm0`) with its
     * owner index from the thread's heap and its lock, `mov dword [r15+0x58],
     * 0` */
    Object016cdb58(const Name &name) : Object016b9108(name), unknown58(0) {}

  private:
    u8 unknown24[0x4];
    Array01343a80<Ref00503fb0<Object016b9108>> record28; /* +0x28: an array of counted references */
    Array01343a80<Ref00503fb0<Object016b9108>> record40; /* +0x40: an array of counted references */
    int unknown58; /* +0x58: zero from the constructor; not traced */
    u8 unknown5c[0x4];
};

#endif
