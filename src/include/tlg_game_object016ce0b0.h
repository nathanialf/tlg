/* src/include/tlg_game_object016ce0b0.h: the class whose vtable is at
 * 0x16ce0b0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CE0B0_H
#define TLG_GAME_OBJECT016CE0B0_H

#include <float.h>

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_math.h"

/* derived names: the class whose vtable is at 0x16ce0b0
 * (config/vtables.derived.base.txt, stored by its creator FUN_00a04b00,
 * leaf_00a04b00.cpp, and its destructor FUN_01388880), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0xe0 bytes: from the constructor: 0 at +0x24, (-1, 1, 1, -1) at
 * +0x28, ones at +0x40, the lowest and the highest point at +0x50 and
 * +0x60, a locked array of Names at +0x70, zeros at +0x88, 0 at +0x98, 1
 * at +0x9c, 0 at +0xa0 and +0xa4, 1 at +0xa8, an empty counted reference
 * at +0xb0, -1 at +0xb8 and three empty counted references from +0xc0.
 * The destructor is implicit: the complete one, FUN_01388870, is a jump
 * to the base-object one, FUN_01388880 (the references and the array of
 * Names last to first, then the root's destructor in line), and the
 * deleting one, FUN_01388bb0, calls it: its cost is over the inline limit
 * of 325 (the inline hint). The class has no key function, so the
 * creator's unit emits the vtable with them. */
class Object016ce0b0 : public Object016b9108 /* derived name */
{
  public:
    Object016ce0b0(const Name &name)
        : Object016b9108(name), unknown24(0), unknown28(-1.0f, 1.0f, 1.0f, -1.0f),
          unknown40(1.0f, 1.0f, 1.0f, 1.0f), minimum50(-FLT_MAX, -FLT_MAX, -FLT_MAX, 1.0f),
          maximum60(FLT_MAX, FLT_MAX, FLT_MAX, 1.0f), unknown88(0.0f, 0.0f, 0.0f, 0.0f),
          unknown98(0), unknown9c(1.0f), unknowna0(0), unknowna4(0), unknowna8(1), unknownb8(-1.0f)
    {
    }

  private:
    int unknown24;    /* +0x24: 0 from the constructor */
    Float4 unknown28; /* +0x28: (-1, 1, 1, -1) from the constructor */
    u8 unknown38[0x8];
    Float4 unknown40;            /* +0x40: ones from the constructor */
    Float4 minimum50;            /* +0x50: the lowest point from the constructor */
    Float4 maximum60;            /* +0x60: the highest point from the constructor */
    Array01343a80<Name> names70; /* +0x70 */
    Float4 unknown88;            /* +0x88: zeros from the constructor */
    int unknown98;               /* +0x98: 0 from the constructor */
    float unknown9c;             /* +0x9c: 1 from the constructor */
    int unknowna0;               /* +0xa0: 0 from the constructor */
    int unknowna4;               /* +0xa4: 0 from the constructor */
    int unknowna8;               /* +0xa8: 1 from the constructor */
    u8 unknownac[0x4];
    Ref00503fb0<Object016b9108> unknownb0; /* +0xb0 */
    float unknownb8;                       /* +0xb8: -1 from the constructor */
    u8 unknownbc[0x4];
    Ref00503fb0<Object016b9108> unknownc0; /* +0xc0 */
    Ref00503fb0<Object016b9108> unknownc8; /* +0xc8 */
    Ref00503fb0<Object016b9108> unknownd0; /* +0xd0 */
    u8 unknownd8[0x8];
};

#endif
