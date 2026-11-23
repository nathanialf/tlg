/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013d2f90.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16c1e40 (config/vtables.derived.base.txt; stored by its constructor
 * FUN_0120fe90), defined empty: its member at +0x10, an Object013d2f90
 * (tlg_game_object013d2f90.h), is destroyed with its destructor inlined in the module
 * (its vtable stored, its block released, the last call a tail call).
 * FUN_014781e0, slot 1, is the deleting one. The vtable holds no second table,
 * so the Object013d2f90 is a member, not a base. Slots 2 to 6 are the shared
 * empty body 0x1af750, slots 7 and 8 FUN_0120ffb0 and FUN_0120ffc0, declared here
 * untraced. The destructor is the class's key function, so this file emits
 * the vtable. */
/* derived name: the owner kept at +0x8, a non-polymorphic base of
 * Object016c1e40: FUN_0120fe90 stores it before the class's vptr, so it is constructed
 * first */
struct Owner016c1e40 /* derived name */
{
    explicit Owner016c1e40(void *owner) : unknown8(owner) {}

    void *unknown8; /* +0x8: the constructor's argument; not traced */
};

class Object016c1e40 : public Owner016c1e40 /* derived name */
{
  public:
    explicit Object016c1e40(void *owner);

    virtual ~Object016c1e40();

    virtual void slot2() {} /* derived name */

    virtual void slot3() {} /* derived name */

    virtual void slot4() {} /* derived name */

    virtual void slot5() {} /* derived name */

    virtual void slot6() {} /* derived name */

    virtual void slot7(); /* derived name; FUN_0120ffb0, not traced */
    virtual void slot8(); /* derived name; FUN_0120ffc0, not traced */

  private:
    Object013d2f90 unknown10; /* +0x10 */
};

/* FUN_0120fe90: the constructor: the argument kept at +0x8, the member at +0x10
 * built with its constructor in line (tlg_game_object013d2f90.h) */
// The owner (+0x8) and the member's +0x18 and +0x20 are fields of non-polymorphic bases, stored
// before each vptr; the member's +0x30 is a float, so its constant stores stay one per field.
Object016c1e40::Object016c1e40(void *owner) : Owner016c1e40(owner) {}

Object016c1e40::~Object016c1e40() {}
