/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cb958
 * (config/vtables.derived.base.txt, stored by FUN_007a2150 FUN_0136c1e0 FUN_0136c2a0), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_0136c1e0 tears them down
 * (the Name at +0x74); the rest are not traced. */
class Object016cb958 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cb958();

  private:
    u8 unknown24[0x50];
    Name name74; /* +0x74: released by the destructor (`mov eax, [rbx+0x74]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_0136c2a0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016cb958::~Object016cb958() {}
