/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b3c10
 * (config/vtables.derived.base.txt, stored by FUN_00ae5ad0 FUN_00ae5de0), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_00ae5de0 tears them down
 * (the Names at +0x208, +0x16c, +0x154, +0x150, +0x8c, +0x24); the rest are not traced. */
class Object016b3c10 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b3c10();

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    u8 unknown28[0x64];
    Name name8c; /* +0x8c: released by the destructor (`mov eax, [rbx+0x8c]; shl 5`) */
    u8 unknown90[0xc0];
    Name name150; /* +0x150: released by the destructor (`mov eax, [rbx+0x150]; shl 5`) */
    Name name154; /* +0x154: released by the destructor (`mov eax, [rbx+0x154]; shl 5`) */
    u8 unknown158[0x14];
    Name name16c; /* +0x16c: released by the destructor (`mov eax, [rbx+0x16c]; shl 5`) */
    u8 unknown170[0x98];
    Name name208; /* +0x208: released by the destructor (`mov eax, [rbx+0x208]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_00ae5fd0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016b3c10::~Object016b3c10() {}
