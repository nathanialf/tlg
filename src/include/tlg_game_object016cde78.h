/* src/include/tlg_game_object016cde78.h: the class whose vtable is at
 * 0x16cde78 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CDE78_H
#define TLG_GAME_OBJECT016CDE78_H

#include "tlg_types.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_object05945a38.h"
#include "tlg_math.h"

/* derived names: the point Object016cde78's constructor copies to five of
 * its records (`mov rax, [0x5822b10]; mov rdx, [0x5822b18]`, stored as
 * words), and the type of the object it holds at +0x160 */
extern Float4 D_5822b10;
extern Type00503fb0 *D_5822338;

/* derived names: the class whose vtable is at 0x16cde78
 * (config/vtables.derived.base.txt, stored by its creator FUN_009a5af0,
 * leaf_009a5af0.cpp, and its destructor FUN_01383cb0), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x170 bytes: from the constructor: an empty Name at +0x24, 0.5
 * at +0x28, zeros from +0x2c to +0x44, six records of a point and a word
 * from +0x50, 0x20 bytes apart (the point a copy of the one at 0x5822b10
 * but in the fifth, which is zero), (0, 1, 0, 1) and 0 from +0x100, zeros
 * from +0x120 to +0x13c, 10, 0, 0.1, 0, -0.03, 0, 0.05 and 0 from +0x13c,
 * then a counted reference another thread may replace at +0x160, set in
 * the body to an object of the type at 0x5822338 the registry makes, and
 * 0 at +0x168. The destructor is written in the class: it empties the
 * reference first; the complete one, FUN_01383ca0, is a jump to the
 * base-object one, FUN_01383cb0 (the reference emptied, then released with
 * the members, the Name, then the root's destructor in line), and the
 * deleting one, FUN_01383ea0, calls it (cost 485 at the unit stage, over
 * the 225 of a body written in the class). The class has no key function,
 * so the creator's unit emits the vtable with them. */
class Object016cde78 : public Object016b9108 /* derived name */
{
  public:
    Object016cde78(const Name &name)
        : Object016b9108(name), unknown28(0.5f), unknown2c(), unknown50(D_5822b10), unknown60(0),
          unknown70(D_5822b10), unknown80(0), unknown90(D_5822b10), unknowna0(0),
          unknownb0(D_5822b10), unknownc0(0), unknownd0(0.0f, 0.0f, 0.0f, 0.0f), unknowne0(0),
          unknownf0(D_5822b10), unknown100(0), unknown104(1.0f), unknown108(0.0f), unknown10c(1.0f),
          unknown110(0), unknown120(), unknown13c(10.0f), unknown140(0), unknown144(0.1f),
          unknown148(0), unknown14c(-0.03f), unknown150(0), unknown154(0.05f), unknown158(0),
          unknown168(0)
    {
        unknown160.set(D_5945a38->object(Name(), D_5822338));
    }

    /* the reference at +0x160 emptied by compare-and-swap before the
     * members are destroyed (`lock cmpxchg qword [r15], rcx` with rcx 0 at
     * 0x1383ce6) */
    virtual ~Object016cde78()
    {
        unknown160.clear();
    }

  private:
    Name name24;      /* +0x24 */
    float unknown28;  /* +0x28: 0.5 from the constructor */
    int unknown2c[6]; /* +0x2c: zeros from the constructor; not traced */
    u8 unknown44[0xc];
    Float4 unknown50; /* +0x50: a copy of D_5822b10 */
    int unknown60;    /* +0x60: 0 from the constructor */
    u8 unknown64[0xc];
    Float4 unknown70; /* +0x70: a copy of D_5822b10 */
    int unknown80;    /* +0x80: 0 from the constructor */
    u8 unknown84[0xc];
    Float4 unknown90; /* +0x90: a copy of D_5822b10 */
    int unknowna0;    /* +0xa0: 0 from the constructor */
    u8 unknowna4[0xc];
    Float4 unknownb0; /* +0xb0: a copy of D_5822b10 */
    int unknownc0;    /* +0xc0: 0 from the constructor */
    u8 unknownc4[0xc];
    Float4 unknownd0; /* +0xd0: zero from the constructor */
    int unknowne0;    /* +0xe0: 0 from the constructor */
    u8 unknowne4[0xc];
    Float4 unknownf0; /* +0xf0: a copy of D_5822b10 */
    int unknown100;   /* +0x100: 0 from the constructor */
    float unknown104; /* +0x104: 1 from the constructor */
    float unknown108; /* +0x108: 0 from the constructor */
    float unknown10c; /* +0x10c: 1 from the constructor */
    int unknown110;   /* +0x110: 0 from the constructor */
    u8 unknown114[0xc];
    int unknown120[7]; /* +0x120: zeros from the constructor; not traced */
    float unknown13c;  /* +0x13c: 10 from the constructor */
    int unknown140;    /* +0x140: 0 from the constructor */
    float unknown144;  /* +0x144: 0.1 from the constructor */
    int unknown148;    /* +0x148: 0 from the constructor */
    float unknown14c;  /* +0x14c: -0.03 from the constructor */
    int unknown150;    /* +0x150: 0 from the constructor */
    float unknown154;  /* +0x154: 0.05 from the constructor */
    int unknown158;    /* +0x158: 0 from the constructor */
    u8 unknown15c[0x4];
    AtomicRef0045c470<Object016b9108> unknown160; /* +0x160 */
    int unknown168;                               /* +0x168: 0 from the constructor */
    u8 unknown16c[0x4];
};

#endif
