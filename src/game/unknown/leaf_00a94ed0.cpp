/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016b2ab0.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5829890]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_5829890;

/* derived name: the creator of Object016b2ab0, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x30 bytes
 * are allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place. This
 * unit creates the object, so it emits the class's vtable and its two
 * destructors (FUN_00a95030 and FUN_00a95120, defined in the header). */
Object016b9108 *FUN_00a94ed0(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016b2ab0));
    D_59458a4.lock();
    D_59458a8 = D_5829890;
    return new (memory) Object016b2ab0(name);
}
