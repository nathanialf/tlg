/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object01343880.h"

/* derived names: the class whose vtable is at 0x16b1fd0
 * (config/vtables.derived.base.txt, stored by FUN_00a524e0 FUN_00a526b0 FUN_00a52770), derived from
 * Object01343880 (tlg_game_object01343880.h: slots 5 to 8 are that class's). Its own fields
 * from +0x34 are traced only where its destructor FUN_00a526b0 tears them down
 * (the Name at +0x60); the rest are not traced. */
class Object016b1fd0 : public Object01343880 /* derived name */
{
  public:
    virtual ~Object016b1fd0();

  private:
    u8 unknown34[0x2c];
    Name name60; /* +0x60: released by the destructor (`mov eax, [rbx+0x60]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_00a52770, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b1fd0::~Object016b1fd0() {}
