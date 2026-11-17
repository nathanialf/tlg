/* src/include/tlg_game_object014068b0.h: the class whose constructor is
 * FUN_014068b0, its unit-local copy whose constructor is FUN_0148c070, and
 * the class over each whose slot 2 runs the base's then sets three poses'
 * vectors (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT014068B0_H
#define TLG_GAME_OBJECT014068B0_H

#include "tlg_types.h"
#include "tlg_math.h"

/* derived names: a pose of the model the object reads, 0x40 bytes, a vector
 * at +0x20 whose w the classes over the base set to 1 */
struct Pose014068b0 { /* derived name */
    u8 unknown0[0x20];
    Float4A unknown20; /* +0x20 */
    u8 unknown30[0x10];
};

struct Model014068b0 { /* derived name */
    u8 unknown0[0x140];
    Pose014068b0 *poses; /* +0x140 */
};

struct Owner014068b0 { /* derived name */
    u8 unknown0[0x8];
    Model014068b0 *model; /* +0x8 */
};

/* derived names: the pose indices the object works on (ints at +0x8, +0x14
 * and +0x18 read by the classes' slot 2) */
struct Indices014068b0 { /* derived name */
    u8 unknown0[0x8];
    int unknown8; /* +0x8 */
    u8 unknownc[0x8];
    int unknown14; /* +0x14 */
    int unknown18; /* +0x18 */
};

/* derived names: the base of the class whose vtable is at 0x16d5878
 * (FUN_01406b30, leaf_01406b30.cpp) and of the one at 0x16d5850: slot 0
 * FUN_0140b680, slot 1 FUN_01408ad0 (leaf_01408ad0.cpp), slot 2
 * FUN_01408960. The vtable's first two slots are not destructors. */
class Object014068b0 /* derived name */
{
  public:
    Object014068b0(int kind);
    virtual void slot0();        /* derived name; not traced */
    virtual void slot1();        /* derived name; not traced */
    virtual void FUN_01408960(); /* slot 2, not written */

  protected:
    u8 unknown8[0x8];
    Owner014068b0 *owner;     /* +0x10 */
    Indices014068b0 *indices; /* +0x18 */
    u8 unknown20[0x44];
};

/* derived names: the same class in another unit (vtable 0x16d7c58's base,
 * FUN_0148c2f0, leaf_0148c2f0.cpp; 0x16d7c30's): slot 2 FUN_0148d930 */
class Object0148c070 /* derived name */
{
  public:
    Object0148c070(int kind);
    virtual void slot0();        /* derived name; not traced */
    virtual void slot1();        /* derived name; not traced */
    virtual void FUN_0148d930(); /* slot 2, not written */

  protected:
    u8 unknown8[0x8];
    Owner014068b0 *owner;     /* +0x10 */
    Indices014068b0 *indices; /* +0x18 */
    u8 unknown20[0x44];
};

/* derived names: the class whose vtable is at 0x16d5850
 * (config/vtables.derived.base.txt, stored by FUN_010b0530 and
 * FUN_010b1800): three vectors at +0x70, +0x80 and +0x90, each set as the
 * vector of the pose of one of the indices (+0x8, +0x14, +0x18) with w 1
 * after the base's slot 2 has run (FUN_0140b870, the base's FUN_01408960) */
class Object016d5850 : public Object014068b0 /* derived name */
{
  public:
    void FUN_01408960(); /* slot 2 */

  private:
    u8 unknown64[0xc];
    Float4A unknown70; /* +0x70 */
    Float4A unknown80; /* +0x80 */
    Float4A unknown90; /* +0x90 */
};

/* derived names: the same over Object0148c070, vtable 0x16d7c30 (stored by
 * FUN_012bc3a0; slot 2 FUN_014904c0) */
class Object016d7c30 : public Object0148c070 /* derived name */
{
  public:
    void FUN_0148d930(); /* slot 2 */

  private:
    u8 unknown64[0xc];
    Float4A unknown70; /* +0x70 */
    Float4A unknown80; /* +0x80 */
    Float4A unknown90; /* +0x90 */
};

#endif
