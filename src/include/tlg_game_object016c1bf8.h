/* src/include/tlg_game_object016c1bf8.h: the class whose vtable is at
 * 0x16c1bf8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C1BF8_H
#define TLG_GAME_OBJECT016C1BF8_H

#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x16c1bf8
 * (config/vtables.derived.base.txt, stored by FUN_011edd30 FUN_011edfc0),
 * derived from Object00c1b7f0. Its destructor FUN_011edfc0 is FUN_00f1a950
 * (leaf_00f1a950.cpp) instruction for instruction but for the vtable, so
 * the fields that destructor uses are Object016bedd8's, at the same
 * offsets; the rest are not traced. */
class Object016c1bf8 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    /* FUN_011edd30 (func_011f70a0.cpp, the unit whose VECTOR_W it reads) */
    Object016c1bf8(const Name &name);

    virtual ~Object016c1bf8();

  private:
    u8 unknown194
        [0x24]; /* +0x194: in the tail padding of Object013cd320; zero from the constructor; not traced */
    AtomicRef0045c470<Node00503fb0> owner; /* +0x1b8: a counted reference */
    Name name1c0;                          /* +0x1c0: released by the destructor */
    bool unknown1c4;                       /* +0x1c4: false from the constructor; not traced */
    s64 unknown1c8;                        /* +0x1c8: -1 from the constructor; not traced */
    int active1d0;                         /* +0x1d0: zero from the constructor; not traced */
    int unknown1d4;                        /* +0x1d4: zero from the constructor; not traced */
    Registry00f516f0 *registry; /* +0x1d8: the array this object is entered in, or null */
    void *unknown1e0;           /* +0x1e0: not traced */
    AtomicRef0045c470<Node00503fb0> held1e8; /* +0x1e8: a counted reference */
    void *unknown1f0;                        /* +0x1f0: null from the constructor; not traced */
    void *unknown1f8;                        /* +0x1f8: null from the constructor; not traced */
};

#endif
