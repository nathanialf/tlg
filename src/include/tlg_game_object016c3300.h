/* src/include/tlg_game_object016c3300.h: the class whose vtable is at
 * 0x16c3300 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C3300_H
#define TLG_GAME_OBJECT016C3300_H

#include "tlg_game_array.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_block.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x16c3300
 * (config/vtables.derived.base.txt, stored by FUN_012ae3a0 FUN_012ae670),
 * derived from Object00c1b7f0. Its fields are traced where its constructor
 * FUN_012ae3a0 and its destructor FUN_012ae670 use them: the shape of
 * FUN_00f1a950 (leaf_00f1a950.cpp) with the members at this class's
 * offsets; the array at +0x258 (with its lock: the constructor's allocator
 * index at +0x268 and free lock at +0x26c) is emptied while the int at
 * +0x1d0 is set, and its block released first of the members. 0x2a0 bytes
 * (the factory FUN_012ae240). */
class Object016c3300 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    /* FUN_012ae3a0 (func_012b3e30.cpp, the unit whose VECTOR_W it reads) */
    Object016c3300(const Name &name);

    virtual ~Object016c3300();

  private:
    u8 unknown194
        [0x24]; /* +0x194: in the tail padding of Object013cd320; zero from the constructor; not traced */
  public:
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: a counted reference */

  private:
    Name name1c0;               /* +0x1c0: released by the destructor */
    bool unknown1c4;            /* +0x1c4: false from the constructor; not traced */
    int unknown1c8;             /* +0x1c8: -1 from the constructor; not traced */
    int unknown1cc;             /* +0x1cc: -1 from the constructor; not traced */
    int active1d0;              /* +0x1d0: cleared by the destructor where it is set */
    int unknown1d4;             /* +0x1d4: zero from the constructor; not traced */
    Registry00f516f0 *registry; /* +0x1d8: the array this object is entered in, or null */
    void *unknown1e0;           /* +0x1e0: not traced */
    AtomicRef0045c470<Object016b9108> held; /* +0x1e8: a counted reference */
    void *unknown1f0;                       /* +0x1f0: null from the constructor; not traced */
    void *unknown1f8;                       /* +0x1f8: null from the constructor; not traced */
    u8 unknown200[0x58];
    Array01343a80<int>
        array258; /* +0x258: an array emptied by the destructor while the object is active */
    u8 unknown270[0x30];
};

#endif
