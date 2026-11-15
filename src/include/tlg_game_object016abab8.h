/* src/include/tlg_game_object016abab8.h: the class whose vtable is at
 * 0x16abab8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016ABAB8_H
#define TLG_GAME_OBJECT016ABAB8_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_base016b4340.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"

/* derived names: the class whose vtable is at 0x16abab8
 * (config/vtables.derived.base.txt, stored by FUN_005ab650 FUN_005ab880
 * FUN_005ab930), derived from Base016b4340. 0x90 bytes (`mov edi,
 * 0x90` before operator new in the creator). Its own fields are traced
 * where its creator FUN_005ab650 sets them and its destructor FUN_005ab880
 * tears them down. The destructor is the class's key function
 * (leaf_005ab880.cpp), so that unit emits the vtable and the
 * destructors. */
class Object016abab8 : public Base016b4340 /* derived name */
{
  public:
    /* inlined in the creator: the base built from the name, the vptr, the three arrays, each
     * cleared (`vmovdqu [rbx+0x30], xmm0`, +0x58, +0x78) with its owner index from
     * the thread's heap and its state, then the body's stores: the kind 0x51
     * at +0x24, 5 at +0x48, `mov dword` 0 at +0x4c, +0x50, +0x54 and +0x70
     * (separate stores: the fields are not four of one type) */
    Object016abab8(const Name &name) : Base016b4340(name)
    {
        kind = 0x51;
        unknown48 = 5;
        unknown4c = 0;
        unknown50 = 0;
        unknown54 = 0.0f;
        unknown70 = 0;
    }

    virtual ~Object016abab8();
    virtual void slot5(); /* derived name; FUN_001af750, not traced */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    u8 unknown2c[0x4];
    Array01343a80<Ref00503fb0<Node00503fb0>> record30; /* +0x30: an array of counted references */
    int unknown48;   /* +0x48: 5 from the constructor; not traced */
    int unknown4c;   /* +0x4c: zero from the constructor; not traced */
    int unknown50;   /* +0x50: zero from the constructor; not traced */
    float unknown54; /* +0x54: zero from the constructor; not traced */
    Array01343a80<Ref00503fb0<Node00503fb0>> record58; /* +0x58: an array of counted references */
    int unknown70; /* +0x70: zero from the constructor; not traced */
    u8 unknown74[0x4];
    Array01343a80<Ref00503fb0<Node00503fb0>> record78; /* +0x78: an array of counted references */
};

#endif
