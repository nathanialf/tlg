/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cbbf8
 * (config/vtables.derived.base.txt, stored by FUN_007adaa0 FUN_0136df20 FUN_0136dfe0), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_0136df20 tears them down
 * (the Name at +0x40); the rest are not traced. */
class Object016cbbf8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cbbf8();

  private:
    u8 unknown24[0x1c];
    Name name40; /* +0x40: released by the destructor (`mov eax, [rbx+0x40]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_0136dfe0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016cbbf8::~Object016cbbf8() {}
