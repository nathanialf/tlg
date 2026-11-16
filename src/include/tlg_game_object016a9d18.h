/* src/include/tlg_game_object016a9d18.h: the class whose vtable is at
 * 0x16a9d18 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016A9D18_H
#define TLG_GAME_OBJECT016A9D18_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a9d18
 * (config/vtables.derived.base.txt, stored by FUN_00472640 FUN_00472d70
 * FUN_00472e10), derived from Object016b9108. 0x70 bytes (`mov edi,
 * 0x70` before operator new in the creator). Its own fields are traced
 * where its creator FUN_00472640 sets them and its destructor FUN_00472d70
 * tears them down. The destructor is the class's key function
 * (leaf_00472d70.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016a9d18 : public Object016b9108 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the first array cleared
     * (`vmovdqu [r15+0x28], xmm0`) with its owner index from the thread's heap
     * and its lock, -1.0 twice and 5 from +0x40, the second array (`vmovdqu
     * [r15+0x50], xmm0`) with its owner index and lock, 0 and 3.5 at +0x68 in
     * one `movabs`, then FUN_00472830 called on the object (not inlined) */
    Object016a9d18(const Name &name)
        : Object016b9108(name), unknown40(-1.0f), unknown44(-1.0f), unknown48(5), unknown68(0.0f),
          unknown6c(3.5f)
    {
        FUN_00472830();
    }

    virtual ~Object016a9d18();

    /* FUN_00472830 (1332 bytes, not written): called on the new object by
     * its constructor; not traced */
    void FUN_00472830(); /* derived name */

  private:
    u8 unknown24[0x4];
    Array01343a80<Ref00503fb0<Object016b9108>> record28; /* +0x28: an array of counted references */
    float unknown40; /* +0x40: -1.0 from the constructor; not traced */
    float unknown44; /* +0x44: -1.0 from the constructor; not traced */
    int unknown48;   /* +0x48: 5 from the constructor; not traced */
    u8 unknown4c[0x4];
    Array01343a80<Ref00503fb0<Object016b9108>> record50; /* +0x50: an array of counted references */
    float unknown68; /* +0x68: zero from the constructor; not traced */
    float unknown6c; /* +0x6c: 3.5 from the constructor; not traced */
};

#endif
