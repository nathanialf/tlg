/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_002aa140: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016a7e28.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x57cb388]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_57cb388;

/* derived name: the creator of Object016a7e28, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x70 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place by its
 * constructor FUN_002aa2a0, which is not inlined. */
Object016b9108 *FUN_002aa140(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016a7e28));
    D_59458a4.lock();
    D_59458a8 = D_57cb388;
    return new (memory) Object016a7e28(name);
}
