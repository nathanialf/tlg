/* src/include/tlg_game_object016ce3e8.h: the class whose vtable is at
 * 0x16ce3e8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CE3E8_H
#define TLG_GAME_OBJECT016CE3E8_H

#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived name: the class of the objects the array at +0x38 of
 * Object016ce3e8 holds; not traced */
class Element016ce3e8;

/* derived names: the class whose vtable is at 0x16ce3e8
 * (config/vtables.derived.base.txt, stored by its creator FUN_00a546e0,
 * leaf_00a546e0.cpp, and its destructor FUN_0138ca30), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x58 bytes: two empty counted references at +0x28 and +0x30, a
 * locked array of counted references at +0x38 and an empty counted
 * reference at +0x50, all from the constructor. The array holds objects
 * of a class no other array of the module holds, so its destructor, which
 * has this one caller, is inlined by the link. The destructor is
 * implicit: the complete one, FUN_0138ca20, is a jump to the base-object
 * one, FUN_0138ca30 (the reference at +0x50, the array, its elements
 * released, then the other two references, then the root's destructor in
 * line), and the deleting one, FUN_0138cd40, calls it: its cost is over
 * the inline limit of 325 (the inline hint). The class has no key
 * function, so the creator's unit emits the vtable with them. */
class Object016ce3e8 : public Object016b9108 /* derived name */
{
  public:
    Object016ce3e8(const Name &name) : Object016b9108(name) {}

  private:
    u8 unknown24[0x4];
    Ref00503fb0<Object016b9108> unknown28;                    /* +0x28 */
    Ref00503fb0<Object016b9108> unknown30;                    /* +0x30 */
    Array01343a80<Ref00503fb0<Element016ce3e8>> references38; /* +0x38 */
    Ref00503fb0<Object016b9108> unknown50;                    /* +0x50 */
};

#endif
