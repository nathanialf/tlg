/* src/include/tlg_game_object016cffb0.h: the class whose vtable is at
 * 0x16cffb0 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CFFB0_H
#define TLG_GAME_OBJECT016CFFB0_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived name: the string the constructor of Object016cffb0 looks its
 * Name at +0x48 up from (`lea rbx, [0x15ad2e8]` before FUN_013bad90) */
extern const char D_15ad2e8[52];

/* derived names: the class whose vtable is at 0x16cffb0
 * (config/vtables.derived.base.txt, stored by its creator FUN_00b43190,
 * leaf_00b43190.cpp, and its destructor FUN_0139b550), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x90 bytes: from the constructor: 3 at +0x24, an empty counted
 * reference at +0x28, 100 at +0x30, 0.05, 2.9, 8, 8 and 5 from +0x34, a
 * Name at +0x48 looked up from the string at 0x15ad2e8 without adding it,
 * then two locked arrays of counted references at +0x50 and +0x70, each
 * followed by an int of 0. The destructor is written in the class: the
 * complete one, FUN_0139b520, is a jump to the base-object one,
 * FUN_0139b550 (the arrays last to first through their destructor
 * FUN_0134f620, the Name and the reference, then the root's destructor in
 * line), and the deleting one, FUN_0139b530, calls it. Its cost is 310:
 * under the implicit destructor's limit of 325 (the inline hint), over
 * the 225 of a body written in the class, which carries no hint. The
 * class has no key function, so the creator's unit emits the vtable with
 * them. */
class Object016cffb0 : public Object016b9108 /* derived name */
{
  public:
    Object016cffb0(const Name &name)
        : Object016b9108(name), unknown24(3), unknown30(100), unknown34(0.05f), unknown38(2.9f),
          unknown3c(8.0f), unknown40(8.0f), unknown44(5.0f), name48(D_15ad2e8, false), unknown68(0),
          unknown88(0)
    {
    }

    virtual ~Object016cffb0() {}

  private:
    int unknown24;                         /* +0x24: 3 from the constructor */
    Ref00503fb0<Object016b9108> unknown28; /* +0x28 */
    int unknown30;                         /* +0x30: 100 from the constructor */
    float unknown34;                       /* +0x34: 0.05 from the constructor */
    float unknown38;                       /* +0x38: 2.9 from the constructor */
    float unknown3c;                       /* +0x3c: 8 from the constructor */
    float unknown40;                       /* +0x40: 8 from the constructor */
    float unknown44;                       /* +0x44: 5 from the constructor */
    Name name48;                           /* +0x48 */
    u8 unknown4c[0x4];
    Array01343a80<Ref00503fb0<Object016b9108>> references50; /* +0x50 */
    int unknown68;                                           /* +0x68: 0 from the constructor */
    u8 unknown6c[0x4];
    Array01343a80<Ref00503fb0<Object016b9108>> references70; /* +0x70 */
    int unknown88;                                           /* +0x88: 0 from the constructor */
    u8 unknown8c[0x4];
};

#endif
