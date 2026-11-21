/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_0085e070: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016cc0c0.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x581d720]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_581d720;

/* derived name: the creator of Object016cc0c0, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x38 bytes
 * are allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place. This
 * unit creates the object, so it emits the class's vtable and its two
 * destructors (FUN_013712b0 and FUN_01371370, defined in the header). */
Object016b9108 *FUN_0085e070(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016cc0c0));
    D_59458a4.lock();
    D_59458a8 = D_581d720;
    return new (memory) Object016cc0c0(name);
}
