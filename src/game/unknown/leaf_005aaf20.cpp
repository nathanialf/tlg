/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ab9d8
 * (config/vtables.derived.base.txt, stored by FUN_005aa770 FUN_005aaf20), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_005aaf20 tears them down
 * (the Names at +0x40, +0x2c, +0x28); the rest are not traced. */
class Object016ab9d8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016ab9d8();

  private:
    u8 unknown24[0x4];
    Name name28; /* +0x28: released by the destructor (`mov eax, [rbx+0x28]; shl 5`) */
    Name name2c; /* +0x2c: released by the destructor (`mov eax, [rbx+0x2c]; shl 5`) */
    u8 unknown30[0x10];
    Name name40; /* +0x40: released by the destructor (`mov eax, [rbx+0x40]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_005ab040, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016ab9d8::~Object016ab9d8() {}
