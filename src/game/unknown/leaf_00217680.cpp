/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016a7818.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x57ca270]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_57ca270;

/* derived name: the creator of Object016a7818, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x88 bytes
 * are allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place. */
Object016b9108 *FUN_00217680(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016a7818));
    D_59458a4.lock();
    D_59458a8 = D_57ca270;
    return new (memory) Object016a7818(name);
}
