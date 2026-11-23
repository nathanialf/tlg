/* src/include/tlg_game_object016d1b90.h: the class whose vtable is at
 * 0x16d1b90 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D1B90_H
#define TLG_GAME_OBJECT016D1B90_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object00ccfd00.h"
#include "tlg_math.h"

/* derived names: the class whose vtable is at 0x16d1b90
 * (config/vtables.derived.base.txt, stored by its creator FUN_00cd3940,
 * leaf_00cd3940.cpp, and its destructor FUN_013af0a0), derived from
 * Object00ccfd00: its five slots are the two destructors and the root's
 * three. 0x110 bytes: from the constructor: the points (0, 0, 0, 1) at
 * +0x60 and +0x70, three empty counted references from +0x80, null at
 * +0xa0, 0 at +0xa8, (1, 0, 0, 1) at +0xac, 0 at +0xbc, (0, 0, 1, 0) at
 * +0xc0, (0, 1, 0, 0) at +0xd0 and at +0xe0 (an aligned 16-byte store:
 * the class is 16-byte aligned), (-90, 90, -90, 90) at +0xf0, 30 at
 * +0x100, 0 at +0x104 and 0.8 at +0x108. The destructor is implicit: the
 * complete one, FUN_013af070, is a jump to the base-object one,
 * FUN_013af0a0 (the references released last to first, then a tail call
 * of the base's destructor FUN_00ccfd00), and the deleting one,
 * FUN_013af080, calls it: its cost is over the inline limit of 325 (the
 * inline hint). The class has no key function, so the creator's unit
 * emits the vtable with them. */
class Object016d1b90 : public Object00ccfd00 /* derived name */
{
  public:
    Object016d1b90(const Name &name)
        : Object00ccfd00(name, 6), unknown60(0.0f, 0.0f, 0.0f, 1.0f),
          unknown70(0.0f, 0.0f, 0.0f, 1.0f), unknowna0(0), unknowna8(0),
          unknownac(1.0f, 0.0f, 0.0f, 1.0f), unknownbc(0), unknownc0(0.0f, 0.0f, 1.0f, 0.0f),
          unknownd0(0.0f, 1.0f, 0.0f, 0.0f), unknowne0(0.0f, 1.0f, 0.0f, 0.0f),
          unknownf0(-90.0f, 90.0f, -90.0f, 90.0f), unknown100(30.0f), unknown104(0),
          unknown108(0.8f)
    {
    }

  private:
    u8 unknown58[0x8];
    Float4 unknown60;                      /* +0x60: (0, 0, 0, 1) from the constructor */
    Float4 unknown70;                      /* +0x70: (0, 0, 0, 1) from the constructor */
    Ref00503fb0<Object016b9108> unknown80; /* +0x80 */
    Ref00503fb0<Object016b9108> unknown88; /* +0x88 */
    Ref00503fb0<Object016b9108> unknown90; /* +0x90 */
    u8 unknown98[0x8];
    void *unknowna0;   /* +0xa0: null from the constructor */
    int unknowna8;     /* +0xa8: 0 from the constructor */
    Float4 unknownac;  /* +0xac: (1, 0, 0, 1) from the constructor */
    int unknownbc;     /* +0xbc: 0 from the constructor */
    Float4 unknownc0;  /* +0xc0: (0, 0, 1, 0) from the constructor */
    Float4 unknownd0;  /* +0xd0: (0, 1, 0, 0) from the constructor */
    Float4A unknowne0; /* +0xe0: (0, 1, 0, 0) from the constructor */
    Float4 unknownf0;  /* +0xf0: (-90, 90, -90, 90) from the constructor */
    float unknown100;  /* +0x100: 30 from the constructor */
    int unknown104;    /* +0x104: 0 from the constructor */
    float unknown108;  /* +0x108: 0.8 from the constructor */
    u8 unknown10c[0x4];
};

#endif
