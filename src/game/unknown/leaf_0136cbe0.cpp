/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016cbd80.h"

/* derived names: the class whose vtable is at 0x16cbdf0
 * (config/vtables.derived.base.txt, stored by FUN_007ae910 FUN_0136cbe0 FUN_0136cd30), derived from Object016cbd80 (tlg_game_object016cbd80.h; itself derived from
 * Object016b9108): every slot from 2 is the base's. Its own fields
 * from +0x88 are traced only where its destructor FUN_0136cbe0 tears them down
 * (the Name at +0x88); the rest are not traced. */
class Object016cbdf0 : public Object016cbd80 /* derived name */
{
  public:
    virtual ~Object016cbdf0();

  private:
    Name name88; /* +0x88: released by the destructor (`mov eax, [rbx+0x88]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * (FUN_0136d120, tlg_game_object016cbd80.h) is inlined, and Object016b9108's in it.
 * FUN_0136cd30, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
// NONMATCHING: an inline-cost margin: the build tail-calls the base's destructor FUN_0136d120 where the
// base inlines it
Object016cbdf0::~Object016cbdf0() {}
