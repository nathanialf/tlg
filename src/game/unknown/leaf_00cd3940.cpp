/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00cd3940: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). After it, the build merges the stores at +0xe0 and +0xf0 into one 32-byte store and those at +0x104 and +0x108 into one 8-byte store, where the base stores +0xf0 to +0x108 apart and before them: their order in the source is not traced. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016d1b90.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5945de0]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_5945de0;

/* derived name: the creator of Object016d1b90, of FUN_002188b0's
 * signature (the first argument is not used): the object's 0x110 bytes
 * are allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place:
 * Object00ccfd00's constructor 0xccfbe0 a call with the kind 6, the
 * class's own inlined after it. */
Object016b9108 *FUN_00cd3940(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016d1b90));
    D_59458a4.lock();
    D_59458a8 = D_5945de0;
    return new (memory) Object016d1b90(name);
}
