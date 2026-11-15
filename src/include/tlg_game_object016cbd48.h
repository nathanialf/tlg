/* src/include/tlg_game_object016cbd48.h: the class whose vtable is at
 * 0x16cbd48 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CBD48_H
#define TLG_GAME_OBJECT016CBD48_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cbd48
 * (config/vtables.derived.base.txt, stored by FUN_007ae430 FUN_0136d320
 * FUN_0136d3f0), derived from Object016b9108. 0x40 bytes (`mov edi,
 * 0x40` before operator new in the creator). Its own fields are traced
 * where its creator FUN_007ae430 sets them and its destructor FUN_0136d320
 * tears them down. The destructor is the class's key function
 * (leaf_0136d320.cpp), so that unit emits the vtable: defined inline it stays a
 * function of its own that the vtable's two destructors call. */
class Object016cbd48 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the 20 bytes from +0x24
     * cleared (`vmovdqu [r15+0x24], xmm0; mov dword [r15+0x34], 0`: the name
     * and the array's block, count and capacity, a run of zero stores the
     * compiler made one memset), the array's owner index from the thread's
     * heap and its state */
    Object016cbd48(const Name &name) : Object016b9108(name) {}

    virtual ~Object016cbd48();

  private:
    Name name24; /* +0x24: empty from the constructor, released by the destructor */
    Array01343a80<Ref00503fb0<Node00503fb0>> record28; /* +0x28: an array of counted references */
};

#endif
