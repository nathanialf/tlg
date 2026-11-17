/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016a8d50.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x57d0970]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_57d0970;

/* derived name: the creator of Object016a8d50, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0xa0 bytes
 * are allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place. */
// NONMATCHING: the base keeps the six floats at +0x60 to +0x74 scalar, those at +0x6c first;
// this build makes +0x60 to +0x6c one 16-byte constant store (and the object in r15, the base's rbx)
Object016b9108 *FUN_0037a460(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016a8d50));
    D_59458a4.lock();
    D_59458a8 = D_57d0970;
    return new (memory) Object016a8d50(name);
}
