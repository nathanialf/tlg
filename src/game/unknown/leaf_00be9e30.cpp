/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b7b58
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00be8ca0
 * and its destructor FUN_00be9e30), derived from Object016b9108: its slots
 * 2 to 4 are the base's, slot 5 FUN_00bea1f0 and slot 6 FUN_00c1b350. Its
 * fields are traced where the destructor tears them down: a reference
 * another thread may replace at +0x28, four arrays of counted references
 * from +0x30 (each torn down by 0x134f620) and two references at +0x98 and
 * +0xa0. */
class Object016b7b58 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b7b58();
    virtual void slot5(); /* derived name; FUN_00bea1f0, not traced */
    virtual void slot6(); /* derived name; FUN_00c1b350, not traced */

  private:
    u8 unknown24[0x4];
    AtomicRef0045c470<Object016b9108> shared28; /* +0x28 */
    Object0134f620 array30;                     /* +0x30 */
    Object0134f620 array48;                     /* +0x48 */
    Object0134f620 array60;                     /* +0x60 */
    Object0134f620 array78;                     /* +0x78 */
    u8 unknown90[0x8];
    Ref00503fb0<Object016b9108> held98; /* +0x98 */
    Ref00503fb0<Object016b9108> heldA0; /* +0xa0 */
};

/* derived name: the complete destructor FUN_00be9e30: the array at +0x48
 * has its references released (its block kept) and the shared reference
 * is emptied by compare-and-swap, then the members and the base are torn
 * down. FUN_00bea1d0, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. */
Object016b7b58::~Object016b7b58()
{
    array48.removeAll();
    shared28.clear();
}
