/* src/include/tlg_game_object016c1128.h: the class whose vtable is at
 * 0x16c1128 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C1128_H
#define TLG_GAME_OBJECT016C1128_H

#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"
#include "tlg_simd.h"

/* derived names: two vectors, the first zero and the second the w axis
 * from the constructor (FUN_010644d0: `vmovaps [rbx+0x250], xmm1` of the
 * cleared register, then the unit's VECTOR_W at +0x260); the constructor is
 * defined in the unit that builds them (func_01067d40.cpp), as it reads that
 * unit's VECTOR_W. Not traced further. */
struct Frame016c1128 { /* derived name */
    Frame016c1128();

    Vec4 unknown0;  /* +0x0: zero from the constructor */
    Vec4 unknown10; /* +0x10: VECTOR_W from the constructor */
};

/* derived names: 0x70 bytes, at +0x230 and +0x2a0 of the class below: a
 * pointer cleared by the constructor, two of them from +0x20 and an int
 * cleared at +0x68. */
struct Part016c1128 { /* derived name */

    Part016c1128() : unknown0(0), unknown68(0) {}

    void *unknown0; /* +0x0: null from the constructor; not traced */
    u8 unknown8[0x18];
    Frame016c1128 frames[2]; /* +0x20 */
    u8 unknown60[0x8];
    int unknown68; /* +0x68: zero from the constructor; not traced */
};

/* derived names: the class whose vtable is at 0x16c1128
 * (config/vtables.derived.base.txt, stored by FUN_010644d0 FUN_010647f0),
 * derived from Object00c1b7f0. Its destructor FUN_010647f0 is the shape of
 * FUN_00f1a950 (leaf_00f1a950.cpp) with the members after the owner eight
 * bytes further on and one more step: the array it is entered in is at
 * +0x1e0 (0x1064808), the int at +0x1d4 is cleared where it is set
 * (0x10648a3), the reference emptied is at +0x1f0 (0x10648b8) and the Name
 * released is at +0x1c4 (0x10649d9). Its other fields are traced where its
 * constructor FUN_010644d0 sets them. 0x320 bytes (the factory
 * FUN_01064370). */
class Object016c1128 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    /* FUN_010644d0 (func_01067d40.cpp, the unit whose VECTOR_W it reads) */
    Object016c1128(const Name &name);

    virtual ~Object016c1128();

  private:
    u8 unknown194
        [0x24]; /* +0x194: in the tail padding of Object013cd320; zero from the constructor; not traced */
    AtomicRef0045c470<Node00503fb0> owner; /* +0x1b8: a counted reference */
    int unknown1c0;                        /* +0x1c0: zero from the constructor; not traced */
    Name name1c4;                          /* +0x1c4: released by the destructor */
    bool unknown1c8;                       /* +0x1c8: false from the constructor; not traced */
    int unknown1cc;                        /* +0x1cc: -1 from the constructor; not traced */
    int unknown1d0;                        /* +0x1d0: -1 from the constructor; not traced */
    int active1d4;                         /* +0x1d4: cleared by the destructor where it is set */
    int unknown1d8;                        /* +0x1d8: zero from the constructor; not traced */
    Registry00f516f0 *registry; /* +0x1e0: the array this object is entered in, or null */
    void *unknown1e8;
    AtomicRef0045c470<Node00503fb0> held1f0; /* +0x1f0: a counted reference */
    void *unknown1f8;                        /* +0x1f8: null from the constructor; not traced */
    void *unknown200;                        /* +0x200: null from the constructor; not traced */
    u8 unknown208[0x28];
    Part016c1128 part230; /* +0x230 */
    Part016c1128 part2a0; /* +0x2a0 */
    u8 unknown310[0x10];
};

#endif
