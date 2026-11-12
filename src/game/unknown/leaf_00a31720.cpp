/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b1e60
 * (config/vtables.derived.base.txt, stored by FUN_00a315b0 FUN_00a31720), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_00a31720 tears them down
 * (the Names at +0x38, +0x34, +0x2c, +0x28); the rest are not traced. */
class Object016b1e60 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b1e60();

  private:
    u8 unknown24[0x4];
    Name name28; /* +0x28: released by the destructor (`mov eax, [rbx+0x28]; shl 5`) */
    Name name2c; /* +0x2c: released by the destructor (`mov eax, [rbx+0x2c]; shl 5`) */
    u8 unknown30[0x4];
    Name name34; /* +0x34: released by the destructor (`mov eax, [rbx+0x34]; shl 5`) */
    Name name38; /* +0x38: released by the destructor (`mov eax, [rbx+0x38]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_00a31870, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b1e60::~Object016b1e60() {}
