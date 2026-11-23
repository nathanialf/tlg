/* src/include/tlg_game_object016cde08.h: the class whose vtable is at
 * 0x16cde08 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CDE08_H
#define TLG_GAME_OBJECT016CDE08_H

#include "tlg_types.h"
#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_math.h"

/* derived name: the point Object016cde08's constructor copies to +0xe0 and
 * +0xf0 (`mov rax, [0x5822b10]; mov rdx, [0x5822b18]`, stored as words) */
extern Float4 D_5822b10;

/* derived names: the class whose vtable is at 0x16cde08
 * (config/vtables.derived.base.txt, stored by its creator FUN_009b64b0,
 * leaf_009b64b0.cpp, and its destructor FUN_013842f0), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x1d0 bytes: from the constructor: an array of five locked
 * arrays of counted references at +0x28, a locked array of floats at +0xa0 and one of
 * Names at +0xb8, an empty Name at +0xd0, 0 and 1 at +0xd8, two copies of
 * the point at 0x5822b10 at +0xe0 and +0xf0, the floats from +0x100 to
 * +0x120, an empty Name at +0x124 and the ints and floats from +0x128 to
 * +0x1c8 read from the creator's stores; then six angles, -90 and on in
 * steps of 36, appended to the array of floats. The destructor is
 * implicit: the complete one, FUN_013842e0, is a jump to the base-object
 * one, FUN_013842f0 (the Names, the array of Names, the array of floats'
 * block, the five arrays through their destructor FUN_0134f620, then the
 * root's destructor in line), and the deleting one, FUN_01384520, calls
 * it: its cost is over the inline limit of 325 (the inline hint). The
 * class has no key function, so the creator's unit emits the vtable with
 * them. */
class Object016cde08 : public Object016b9108 /* derived name */
{
  public:
    Object016cde08(const Name &name)
        : Object016b9108(name), unknownd4(0), unknownd8(0.0f), unknowndc(1.0f),
          unknowne0(D_5822b10), unknownf0(D_5822b10), unknown100(20.0f, 5.0f, 5.0f, 1.0f),
          unknown110(1.0f, 1.0f, 1.0f, 1.0f), unknown120(3.5f), unknown128(1), unknown12c(1),
          unknown130(1), unknown134(1), unknown138(1), unknown13c(1), unknown140(0), unknown144(0),
          unknown148(0.0f), unknown14c(1.0f), unknown150(0), unknown154(0), unknown158(100.0f),
          unknown15c(135.0f), unknown160(5.0f), unknown164(0.0f), unknown168(-55.0f),
          unknown16c(55.0f), unknown170(0), unknown174(1), unknown178(6.0f, 16.0f, 0.7f, 6.0f),
          unknown188(16.0f, 0.7f, 11.0f, 11.0f), unknown1a0(1.0f, 1.0f, 1.0f, 1.0f),
          unknown1b0(1.25f), unknown1b4(1.25f), unknown1b8(1.25f, 1.0f, 0.25f, 0.5f), unknown1c8(0)
    {
        for (int i = 0; i < 6; ++i)
            anglesa0.push(i * 36.0f + -90.0f);
    }

  private:
    u8 unknown24[0x4];
    /* +0x28: one member of five arrays: the destructor forms the first's
     * address before it destroys the last (`lea r14, [r15+0x28]`) */
    Array01343a80<Ref00503fb0<Object016b9108>> references28[5];
    Array01343a80<float> anglesa0; /* +0xa0 */
    Array01343a80<Name> namesb8;   /* +0xb8 */
    Name named0;                   /* +0xd0 */
    int unknownd4;                 /* +0xd4: 0 from the constructor */
    float unknownd8;               /* +0xd8: 0 from the constructor */
    float unknowndc;               /* +0xdc: 1 from the constructor */
    Float4 unknowne0;              /* +0xe0: a copy of D_5822b10 */
    Float4 unknownf0;              /* +0xf0: a copy of D_5822b10 */
    Float4 unknown100;             /* +0x100: (20, 5, 5, 1) from the constructor */
    Float4 unknown110;             /* +0x110: ones from the constructor */
    float unknown120;              /* +0x120: 3.5 from the constructor */
    Name name124;                  /* +0x124 */
    int unknown128;                /* +0x128: 1 from the constructor */
    int unknown12c;                /* +0x12c: 1 from the constructor */
    int unknown130;                /* +0x130: 1 from the constructor */
    int unknown134;                /* +0x134: 1 from the constructor */
    int unknown138;                /* +0x138: 1 from the constructor */
    int unknown13c;                /* +0x13c: 1 from the constructor */
    int unknown140;                /* +0x140: 0 from the constructor */
    int unknown144;                /* +0x144: 0 from the constructor */
    float unknown148;              /* +0x148: 0 from the constructor */
    float unknown14c;              /* +0x14c: 1 from the constructor */
    int unknown150;                /* +0x150: 0 from the constructor */
    int unknown154;                /* +0x154: 0 from the constructor */
    float unknown158;              /* +0x158: 100 from the constructor */
    float unknown15c;              /* +0x15c: 135 from the constructor */
    float unknown160;              /* +0x160: 5 from the constructor */
    float unknown164;              /* +0x164: 0 from the constructor */
    float unknown168;              /* +0x168: -55 from the constructor */
    float unknown16c;              /* +0x16c: 55 from the constructor */
    int unknown170;                /* +0x170: 0 from the constructor */
    int unknown174;                /* +0x174: 1 from the constructor */
    Float4 unknown178;             /* +0x178: (6, 16, 0.7, 6) from the constructor */
    Float4 unknown188;             /* +0x188: (16, 0.7, 11, 11) from the constructor */
    u8 unknown198[0x8];
    Float4 unknown1a0; /* +0x1a0: ones from the constructor */
    float unknown1b0;  /* +0x1b0: 1.25 from the constructor */
    float unknown1b4;  /* +0x1b4: 1.25 from the constructor */
    Float4 unknown1b8; /* +0x1b8: (1.25, 1, 0.25, 0.5) from the constructor */
    int unknown1c8;    /* +0x1c8: 0 from the constructor */
    u8 unknown1cc[0x4];
};

#endif
