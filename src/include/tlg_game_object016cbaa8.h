/* src/include/tlg_game_object016cbaa8.h: the class whose vtable is at
 * 0x16cbaa8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016CBAA8_H
#define TLG_GAME_OBJECT016CBAA8_H

#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cbaa8
 * (config/vtables.derived.base.txt, stored by FUN_007a2d90 FUN_0136c360
 * FUN_0136c4b0), derived from Object016b9108: its five slots are the two
 * destructors and the base's three. Its own fields: the Name at +0x24 and
 * the counted reference at +0x28, which the constructor FUN_007a2d90
 * sets and the destructor FUN_0136c360 releases. The destructor is the
 * class's key function (leaf_0136c360.cpp), so that unit emits the vtable: defined
 * inline it stays a function of its own that the two vtable destructors call
 * (326 bytes: over the inliner's threshold). */
class Object016cbaa8 : public Object016b9108 /* derived name */
{
  public:
    Object016cbaa8(const Name &name);
    virtual ~Object016cbaa8();

  private:
    Name name24;                            /* +0x24: empty from the constructor */
    AtomicRef0045c470<Node00503fb0> held28; /* +0x28 */
};

#endif
