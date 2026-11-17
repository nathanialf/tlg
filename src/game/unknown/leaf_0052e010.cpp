/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016ab4e8.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x57db358]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_57db358;

/* derived name: the creator of Object016ab4e8, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x1e0 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place by its
 * constructor FUN_005322e0, which is not inlined. */
Object016b9108 *FUN_0052e010(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016ab4e8));
    D_59458a4.lock();
    D_59458a8 = D_57db358;
    return new (memory) Object016ab4e8(name);
}
