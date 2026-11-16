/* src/include/tlg_game_object016bedd8.h: the class whose vtable is at
 * 0x16bedd8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BEDD8_H
#define TLG_GAME_OBJECT016BEDD8_H

#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x16bedd8
 * (config/vtables.derived.base.txt, stored by FUN_00f1a6c0 FUN_00f1a950),
 * derived from Object00c1b7f0. Its own fields are traced only where its
 * destructor FUN_00f1a950 and the function that enters an object of this
 * layout in its owner's array (FUN_00fc5680, 0xfc5781 to 0xfc5877) use
 * them; the rest are not traced. */
class Object016bedd8 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    /* FUN_00f1a6c0 (func_00f2b350.cpp, the unit whose VECTOR_W it reads) */
    Object016bedd8(const Name &name);

    virtual ~Object016bedd8();

  private:
    u8 unknown194
        [0x24]; /* +0x194: in the tail padding of Object013cd320; zero from the constructor; not traced */
    AtomicRef0045c470<Node00503fb0>
        owner;       /* +0x1b8: the owner, a counted reference set by compare-and-swap (0xfc5877) */
    Name name1c0;    /* +0x1c0: released by the destructor */
    bool unknown1c4; /* +0x1c4: false from the constructor; not traced */
    s64 unknown1c8;  /* +0x1c8: -1 from the constructor; not traced */
    int active1d0;   /* +0x1d0: zero from the constructor; not traced */
    int unknown1d4;  /* +0x1d4: zero from the constructor; not traced */
    Registry00f516f0 *registry; /* +0x1d8: the owner's array this object is entered in, or null */
    void *unknown1e0;           /* +0x1e0: set with the array (0xfc578f) */
    AtomicRef0045c470<Node00503fb0>
        held1e8;      /* +0x1e8: a counted reference set by compare-and-swap (0xfc57a7) */
    void *unknown1f0; /* +0x1f0: null from the constructor; not traced */
    void *unknown1f8; /* +0x1f8: null from the constructor; not traced */
};

#endif
