/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00a04b00: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). After it, the base stores the ones at +0x40 and the lowest point at +0x50 as two 16-byte stores where this build makes one 32-byte store. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016ce0b0.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5826740]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_5826740;

/* derived name: the creator of Object016ce0b0, of FUN_002188b0's
 * signature (the first argument is not used): the object's 0xe0 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place: the
 * root's constructor 0xcb6310 a call, the class's own inlined after it. */
Object016b9108 *FUN_00a04b00(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016ce0b0));
    D_59458a4.lock();
    D_59458a8 = D_5826740;
    return new (memory) Object016ce0b0(name);
}
