/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b39e8
 * (config/vtables.derived.base.txt, stored by FUN_00ad5a00 FUN_00ad5c50),
 * derived from Object016b9108: its destructor FUN_00ad5a00 ends with that
 * class's (the vtable 0x16b9108 stored, the Names at +0x10 and +0xc
 * released). Its members are traced only where the destructor releases
 * them: two arrays of Names (the loops over `[r12+rbx*4]` with the counts
 * at +0x50 and +0x38, each block released after its loop) and a counted
 * reference at +0x28. */
class Object016b39e8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b39e8();

  private:
    AtomicRef0045c470<Node00503fb0> held28; /* +0x28: a counted reference */
    Array05943280<Name> names30;            /* +0x30 */
    Array05943280<Name> names48;            /* +0x48 */
};

/* derived name: the complete destructor: nothing of its own; the members
 * are released, last first, then the base's. FUN_00ad5c30, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b39e8::~Object016b39e8() {}
