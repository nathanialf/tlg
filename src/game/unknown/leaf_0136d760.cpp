/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016cbca0.h"

/* derived names: the class whose vtable is at 0x16cbcd8
 * (config/vtables.derived.base.txt, stored by FUN_007ae0d0 FUN_0136d760 FUN_0136d8b0), derived from Object016cbca0 (tlg_game_object016cbca0.h; itself derived from
 * Object016b9108): every slot from 2 is the base's. Its own fields
 * from +0x88 are traced only where its destructor FUN_0136d760 tears them down
 * (the Name at +0x88); the rest are not traced. */
class Object016cbcd8 : public Object016cbca0 /* derived name */
{
  public:
    virtual ~Object016cbcd8();

  private:
    Name name88; /* +0x88: released by the destructor (`mov eax, [rbx+0x88]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * (FUN_0136da00, tlg_game_object016cbca0.h) is inlined, and Object016b9108's in it.
 * FUN_0136d8b0, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
// NONMATCHING: an inline-cost margin: the build tail-calls the base's destructor FUN_0136da00 where the
// base inlines it
Object016cbcd8::~Object016cbcd8() {}
