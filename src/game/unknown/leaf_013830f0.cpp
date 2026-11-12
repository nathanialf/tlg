/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16cd430
 * (config/vtables.derived.base.txt, stored by FUN_00991dd0 FUN_013830f0 FUN_013831e0), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_013830f0 tears them down
 * (the Names at +0x64, +0x30); the rest are not traced. */
class Object016cd430 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cd430();

  private:
    u8 unknown24[0xc];
    Name name30; /* +0x30: released by the destructor (`mov eax, [rbx+0x30]; shl 5`) */
    u8 unknown34[0x30];
    Name name64; /* +0x64: released by the destructor (`mov eax, [rbx+0x64]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_013831e0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016cd430::~Object016cd430() {}
