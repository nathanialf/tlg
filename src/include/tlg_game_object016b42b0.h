/* src/include/tlg_game_object016b42b0.h: the class whose vtable is at
 * 0x16b42b0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B42B0_H
#define TLG_GAME_OBJECT016B42B0_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_base016b4340.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b42b0
 * (config/vtables.derived.base.txt, stored by FUN_00af0df0 FUN_00af0fa0
 * FUN_00af1040), derived from Base016b4340. 0x50 bytes (`mov edi,
 * 0x50` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00af0df0 sets them and its destructor FUN_00af0fa0
 * tears them down. The destructor is the class's key function
 * (leaf_00af0fa0.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b42b0 : public Base016b4340 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array cleared
     * (`vmovdqu [r15+0x30], xmm0`), its owner index from the thread's heap and
     * its lock, then the body's kind 0x58, 0 at +0x2c and 1.0 at +0x48 */
    Object016b42b0(const Name &name) : Base016b4340(name)
    {
        kind = 0x58;
        unknown2c = 0;
        unknown48 = 1.0f;
    }

    virtual ~Object016b42b0();

  private:
    int unknown2c; /* +0x2c: zero from the constructor; not traced */
    Array01343a80<Ref00503fb0<Object016b9108>> record30; /* +0x30: an array of counted references */
    float unknown48; /* +0x48: 1.0 from the constructor; not traced */
    u8 unknown4c[0x4];
};

#endif
