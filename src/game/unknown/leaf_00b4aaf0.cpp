/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00b4aaf0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016b64a0.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5833bc0]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_5833bc0;

/* derived name: the creator of Object016b64a0, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x68 bytes
 * are allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place. */
Object016b9108 *FUN_00b4aaf0(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016b64a0));
    D_59458a4.lock();
    D_59458a8 = D_5833bc0;
    return new (memory) Object016b64a0(name);
}
