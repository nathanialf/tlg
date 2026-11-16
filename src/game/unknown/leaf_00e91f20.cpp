/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016d3210.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5a8d798]; mov [0x59458a8], rax` before the base's
 * constructor's call) */
extern Type059458a8 *D_5a8d798;

/* derived name: the creator of Object016d3210, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0xe0 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place (its
 * base's constructor FUN_00ccfbe0 called with 5, its own inlined). */
Object00ccfd00 *FUN_00e91f20(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016d3210));
    D_59458a4.lock();
    D_59458a8 = D_5a8d798;
    return new (memory) Object016d3210(name);
}
