/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016cb260.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5809458]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_5809458;

/* derived name: the creator of Object016cb260, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x1910 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place by its
 * constructor FUN_005c6060, which is not inlined. */
Object016b9108 *FUN_005c1730(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016cb260));
    D_59458a4.lock();
    D_59458a8 = D_5809458;
    return new (memory) Object016cb260(name);
}
