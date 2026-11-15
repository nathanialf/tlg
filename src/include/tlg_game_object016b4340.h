/* src/include/tlg_game_object016b4340.h: the class whose vtable is at
 * 0x16b4340 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B4340_H
#define TLG_GAME_OBJECT016B4340_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_base016b4340.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16b4340
 * (config/vtables.derived.base.txt, stored by FUN_00af1350 FUN_00af1500
 * FUN_00af15d0), derived from Base016b4340. 0x50 bytes (`mov edi,
 * 0x50` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00af1350 sets them and its destructor FUN_00af1500
 * tears them down. The destructor is the class's key function
 * (leaf_00af1500.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016b4340 : public Base016b4340 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the array cleared
     * (`vmovdqu [r15+0x30], xmm0`), its owner index from the thread's heap and
     * its state, `mov dword [r15+0x48], 0` (the name), then the body's kind
     * 0x57 at +0x24 and `mov dword [r15+0x2c], 0` */
    Object016b4340(const Name &name) : Base016b4340(name)
    {
        kind = 0x57;
        unknown2c = 0;
    }

    virtual ~Object016b4340();
    virtual void slot5(); /* derived name; FUN_001af750, not traced */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    int unknown2c; /* +0x2c: zero from the constructor; not traced */
    Array01343a80<Ref00503fb0<Node00503fb0>> record30; /* +0x30: an array of counted references */
    Name name48; /* +0x48: empty from the constructor, released by the destructor */
    u8 unknown4c[0x4];
};

#endif
