/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00c20f80: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016b8300.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x59383d0]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_59383d0;

/* derived name: the creator of Object016b8300, registered with its type
 * through FUN_00cbb0e0 (lea at 0xc234c2), whose signature it keeps: the
 * first argument is not used. The object's 0xb0 bytes are allocated, the
 * creation lock taken, the type's record left for Object016b9108's
 * constructor, and the object constructed in place, its constructor
 * inlined. */
Object016b9108 *FUN_00c20f80(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016b8300));
    D_59458a4.lock();
    D_59458a8 = D_59383d0;
    return new (memory) Object016b8300(name);
}
