/* src/include/tlg_game_object016cc130.h: the class whose vtable is at
 * 0x16cc130 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CC130_H
#define TLG_GAME_OBJECT016CC130_H

#include "tlg_types.h"
#include "tlg_game_array.h"
#include "tlg_game_array01343a80.h"
#include "tlg_math.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cc130
 * (config/vtables.derived.base.txt, stored by its creators), derived from
 * Object016b9108: its slots 2 to 4 are the base's; slot 5 is a virtual of
 * its own (0x42d0 here, a body the classes below replace: FUN_0086bb20,
 * FUN_0086ec00, FUN_00b0ec20), not declared yet. Its constructor is inlined
 * in the creators of the classes below (0x86ba2d, 0x86ea5d, 0xb0eb4d): the
 * vptr, 0 at +0x24 and the block and count of the first array in one
 * 16-byte store, then that array's capacity, owner and lock, then the
 * second array. The complete destructor, FUN_01370c30 (slot 0 of 0x16cc130
 * and of 0x16b4ca0: the Names released and their block, then the
 * references' destructor FUN_0134f620 out of line, then the root's
 * destructor inlined), is tail-called by the destructors of Object016b4c60
 * and Object016af138 below; the deleting one, FUN_01370d70, holds the same
 * body. Slots 0 and 1 of the vtable at 0x16b4ca0 (stored by FUN_00b0eda0,
 * a class derived from this one with no destructor work of its own) are
 * these same two bodies.
 *
 * OPEN, the destructors of the four classes of this header. They sit in
 * the stretch of inline functions (from 0x1340000) and their classes are
 * made elsewhere, so they read as implicit destructors, which carry the
 * inline hint (limit 325): measured over the whole module in round 476D,
 * with none of the four declared, FUN_01370d70, FUN_01371c30 (it holds
 * Object016af138's body and this class's, where its complete destructor
 * calls this class's: the unit's inliner puts off the inline into a
 * caller that is itself inline), FUN_01371ea0 and FUN_01372010 are equal,
 * and FUN_01371b50 is lost: the link stage then inlines this class's
 * destructor (cost 290, hinted) into it, where the base keeps the tail
 * call. With the link's limit for a hinted callee at its plain limit
 * (175) the whole module changes in three symbols and all five are equal.
 * That is a decision about the link stage, not about this header, so the
 * destructors stay declared here, each a key function (leaf_01370c30.cpp,
 * leaf_0138fd60.cpp), until it is taken. */
class Object016cc130 : public Object016b9108 /* derived name */
{
  public:
    Object016cc130(const Name &name) : Object016b9108(name), unknown24(0) {}

    virtual ~Object016cc130();

  private:
    int unknown24;                                           /* +0x24: 0 from the constructor */
    Array01343a80<Ref00503fb0<Object016b9108>> references28; /* +0x28 */
    Array01343a80<Name> names40;                             /* +0x40 */
};

/* derived names: the class whose vtable is at 0x16b4c60
 * (config/vtables.derived.base.txt, stored by its creator FUN_00b0ea40,
 * leaf_00b0ea40.cpp): 0x80 bytes, five counted references from +0x58,
 * null from the constructor (one 32-byte store and a quad), released last
 * to first by its complete destructor FUN_0138fd60, which ends in a tail
 * call of the base's, FUN_01370c30; FUN_0138fe30 is the deleting one,
 * which holds both bodies. Slot 5, FUN_00b0ec20, is its own and not
 * written: the function that follows the creator. */
class Object016b4c60 : public Object016cc130 /* derived name */
{
  public:
    Object016b4c60(const Name &name) : Object016cc130(name) {}

    virtual ~Object016b4c60();

  private:
    Ref00503fb0<Object016b9108> unknown58[5]; /* +0x58 */
};

/* derived names: the class whose vtable is at 0x16af138
 * (config/vtables.derived.base.txt, stored by its creator FUN_0086b920,
 * leaf_0086b920.cpp): 0xa0 bytes. Three ints from +0x58 (the second a set
 * of flags: FUN_0086bb20 tests its bits 1 and 5), a counted reference at
 * +0x68 and a Name at +0x70, then two points at +0x80 and +0x90, each (0,
 * 0, 0, 1) from the constructor (one 16-byte constant stored twice,
 * unaligned). The complete destructor, FUN_01371b50, releases the Name,
 * then the reference, and ends in a tail call of the base's, FUN_01370c30;
 * the deleting one, FUN_01371c30, holds both bodies. Slot 5, FUN_0086bb20
 * (8,201 bytes), is its own and not written: the function that follows
 * the creator. */
class Object016af138 : public Object016cc130 /* derived name */
{
  public:
    Object016af138(const Name &name)
        : Object016cc130(name), unknown58(0), flags5c(0), unknown60(0),
          unknown80(FLOAT4_POINT_ORIGIN), unknown90(FLOAT4_POINT_ORIGIN)
    {
    }

    virtual ~Object016af138();

  private:
    int unknown58; /* +0x58: 0 from the constructor; FUN_0086bb20 compares it with 2 */
    int flags5c;   /* +0x5c: 0 from the constructor */
    int unknown60; /* +0x60: 0 from the constructor */
    u8 unknown64[0x4];
    Ref00503fb0<Object016b9108> unknown68; /* +0x68 */
    Name name70;                           /* +0x70 */
    u8 unknown74[0xc];
    Float4 unknown80; /* +0x80 */
    Float4 unknown90; /* +0x90 */
};

/* derived names: the class whose vtable is at 0x16af178
 * (config/vtables.derived.base.txt, stored by its creator FUN_0086e950,
 * leaf_0086e950.cpp): 0xd0 bytes. 0 at +0x58 and -1 at +0x5c, an array
 * of three locked arrays of counted references at +0x60 (its destructor
 * forms the first one's address before it destroys the last: `lea r14,
 * [r15+0x60]` at 0x1371ebf, ahead of the first call), four
 * floats 0 at +0xa8, four floats -1 at +0xb8 (one unaligned 16-byte store
 * each) and 0 at +0xc8, all from the constructor. The complete
 * destructor, FUN_01371ea0, runs the arrays' destructor FUN_0134f620 last
 * first, then holds the base's; FUN_01372010 is the deleting one, a call
 * of it. Slot 5, FUN_0086ec00 (10,350 bytes), is its own and not written:
 * the function that follows the creator. */
class Object016af178 : public Object016cc130 /* derived name */
{
  public:
    Object016af178(const Name &name)
        : Object016cc130(name), unknown58(0), unknown5c(-1), unknownA8(0.0f, 0.0f, 0.0f, 0.0f),
          unknownB8(-1.0f, -1.0f, -1.0f, -1.0f), unknownC8(0)
    {
    }

    virtual ~Object016af178();

  private:
    int unknown58;                                              /* +0x58: 0 from the constructor */
    int unknown5c;                                              /* +0x5c: -1 from the constructor */
    Array01343a80<Ref00503fb0<Object016b9108>> references60[3]; /* +0x60, +0x78, +0x90 */
    Float4 unknownA8;                                           /* +0xa8 */
    Float4 unknownB8;                                           /* +0xb8 */
    int unknownC8;                                              /* +0xc8: 0 from the constructor */
    u8 unknownCc[0x4];
};

#endif
