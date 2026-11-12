/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16b2d10
 * (config/vtables.derived.base.txt, stored by FUN_00a9a7e0 FUN_00a9a9a0 FUN_00a9aae0), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_00a9a9a0 tears them down
 * (the array of Names at +0x28, the record at +0x40); the rest are not traced. */
class Object016b2d10 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b2d10();

  private:
    u8 unknown24[0x4];
    /* +0x28: an array of Names (the block at +0x28, the count at +0x30): the destructor releases each
     * (`mov r12, [r14+0x28]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array05943280<Name> names28;
    /* +0x40: torn down by the destructor (`lea rdi, [rbx+0x40]; call 0x134f620`) */
    Object0134f620 record40;
};

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names).
 * FUN_00a9aae0, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016b2d10::~Object016b2d10() {}
