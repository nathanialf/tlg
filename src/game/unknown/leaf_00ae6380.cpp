/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00ae6380: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). After it, the base clears +0xc8, +0xcc, +0xd0 and +0xd4 with four 4-byte stores where this build makes them one 16-byte memset (MemCpyOpt at the unit stage). */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016ce980.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x582e578]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_582e578;

/* derived name: the creator of Object016ce980, of FUN_002188b0's
 * signature (the first argument is not used): the object's 0xd8 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place: the
 * root's constructor 0xcb6310 a call, the class's own inlined after it. */
Object016b9108 *FUN_00ae6380(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016ce980));
    D_59458a4.lock();
    D_59458a8 = D_582e578;
    return new (memory) Object016ce980(name);
}
