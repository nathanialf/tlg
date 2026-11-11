/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16c1e40 (config/vtables.derived.base.txt; stored by its constructor
 * FUN_0120fe90), defined empty: its member at +0x10, an Object013d2f90
 * (tlg_game_block.h), is destroyed with its destructor inlined in the module
 * (its vtable stored, its block released, the last call a tail call).
 * FUN_014781e0, slot 1, is the deleting one. The vtable holds no second table,
 * so the Object013d2f90 is a member, not a base. Slots 2 to 6 are the shared
 * empty body 0x1af750, slots 7 and 8 FUN_0120ffb0 and FUN_0120ffc0, declared here
 * untraced. The destructor is the class's key function, so this file emits
 * the vtable. */
class Object016c1e40 /* derived name */
{
  public:
    virtual ~Object016c1e40();

    virtual void slot2() {} /* derived name */

    virtual void slot3() {} /* derived name */

    virtual void slot4() {} /* derived name */

    virtual void slot5() {} /* derived name */

    virtual void slot6() {} /* derived name */

    virtual void slot7(); /* derived name; FUN_0120ffb0, not traced */
    virtual void slot8(); /* derived name; FUN_0120ffc0, not traced */

  private:
    u8 unknown8[0x8];
    Object013d2f90 unknown10; /* +0x10 */
};

Object016c1e40::~Object016c1e40() {}
