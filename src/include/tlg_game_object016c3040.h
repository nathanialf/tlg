/* src/include/tlg_game_object016c3040.h: the class whose vtable is at
 * 0x16c3040 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C3040_H
#define TLG_GAME_OBJECT016C3040_H

#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object00c1b7f0.h"

/* derived names: the class whose vtable is at 0x16c3040
 * (config/vtables.derived.base.txt, stored by FUN_0129a240 FUN_0129a4d0),
 * derived from Object00c1b7f0. Its destructor FUN_0129a4d0 is FUN_00f1a950
 * (leaf_00f1a950.cpp) instruction for instruction but for the vtable, so
 * the fields that destructor uses are Object016bedd8's, at the same
 * offsets; the rest are not traced. */
class Object016c3040 : public Object00c1b7f0, public Object013cd320 /* derived name */
{
  public:
    Object016c3040(const Name &name); /* FUN_0129a240 */
    virtual ~Object016c3040();

  private:
    u8 unknown194[0x24]; /* +0x194: in the tail padding of Object013cd320; not traced */
  public:
    AtomicRef0045c470<Object016b9108> owner; /* +0x1b8: a counted reference */

  private:
    Name name1c0; /* +0x1c0: released by the destructor */
    u8 unknown1c4[0x14];
    Registry00f516f0 *registry; /* +0x1d8: the array this object is entered in, or null */
    void *unknown1e0;
    AtomicRef0045c470<Object016b9108> held1e8; /* +0x1e8: a counted reference */
    u8 unknown1f0[0x10]; /* the rest of the 0x200 bytes the creator allocates; not traced */
};

#endif
