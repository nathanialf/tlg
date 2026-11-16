/* src/include/tlg_game_object016b1d40.h: the class whose vtable is at
 * 0x16b1d40 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B1D40_H
#define TLG_GAME_OBJECT016B1D40_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b1d40
 * (config/vtables.derived.base.txt, stored by FUN_00a2a0f0 FUN_00a2b780
 * FUN_00a2b820), derived from Object01343880. 0x58 bytes (`mov edi,
 * 0x58` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00a2a0f0 sets them and its destructor FUN_00a2b780
 * tears them down. The destructor is the class's key function
 * (leaf_00a2b780.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b1d40 : public Object01343880 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array cleared
     * (`vmovdqu [r15+0x38], xmm0`), its owner index from the thread's heap and
     * its lock, `mov dword [r15+0x50], 0`; the base's pointer and int cleared
     * before the vptr store */
    Object016b1d40(const Name &name) : Object01343880(name), unknown50(0) {}

    virtual ~Object016b1d40();

  private:
    u8 unknown34[0x4];
    Array01343a80<Ref00503fb0<Object016b9108>> record38; /* +0x38: an array of counted references */
    int unknown50; /* +0x50: zero from the constructor; not traced */
    u8 unknown54[0x4];
};

#endif
