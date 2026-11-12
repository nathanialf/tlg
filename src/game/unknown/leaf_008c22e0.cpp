/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16b02a8
 * (config/vtables.derived.base.txt, stored by FUN_008c2140 FUN_008c22e0), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_008c22e0 tears them down
 * (the array of Names at +0x30, the Name at +0x24); the rest are not traced. */
class Object016b02a8 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b02a8();

  private:
    Name name24; /* +0x24: released by the destructor (`mov eax, [rbx+0x24]; shl 5`) */
    u8 unknown28[0x8];
    /* +0x30: an array of Names (the block at +0x30, the count at +0x38): the destructor releases each
     * (`mov r12, [r14+0x30]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array05943280<Name> names30;
};

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names).
 * FUN_008c2440, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016b02a8::~Object016b02a8() {}
