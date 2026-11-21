/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00a29f30: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016b1d00.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5827320]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_5827320;

/* derived name: the creator of Object016b1d00, registered with its type
 * through FUN_00cbb0e0 by FUN_00a2b8c0 (lea at 0xa2dfbe), whose signature it
 * keeps: the first argument is not used. The object's 0x70 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place, its
 * constructor and its base's inlined. */
Object016b9108 *FUN_00a29f30(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016b1d00));
    D_59458a4.lock();
    D_59458a8 = D_5827320;
    return new (memory) Object016b1d00(name);
}
