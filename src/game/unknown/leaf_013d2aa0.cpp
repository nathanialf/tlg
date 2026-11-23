/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013d2f90.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16bf020 (config/vtables.derived.base.txt; stored by its constructor
 * FUN_00f4cf00), defined empty: its member at +0x10, an Object013d2f90
 * (tlg_game_object013d2f90.h), is destroyed with its destructor inlined in the module
 * (its vtable stored, its block released, the last call a tail call).
 * FUN_013d2b00, slot 1, is the deleting one. The vtable holds no second table,
 * so the Object013d2f90 is a member, not a base. Slots 2 to 6 are the shared
 * empty body 0x1af750, slots 7 and 8 FUN_00f4d020 and FUN_00f4d030, declared here
 * untraced. The destructor is the class's key function, so this file emits
 * the vtable. */
class Object016bf020 /* derived name */
{
  public:
    explicit Object016bf020(void *owner);

    virtual ~Object016bf020();

    virtual void slot2() {} /* derived name */

    virtual void slot3() {} /* derived name */

    virtual void slot4() {} /* derived name */

    virtual void slot5() {} /* derived name */

    virtual void slot6() {} /* derived name */

    virtual void slot7(); /* derived name; FUN_00f4d020, not traced */
    virtual void slot8(); /* derived name; FUN_00f4d030, not traced */

  private:
    void *unknown8;           /* +0x8: the constructor's argument; not traced */
    Object013d2f90 unknown10; /* +0x10 */
};

/* FUN_00f4cf00: the constructor: the argument kept at +0x8, the member at +0x10
 * built with its constructor in line (tlg_game_object013d2f90.h) */
// NONMATCHING: two store orders and one merge: the base stores +0x8 before the vptr and the
// member's +0x18 and +0x20 before its vptr (each the field of a base class constructed first,
// the stores kept in the IR's order), and keeps the four ints at +0x40 to +0x4c one store each
// (0, 0, -1, 1) where the build merges them into one vector constant.
Object016bf020::Object016bf020(void *owner) : unknown8(owner) {}

Object016bf020::~Object016bf020() {}
