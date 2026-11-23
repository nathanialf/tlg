/* src/include/tlg_game_object016cdc70.h: the class whose vtable is at
 * 0x16cdc70 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CDC70_H
#define TLG_GAME_OBJECT016CDC70_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_math.h"

/* derived name: the class of the objects the array at +0x48 of
 * Object016cdc70 holds; not traced */
class Element016cdc70;

/* derived names: the class whose vtable is at 0x16cdc70
 * (config/vtables.derived.base.txt, stored by its creator FUN_009b5b10,
 * leaf_009b5b10.cpp, and its destructor FUN_01385cf0), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0xc0 bytes: four empty counted references from +0x28, two locked
 * arrays of counted references at +0x48 and +0x60, (40, 20, 0, 60) at
 * +0x78, 0 at +0x88, 1 at +0x8c, 40 at +0x90, (30, 90, 0, 1) at +0xa0 and
 * 0 at +0xb0, all from the constructor. The array at +0x48 holds objects
 * of a class no other array of the module holds, so its destructor, which
 * has this one caller, is inlined by the link, where the other calls the
 * shared one, FUN_0134f620. The destructor is implicit: the complete one,
 * FUN_01385cc0, is a jump to the base-object one, FUN_01385cf0 (the
 * arrays last to first, then the references, then the root's destructor
 * in line), and the deleting one, FUN_01385cd0, calls it: its cost is
 * over the inline limit of 325 (the inline hint). The class has no key
 * function, so the creator's unit emits the vtable with them. */
class Object016cdc70 : public Object016b9108 /* derived name */
{
  public:
    Object016cdc70(const Name &name)
        : Object016b9108(name), unknown78(40.0f, 20.0f, 0.0f, 60.0f), unknown88(0), unknown8c(1.0f),
          unknown90(40.0f), unknowna0(30.0f, 90.0f, 0.0f, 1.0f), unknownb0(0)
    {
    }

  private:
    u8 unknown24[0x4];
    Ref00503fb0<Object016b9108> unknown28;                    /* +0x28 */
    Ref00503fb0<Object016b9108> unknown30;                    /* +0x30 */
    Ref00503fb0<Object016b9108> unknown38;                    /* +0x38 */
    Ref00503fb0<Object016b9108> unknown40;                    /* +0x40 */
    Array01343a80<Ref00503fb0<Element016cdc70>> references48; /* +0x48 */
    Array01343a80<Ref00503fb0<Object016b9108>> references60;  /* +0x60 */
    Float4 unknown78; /* +0x78: (40, 20, 0, 60) from the constructor */
    int unknown88;    /* +0x88: 0 from the constructor */
    float unknown8c;  /* +0x8c: 1 from the constructor */
    float unknown90;  /* +0x90: 40 from the constructor */
    u8 unknown94[0xc];
    Float4 unknowna0; /* +0xa0: (30, 90, 0, 1) from the constructor */
    int unknownb0;    /* +0xb0: 0 from the constructor */
    u8 unknownb4[0xc];
};

#endif
