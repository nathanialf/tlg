/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16a93c0
 * (config/vtables.derived.base.txt, stored by FUN_003ed1e0 FUN_003ed400), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_003ed400 tears them down
 * (the array of Names at +0x38, the Names at +0x64, +0x60, +0x28, +0x24); the rest are not traced. */
class Object016a93c0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a93c0();

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    Name name28; /* +0x28: released by the destructor (`mov eax, [rbx+0x28]; shl 5`) */
    u8 unknown2c[0xc];
    /* +0x38: an array of Names (the block at +0x38, the count at +0x40): the destructor releases each
     * (`mov r12, [r14+0x38]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array05943280<Name> names38;
    u8 unknown50[0x10];
    Name name60; /* +0x60: released by the destructor (`mov eax, [rbx+0x60]; shl 5`) */
    Name name64; /* +0x64: released by the destructor (`mov eax, [rbx+0x64]; shl 5`) */
};

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names).
 * FUN_003ed610, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016a93c0::~Object016a93c0() {}
