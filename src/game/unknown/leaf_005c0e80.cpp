/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_005c0e80: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016abc00.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5809420]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_5809420;

/* derived name: the creator of Object016abc00, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x58 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place by its
 * constructor FUN_005c0fe0, which is not inlined. */
Object016b9108 *FUN_005c0e80(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016abc00));
    D_59458a4.lock();
    D_59458a8 = D_5809420;
    return new (memory) Object016abc00(name);
}
