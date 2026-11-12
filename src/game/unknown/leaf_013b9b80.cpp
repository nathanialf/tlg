/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16d23e0
 * (config/vtables.derived.base.txt, stored by FUN_00d57060 FUN_013b9b80 FUN_013b9c70), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_013b9b80 tears them down
 * (the Names at +0x30, +0x28); the rest are not traced. */
class Object016d23e0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016d23e0();

  private:
    u8 unknown24[0x4];
    Name name28; /* +0x28: released by the destructor (`mov eax, [rbx+0x28]; shl 5`) */
    u8 unknown2c[0x4];
    Name name30; /* +0x30: released by the destructor (`mov eax, [rbx+0x30]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_013b9c70, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016d23e0::~Object016d23e0() {}
