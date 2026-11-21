/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_0079c7a0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016ad9f8.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5818758]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_5818758;

/* derived name: the creator of Object016ad9f8, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x170 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place by its
 * constructor FUN_0079c900, which is not inlined. */
Object016b9108 *FUN_0079c7a0(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016ad9f8));
    D_59458a4.lock();
    D_59458a8 = D_5818758;
    return new (memory) Object016ad9f8(name);
}
