/* src/include/tlg_game_object016cedb0.h: the class whose vtable is at
 * 0x16cedb0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CEDB0_H
#define TLG_GAME_OBJECT016CEDB0_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cedb0
 * (config/vtables.derived.base.txt, stored by its creator FUN_00b1fbe0,
 * leaf_00b1fbe0.cpp, and its destructor FUN_01392a50), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x88 bytes: from the constructor: 3, 0.27, 0.7 and 2 from +0x24,
 * 0 at +0x34 and +0x38, an empty counted reference at +0x40, 1.2, -0.4,
 * 0.6, -1.4, -0.38 and 0.4 from +0x48, an empty counted reference at
 * +0x60, 0.8, 0.5, 0.7, 0.1 and 0 from +0x68, 0 at +0x7c, 0.065104157 and
 * 0.15 at +0x80. The destructor is written in the class: the complete
 * one, FUN_01392a20, is a jump to the base-object one, FUN_01392a50 (the
 * references released last to first, then the root's destructor in line),
 * and the deleting one, FUN_01392a30, calls it. Its cost is 315: under
 * the implicit destructor's limit of 325 (the inline hint), over the 225
 * of a body written in the class, which carries no hint. The class has no
 * key function, so the creator's unit emits the vtable with them. */
class Object016cedb0 : public Object016b9108 /* derived name */
{
  public:
    Object016cedb0(const Name &name)
        : Object016b9108(name), unknown24(3.0f), unknown28(0.27f), unknown2c(0.7f), unknown30(2.0f),
          unknown34(0), unknown38(0), unknown48(1.2f), unknown4c(-0.4f), unknown50(0.6f),
          unknown54(-1.4f), unknown58(-0.38f), unknown5c(0.4f), unknown68(0.8f), unknown6c(0.5f),
          unknown70(0.7f), unknown74(0.1f), unknown78(0.0f), unknown7c(0), unknown80(0.065104157f),
          unknown84(0.15f)
    {
    }

    virtual ~Object016cedb0() {}

  private:
    float unknown24; /* +0x24: 3 from the constructor */
    float unknown28; /* +0x28: 0.27 from the constructor */
    float unknown2c; /* +0x2c: 0.7 from the constructor */
    float unknown30; /* +0x30: 2 from the constructor */
    int unknown34;   /* +0x34: 0 from the constructor */
    int unknown38;   /* +0x38: 0 from the constructor */
    u8 unknown3c[0x4];
    Ref00503fb0<Object016b9108> unknown40; /* +0x40 */
    float unknown48;                       /* +0x48: 1.2 from the constructor */
    float unknown4c;                       /* +0x4c: -0.4 from the constructor */
    float unknown50;                       /* +0x50: 0.6 from the constructor */
    float unknown54;                       /* +0x54: -1.4 from the constructor */
    float unknown58;                       /* +0x58: -0.38 from the constructor */
    float unknown5c;                       /* +0x5c: 0.4 from the constructor */
    Ref00503fb0<Object016b9108> unknown60; /* +0x60 */
    float unknown68;                       /* +0x68: 0.8 from the constructor */
    float unknown6c;                       /* +0x6c: 0.5 from the constructor */
    float unknown70;                       /* +0x70: 0.7 from the constructor */
    float unknown74;                       /* +0x74: 0.1 from the constructor */
    float unknown78;                       /* +0x78: 0 from the constructor */
    int unknown7c;                         /* +0x7c: 0 from the constructor */
    float unknown80;                       /* +0x80: 0.065104157 from the constructor */
    float unknown84;                       /* +0x84: 0.15 from the constructor */
};

#endif
