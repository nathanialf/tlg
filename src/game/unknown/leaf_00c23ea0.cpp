/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016d06d0.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x59383f8]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_59383f8;

/* derived name: the creator of Object016d06d0, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x70 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place by its
 * constructor FUN_00c24000, which is not inlined. */
// NONMATCHING: equal under the link stage at 175 (D85), unclaimed: its constructor
// FUN_00c24000 (leaf_013a2770.cpp) is not matched, and the layout finds an unclaimed
// callee by its bytes in the base
Object016b9108 *FUN_00c23ea0(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016d06d0));
    D_59458a4.lock();
    D_59458a8 = D_59383f8;
    return new (memory) Object016d06d0(name);
}
