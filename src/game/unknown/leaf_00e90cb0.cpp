/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016d31d8.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5a8d780]; mov [0x59458a8], rax` before the base's
 * constructor's call) */
extern Type059458a8 *D_5a8d780;

/* derived name: the creator of Object016d31d8, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0xe0 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place (its
 * base's constructor FUN_00ccfbe0 called with 4, its own inlined). */
// NONMATCHING: every store is the base's, but the value (1.0, 0, 0, 0) shared by +0x90 and +0xb4 is loaded from the constant pool (`vmovss`) where the base builds it as an integer vector (`mov edx, 0x3f800000; vmovd xmm0, edx`) and stores +0x90 after the floats at +0xd0: the stores from +0x90 reach the vectoriser as ints in the base; the source form not found
Object00ccfd00 *FUN_00e90cb0(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016d31d8));
    D_59458a4.lock();
    D_59458a8 = D_5a8d780;
    return new (memory) Object016d31d8(name);
}
