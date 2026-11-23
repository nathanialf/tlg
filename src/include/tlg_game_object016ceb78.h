/* src/include/tlg_game_object016ceb78.h: the class whose vtable is at
 * 0x16ceb78 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CEB78_H
#define TLG_GAME_OBJECT016CEB78_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ceb78
 * (config/vtables.derived.base.txt, stored by its creator FUN_00b00770,
 * leaf_00b00770.cpp, and its destructor FUN_0138f3f0), derived from
 * Object016b9108: its five slots are the two destructors and the base's
 * three. 0x38 bytes: a Name at +0x24 and two counted references at +0x28
 * and +0x30, empty from the constructor (a 16-byte store and a 4-byte one).
 * The destructor is implicit: the complete one, FUN_0138f3c0, is a jump to
 * the base-object one, FUN_0138f3f0 (the references and the Name released
 * last to first, then the root's destructor in line), and the deleting
 * one, FUN_0138f3d0, calls it: its cost is over the inline limit. The class
 * has no key function, so the creator's unit emits the vtable with them. */
class Object016ceb78 : public Object016b9108 /* derived name */
{
  public:
    Object016ceb78(const Name &name) : Object016b9108(name) {}

  private:
    Name name24;                           /* +0x24 */
    Ref00503fb0<Object016b9108> unknown28; /* +0x28 */
    Ref00503fb0<Object016b9108> unknown30; /* +0x30 */
};

#endif
