/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016cb428.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x580f6b8]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_580f6b8;

/* derived name: the creator of Object016cb428, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x5040 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place by its
 * constructor 0x6339a0, which is not inlined. */
Object016b9108 *FUN_00628560(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016cb428));
    D_59458a4.lock();
    D_59458a8 = D_580f6b8;
    return new (memory) Object016cb428(name);
}
