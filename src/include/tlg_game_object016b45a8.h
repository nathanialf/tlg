/* src/include/tlg_game_object016b45a8.h: the class whose vtable is at
 * 0x16b45a8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B45A8_H
#define TLG_GAME_OBJECT016B45A8_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_base016b4560.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b45a8
 * (config/vtables.derived.base.txt, stored by FUN_00af95f0 FUN_00af9790
 * FUN_00af9830), derived from Base016b4560: slots 5 and 6 are its own
 * (0x1af750 and FUN_00c1b350; declared, not traced). 0x48 bytes (`mov edi,
 * 0x48` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00af95f0 sets them and its destructor FUN_00af9790
 * tears them down. The destructor is the class's key function
 * (leaf_00af9790.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b45a8 : public Base016b4560 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array cleared
     * (`vmovdqu [r15+0x30], xmm0`), its owner index from the thread's heap and
     * its lock, then the body's `mov qword [r15+0x24], 0x5e` (the kind and the
     * int after it) */
    Object016b45a8(const Name &name) : Base016b4560(name)
    {
        kind = 0x5e;
        unknown28 = 0;
    }

    virtual ~Object016b45a8();
    virtual void slot5(Context016b4560 *context); /* derived name; FUN_001af750, not traced */
    virtual void slot6();                         /* derived name; FUN_00c1b350, not traced */

  private:
    int unknown28; /* +0x28: zero from the constructor; not traced */
    u8 unknown2c[0x4];
    Array01343a80<Ref00503fb0<Object016b9108>> record30; /* +0x30: an array of counted references */
};

#endif
