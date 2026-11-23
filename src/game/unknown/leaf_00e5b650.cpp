/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016cd348.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x598cf38]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_598cf38;

/* derived name: the creator of Object016cd348, of FUN_009912d0's shape and
 * signature (the first argument is not used): the object's 0x48 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place, its
 * constructor inlined. This unit constructs the class, so it emits its
 * vtable and its two destructors (FUN_01382c30, FUN_01382d00). */
/* NONMATCHING FUN_00e5b650: the creation lock's wait loop, as FUN_009912d0's (leaf_009912d0.cpp). */
Object016b9108 *FUN_00e5b650(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016cd348));
    D_59458a4.lock();
    D_59458a8 = D_598cf38;
    return new (memory) Object016cd348(name);
}
