/* src/include/tlg_game_object016cc340.h: the class whose vtable is at
 * 0x16cc340 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CC340_H
#define TLG_GAME_OBJECT016CC340_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived name: the class of the objects the array at +0x58 of
 * Object016cc340 holds; not traced */
class Element016cc340;

/* derived names: the class whose vtable is at 0x16cc340
 * (config/vtables.derived.base.txt, stored by its creator FUN_008794f0,
 * leaf_008794f0.cpp, and its destructor FUN_01373810), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x88 bytes: three locked arrays of counted references at +0x28,
 * +0x40 and +0x58, an empty counted reference at +0x70, then 0.5 at
 * +0x78, 5 at +0x7c and 0.5 at +0x80, all from the constructor. The third
 * array holds objects of a class no other array of the module holds, so
 * its destructor, which has this one caller, is inlined by the link,
 * where the first two call the shared one, FUN_0134f620. The destructor
 * is written in the class: the complete one, FUN_01373800, is a jump to
 * the base-object one, FUN_01373810 (the reference, the arrays last to
 * first, then the root's destructor in line), and the deleting one,
 * FUN_01373a30, calls it. Its cost is 265: under the implicit
 * destructor's limit of 325 (the inline hint), over the 225 of a body
 * written in the class, which carries no hint. The class has no key
 * function, so the creator's unit emits the vtable with them. */
class Object016cc340 : public Object016b9108 /* derived name */
{
  public:
    Object016cc340(const Name &name)
        : Object016b9108(name), unknown78(0.5f), unknown7c(5.0f), unknown80(0.5f)
    {
    }

    virtual ~Object016cc340() {}

  private:
    u8 unknown24[0x4];
    Array01343a80<Ref00503fb0<Object016b9108>> references28;  /* +0x28 */
    Array01343a80<Ref00503fb0<Object016b9108>> references40;  /* +0x40 */
    Array01343a80<Ref00503fb0<Element016cc340>> references58; /* +0x58 */
    Ref00503fb0<Object016b9108> unknown70;                    /* +0x70 */
    float unknown78;                                          /* +0x78: 0.5 from the constructor */
    float unknown7c;                                          /* +0x7c: 5 from the constructor */
    float unknown80;                                          /* +0x80: 0.5 from the constructor */
    u8 unknown84[0x4];
};

#endif
