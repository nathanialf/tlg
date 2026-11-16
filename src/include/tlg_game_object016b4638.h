/* src/include/tlg_game_object016b4638.h: the class whose vtable is at
 * 0x16b4638 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B4638_H
#define TLG_GAME_OBJECT016B4638_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_base016b4560.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b4638
 * (config/vtables.derived.base.txt, stored by FUN_00af9bb0 FUN_00af9d50
 * FUN_00af9df0), derived from Base016b4560. 0x50 bytes (`mov edi,
 * 0x50` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00af9bb0 sets them and its destructor FUN_00af9d50
 * tears them down. The destructor is the class's key function
 * (leaf_00af9d50.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b4638 : public Base016b4560 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array cleared
     * (`vmovdqu [r15+0x30], xmm0`), its owner index from the thread's heap and
     * its state, then the body's `mov qword [r15+0x24], 0x5b` (the kind and the
     * int after it) and `mov dword [r15+0x48], 0` */
    Object016b4638(const Name &name) : Base016b4560(name)
    {
        kind = 0x5b;
        unknown28 = 0;
        unknown48 = 0;
    }

    virtual ~Object016b4638();
    virtual void slot5(); /* derived name; FUN_001af750, not traced */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    int unknown28; /* +0x28: zero from the constructor; not traced */
    u8 unknown2c[0x4];
    Array01343a80<Ref00503fb0<Object016b9108>> record30; /* +0x30: an array of counted references */
    int unknown48; /* +0x48: zero from the constructor; not traced */
    u8 unknown4c[0x4];
};

#endif
