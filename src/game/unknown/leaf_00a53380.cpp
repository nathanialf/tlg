/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived name: the class whose complete destructor is 0x83df00 (its row
 * named for it, D15), as leaf_00b54ba0.cpp declares it */
class Object0083df00 /* derived name */
{
  public:
    virtual ~Object0083df00();
};

/* derived names: the class whose vtable is at 0x16b20d0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00a531f0
 * and its complete destructor FUN_00a53380), derived from Object0083df00.
 * Slots 2 to 10 (FUN_00cb66f0, FUN_0134a390, FUN_0134a3a0, FUN_00c573b0,
 * FUN_00c575d0, FUN_00c59010, FUN_00a537e0, FUN_00a53ac0, FUN_00a535c0)
 * are declared here as the base's slots are not traced; the destructor
 * calls slot 9 through the vtable. Its fields are traced where the
 * destructor tears them down: a reference another thread may replace at
 * +0x588, a counted reference at +0x598 and a name at +0x5a0. */
class Object016b20d0 : public Object0083df00 /* derived name */
{
  public:
    virtual ~Object016b20d0();
    virtual void slot2();  /* derived name; FUN_00cb66f0 */
    virtual void slot3();  /* derived name; FUN_0134a390 */
    virtual void slot4();  /* derived name; FUN_0134a3a0 */
    virtual void slot5();  /* derived name; FUN_00c573b0, not traced */
    virtual void slot6();  /* derived name; FUN_00c575d0, not traced */
    virtual void slot7();  /* derived name; FUN_00c59010, not traced */
    virtual void slot8();  /* derived name; FUN_00a537e0, not traced */
    virtual void slot9();  /* derived name; FUN_00a53ac0, not traced */
    virtual void slot10(); /* derived name; FUN_00a535c0, not traced */

  private:
    u8 unknown8[0x580];
    AtomicRef0045c470<Object016b9108> shared588; /* +0x588 */
    u8 unknown590[0x8];
    Ref00503fb0<Object016b9108> held598; /* +0x598 */
    Name name5a0;                        /* +0x5a0 */
};

/* derived name: the complete destructor FUN_00a53380: the shared reference
 * emptied by compare-and-swap, then slot 9 run; the members are released,
 * last first, and the base's destructor 0x83df00 runs as a tail call.
 * FUN_00a535a0, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. */
Object016b20d0::~Object016b20d0()
{
    shared588.clear();
    slot9();
}
