/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b9108.h"
#include "tlg_game_array.h"
#include "tlg_game_name.h"

/* derived names: the class whose vtable is at 0x16cb378
 * (config/vtables.derived.base.txt, stored by FUN_0061cee0 FUN_0135fc40 FUN_0135fd80), derived from
 * Object016b9108: its slots 2 to 4 are the base's. Its own fields
 * from +0x24 are traced only where its destructor FUN_0135fc40 tears them down
 * (the array of Names at +0x118); the rest are not traced. */
class Object016cb378 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016cb378();

  private:
    u8 unknown24[0xf4];
    /* +0x118: an array of Names (the block at +0x118, the count at +0x120): the destructor releases each
     * (`mov r12, [r14+0x118]; mov ecx, [r12+rbx*4]` ... `cmp ebx, eax; jb`), then the block */
    Array05943280<Name> names118;
};

/* derived name: the complete destructor: the body is empty; the members are
 * released, last first, then the base's destructor
 * is inlined (its vptr store, then the two names).
 * FUN_0135fd80, slot 1, is the deleting one. The destructor is the class's key
 * function, so this file emits the vtable. */
Object016cb378::~Object016cb378() {}
