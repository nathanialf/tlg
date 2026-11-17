/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016b9108_inline.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5813f48]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_5813f48;

/* derived name: the creator of Object016cb5b8, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x2e0 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place by its
 * constructor 0x690560, which is not inlined. */
Object016b9108 *FUN_00685d90(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016cb5b8));
    D_59458a4.lock();
    D_59458a8 = D_5813f48;
    return new (memory) Object016cb5b8(name);
}
