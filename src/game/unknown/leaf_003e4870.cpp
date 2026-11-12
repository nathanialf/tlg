/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16a91c8
 * (config/vtables.derived.base.txt, stored by FUN_003e4660 FUN_003e4870), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_003e4870 tears them down
 * (the Names at +0x70, +0x6c, +0x68, +0x64, +0x60, +0x5c, +0x58, +0x54, +0x50, +0x4c, +0x48, +0x44, +0x40, +0x28, +0x24); the rest are not traced. */
class Object016a91c8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a91c8();

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    Name name28; /* +0x28: released by the destructor (`mov eax, [rbx+0x28]; shl 5`) */
    u8 unknown2c[0x14];
    Name name40; /* +0x40: released by the destructor (`mov eax, [rbx+0x40]; shl 5`) */
    Name name44; /* +0x44: released by the destructor (`mov eax, [rbx+0x44]; shl 5`) */
    Name name48; /* +0x48: released by the destructor (`mov eax, [rbx+0x48]; shl 5`) */
    Name name4c; /* +0x4c: released by the destructor (`mov eax, [rbx+0x4c]; shl 5`) */
    Name name50; /* +0x50: released by the destructor (`mov eax, [rbx+0x50]; shl 5`) */
    Name name54; /* +0x54: released by the destructor (`mov eax, [rbx+0x54]; shl 5`) */
    Name name58; /* +0x58: released by the destructor (`mov eax, [rbx+0x58]; shl 5`) */
    Name name5c; /* +0x5c: released by the destructor (`mov eax, [rbx+0x5c]; shl 5`) */
    Name name60; /* +0x60: released by the destructor (`mov eax, [rbx+0x60]; shl 5`) */
    Name name64; /* +0x64: released by the destructor (`mov eax, [rbx+0x64]; shl 5`) */
    Name name68; /* +0x68: released by the destructor (`mov eax, [rbx+0x68]; shl 5`) */
    Name name6c; /* +0x6c: released by the destructor (`mov eax, [rbx+0x6c]; shl 5`) */
    Name name70; /* +0x70: released by the destructor (`mov eax, [rbx+0x70]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names). FUN_003e4bf0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this file
 * emits the vtable. */
Object016a91c8::~Object016a91c8() {}
