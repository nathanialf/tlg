/* src/include/tlg_game_object016be258.h: the class whose vtable is at
 * 0x16be258 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BE258_H
#define TLG_GAME_OBJECT016BE258_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16be258
 * (config/vtables.derived.base.txt, stored by FUN_00e94e70 FUN_00e95000
 * FUN_00e950a0), derived from Object016b9108. 0x50 bytes (`mov edi,
 * 0x50` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00e94e70 sets them and its destructor FUN_00e95000
 * tears them down. The destructor is the class's key function
 * (leaf_00e95000.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016be258 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array cleared
     * (`vmovdqu [r15+0x38], xmm0`), its owner index from the thread's heap and
     * its state, then the body's four ints from +0x24 cleared in one store
     * (`vmovdqu [r15+0x24], xmm0` after the array: assigned in the body) */
    Object016be258(const Name &name) : Object016b9108(name)
    {
        unknown24 = 0;
        unknown28 = 0;
        unknown2c = 0;
        unknown30 = 0;
    }

    virtual ~Object016be258();

  private:
    int unknown24; /* +0x24: zero from the constructor; not traced */
    int unknown28; /* +0x28: zero from the constructor; not traced */
    int unknown2c; /* +0x2c: zero from the constructor; not traced */
    int unknown30; /* +0x30: zero from the constructor; not traced */
    u8 unknown34[0x4];
    Array01343a80<Ref00503fb0<Object016b9108>> record38; /* +0x38: an array of counted references */
};

#endif
