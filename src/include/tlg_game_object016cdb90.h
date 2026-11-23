/* src/include/tlg_game_object016cdb90.h: the class whose vtable is at
 * 0x16cdb90 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CDB90_H
#define TLG_GAME_OBJECT016CDB90_H

#include "tlg_types.h"
#include "tlg_math.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cdb90
 * (config/vtables.derived.base.txt, stored by its creator FUN_009b5450,
 * leaf_009b5450.cpp, and its destructor FUN_01386460), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x70 bytes, from the constructor: 16 bytes of zero at +0x30, ones
 * at +0x40, two empty counted references at +0x50 and +0x58 and 0 at
 * +0x60; the 12 bytes from +0x24 and the last 12 are not set there. The
 * destructor is written in the class: the complete one, FUN_01386430, is a
 * jump to the base-object one, FUN_01386460 (the references released last
 * to first, then the root's destructor in line), and the deleting one,
 * FUN_01386440, calls it. Its cost is 315: under the implicit destructor's
 * limit of 325 (the inline hint), over the 225 of a body written in the
 * class, which carries no hint. The class has no key function, so the
 * creator's unit emits the vtable with them. */
class Object016cdb90 : public Object016b9108 /* derived name */
{
  public:
    Object016cdb90(const Name &name)
        : Object016b9108(name), unknown30(0), unknown38(0), unknown40(1.0f, 1.0f, 1.0f, 1.0f),
          unknown60(0)
    {
    }

    virtual ~Object016cdb90() {}

  private:
    u8 unknown24[0xc];
    void *unknown30;                       /* +0x30: null from the constructor */
    void *unknown38;                       /* +0x38: null from the constructor */
    Float4 unknown40;                      /* +0x40: ones from the constructor */
    Ref00503fb0<Object016b9108> unknown50; /* +0x50 */
    Ref00503fb0<Object016b9108> unknown58; /* +0x58 */
    int unknown60;                         /* +0x60: 0 from the constructor */
    u8 unknown64[0xc];
};

#endif
