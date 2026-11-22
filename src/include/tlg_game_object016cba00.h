/* src/include/tlg_game_object016cba00.h: the class whose vtable is at
 * 0x16cba00 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CBA00_H
#define TLG_GAME_OBJECT016CBA00_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cba00
 * (config/vtables.derived.base.txt, stored by FUN_007a27a0 FUN_0136bc20
 * FUN_0136bd70), derived from Object016b9108: its five slots are the two
 * destructors and the base's three. Its own fields: the Name at +0x24 and
 * the counted reference at +0x28, which the constructor FUN_007a27a0
 * sets and the destructor FUN_0136bc20 releases. The destructor is implicit:
 * FUN_0136bc20 and the deleting FUN_0136bd70 sit in the stretch of inline
 * functions (from 0x1340000) while the constructor is out of line, so the
 * class has no key function and the constructor's unit (leaf_007a27a0.cpp)
 * emits the vtable with both; an implicit destructor carries the inline
 * hint, so the deleting one holds its body as the base's does. */
class Object016cba00 : public Object016b9108 /* derived name */
{
  public:
    Object016cba00(const Name &name);

  private:
    Name name24;                              /* +0x24: empty from the constructor */
    AtomicRef0045c470<Object016b9108> held28; /* +0x28 */
};

#endif
