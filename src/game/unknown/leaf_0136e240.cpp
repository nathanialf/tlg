/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016cbae0.h"

/* derived names: the class whose vtable is at 0x16cbb50
 * (config/vtables.derived.base.txt, stored by FUN_007ad5e0 FUN_0136e240 FUN_0136e390), derived from Object016cbae0 (tlg_game_object016cbae0.h; itself derived from
 * Object016b9108): every slot from 2 is the base's. Its own fields
 * from +0x98 are traced only where its destructor FUN_0136e240 tears them down
 * (the Name at +0x9c); the rest are not traced. */
class Object016cbb50 : public Object016cbae0 /* derived name */
{
  public:
    virtual ~Object016cbb50();

  private:
    u8 unknown98[0x4];
    Name name9c; /* +0x9c: released by the destructor (`mov eax, [rbx+0x9c]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * (FUN_0136e780, tlg_game_object016cbae0.h) is inlined, and Object016b9108's in it.
 * FUN_0136e390, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
// NONMATCHING: an inline-cost margin: the build tail-calls the base's destructor FUN_0136e780 where the
// base inlines it
Object016cbb50::~Object016cbb50() {}
