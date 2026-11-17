/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016a9200.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x57d2428]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_57d2428;

/* derived name: the creator of Object016a9200, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0xb0 bytes
 * are allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place. */
// NONMATCHING: store order only: the base stores +0x50's 16 bytes before +0x30's and the int
// at +0x40 after both; this build stores +0x30, +0x40, +0x50 (three forms tried: pointers, Float4 at +0x50, Float4 at both)
Object016b9108 *FUN_003e7730(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016a9200));
    D_59458a4.lock();
    D_59458a8 = D_57d2428;
    return new (memory) Object016a9200(name);
}
