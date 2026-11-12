/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ac060
 * (config/vtables.derived.base.txt, stored by FUN_0066dcc0 FUN_0066e340), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_0066e340 tears them down
 * (the Names at +0x420, +0x2a8, +0x2a0, +0x218, +0x100); the rest are not traced. */
class Object016ac060 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016ac060();

  private:
    u8 unknown24[0xdc];
    Name name100; /* +0x100: released by the destructor (`mov eax, [rbx+0x100]; shl 5`) */
    u8 unknown104[0x114];
    Name name218; /* +0x218: released by the destructor (`mov eax, [rbx+0x218]; shl 5`) */
    u8 unknown21c[0x84];
    Name name2a0; /* +0x2a0: released by the destructor (`mov eax, [rbx+0x2a0]; shl 5`) */
    u8 unknown2a4[0x4];
    Name name2a8; /* +0x2a8: released by the destructor (`mov eax, [rbx+0x2a8]; shl 5`) */
    u8 unknown2ac[0x174];
    Name name420; /* +0x420: released by the destructor (`mov eax, [rbx+0x420]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_0066e4f0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ac060::~Object016ac060() {}
