/* src/include/tlg_game_object016d2280.h: the class whose vtable is at
 * 0x16d2280 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016D2280_H
#define TLG_GAME_OBJECT016D2280_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_math.h"

/* derived names: the class whose vtable is at 0x16d2280
 * (config/vtables.derived.base.txt, stored by its creator FUN_00d45e30,
 * leaf_00d45e30.cpp, and its destructor FUN_013b8b60), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x70 bytes: 0 at +0x24, an empty Name at +0x28, two points (0,
 * 0, 0, 1) at +0x30 and +0x40 (one 32-byte store), ones at +0x50 and two
 * empty counted references at +0x60 and +0x68, all from the constructor.
 * The destructor is implicit: the complete one, FUN_013b8b30, is a jump
 * to the base-object one, FUN_013b8b60 (the references and the Name
 * released last to first, then the root's destructor in line), and the
 * deleting one, FUN_013b8b40, calls it: its cost is over the inline limit
 * of 325 (the inline hint). The class has no key function, so the
 * creator's unit emits the vtable with them. */
class Object016d2280 : public Object016b9108 /* derived name */
{
  public:
    Object016d2280(const Name &name)
        : Object016b9108(name), unknown24(0), unknown30(0.0f, 0.0f, 0.0f, 1.0f),
          unknown40(0.0f, 0.0f, 0.0f, 1.0f), unknown50(1.0f, 1.0f, 1.0f, 1.0f)
    {
    }

  private:
    int unknown24; /* +0x24: 0 from the constructor */
    Name name28;   /* +0x28 */
    u8 unknown2c[0x4];
    Float4 unknown30;                      /* +0x30: (0, 0, 0, 1) from the constructor */
    Float4 unknown40;                      /* +0x40: (0, 0, 0, 1) from the constructor */
    Float4 unknown50;                      /* +0x50: ones from the constructor */
    Ref00503fb0<Object016b9108> unknown60; /* +0x60 */
    Ref00503fb0<Object016b9108> unknown68; /* +0x68 */
};

#endif
