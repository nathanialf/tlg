/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aed28.h"

/* derived names: the class whose vtable is at 0x16ac218
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00681b50
 * and its complete destructor FUN_00684c00), over Object016aed28 (its slot
 * 45 is its own, FUN_00684ea0). Its fields are traced where the destructor
 * tears them down: five names and a reference another thread may replace
 * at +0x5e0. */
class Object016ac218 : public Object016aed28 /* derived name */
{
  public:
    virtual ~Object016ac218();

    Name name580; /* +0x580 */

  private:
    u8 unknown584[0xc];

  public:
    Name name590; /* +0x590 */

  private:
    u8 unknown594[0xc];

  public:
    Name name5a0; /* +0x5a0 */
    Name name5a4; /* +0x5a4 */
    Name name5a8; /* +0x5a8 */

  private:
    u8 unknown5ac[0x34];

  public:
    AtomicRef0045c470<Object016b9108> shared5e0; /* +0x5e0 */
};

/* derived name: the complete destructor FUN_00684c00: the shared reference
 * emptied by compare-and-swap; the members are released, last first, and
 * the base's destructor 0x83df00 runs as a tail call. FUN_00684e80, slot 1,
 * is the deleting one. The destructor is the class's key function, so this
 * file emits the vtable. */
Object016ac218::~Object016ac218()
{
    shared5e0.clear();
}
