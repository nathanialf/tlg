/* src/include/tlg_game_object016bfb28.h: the class whose vtable is at
 * 0x16bfb28 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016BFB28_H
#define TLG_GAME_OBJECT016BFB28_H

#include "tlg_game_array.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x16bfb28
 * (config/vtables.derived.base.txt, stored by FUN_00f6f220 FUN_00f6f510),
 * derived from Object00c1b7f0. Its fields are traced where its constructor
 * FUN_00f6f220 and its destructor FUN_00f6f510 use them: the shape of
 * FUN_00f1a950 (leaf_00f1a950.cpp) with the members at this class's
 * offsets; an array with its lock at +0x1c0 (the constructor's allocator
 * index at +0x1d0 and free lock at +0x1d4; its block released by the
 * destructor after the Name). 0x240 bytes (the creator FUN_00f6f0c0). */
class Object016bfb28 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    /* FUN_00f6f220 (func_00f70b00.cpp, the unit whose VECTOR_W it reads) */
    Object016bfb28(const Name &name);

    virtual ~Object016bfb28();

  private:
    u8 unknown194
        [0x24]; /* +0x194: in the tail padding of Object013cd320; zero from the constructor; not traced */
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: a counted reference */
    Array01343a80<u8> array1c0;              /* +0x1c0: the elements not traced */
    int unknown1d8;                          /* +0x1d8: zero from the constructor; not traced */
    int unknown1dc;                          /* +0x1dc: 1 from the constructor; not traced */
    float unknown1e0;                        /* +0x1e0: 1.0 from the constructor; not traced */
    Name name1e4;                            /* +0x1e4: released by the destructor */
    bool unknown1e8;                         /* +0x1e8: false from the constructor; not traced */
    int unknown1ec;                          /* +0x1ec: -1 from the constructor; not traced */
    int unknown1f0;                          /* +0x1f0: -1 from the constructor; not traced */
    int active1f4;                           /* +0x1f4: cleared by the destructor where it is set */
    int unknown1f8;                          /* +0x1f8: zero from the constructor; not traced */
    Registry00f516f0 *registry; /* +0x200: the array this object is entered in, or null */
    void *unknown208;           /* +0x208: not traced */
    AtomicRef0045c470<Object016b9108> held; /* +0x210: a counted reference */
    void *unknown218;                       /* +0x218: null from the constructor; not traced */
    void *unknown220;                       /* +0x220: null from the constructor; not traced */
    u8 unknown228[0x18];
};

#endif
