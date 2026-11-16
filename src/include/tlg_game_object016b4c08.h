/* src/include/tlg_game_object016b4c08.h: the class whose vtable is at
 * 0x16b4c08 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016B4C08_H
#define TLG_GAME_OBJECT016B4C08_H

#include "tlg_game_node.h"
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b4c08
 * (config/vtables.derived.base.txt, stored by FUN_00b0e520 FUN_00b0e650
 * FUN_00b0e770), derived from Object01343880 (the pointer at +0x28 and the
 * int at +0x30 cleared before the vptr store, 0xb0e54e; slots 5 to 8 the
 * base's). Its own fields: the counted reference at +0x38, which the
 * constructor FUN_00b0e520 sets and the destructor FUN_00b0e650 releases,
 * and eight bytes at +0x40 cleared with it in one 16-byte store. */
class Object016b4c08 : public Object01343880 /* derived name */
{
  public:
    Object016b4c08(const Name &name);
    virtual ~Object016b4c08();

  private:
    AtomicRef0045c470<Object016b9108> held38; /* +0x38 */
    void *unknown40;                          /* +0x40: null from the constructor; not traced */
};

/* derived name: the complete destructor FUN_00b0e650: the body is empty; the
 * reference is released, then the base's destructor is inlined (its vptr
 * store, then the two names). FUN_00b0e770, slot 1, is the deleting one and
 * holds this one inlined. Defined here, so the unit that defines the
 * constructor (leaf_00b0e520.cpp) emits the vtable and both destructors. */
inline Object016b4c08::~Object016b4c08() {}

#endif
