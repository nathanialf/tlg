/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016a7d48.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x57cb368]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_57cb368;

/* derived name: the creator of Object016a7d48, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x60 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place by its
 * constructor FUN_002a89e0, which is not inlined. */
// NONMATCHING: the whole module inlines the constructor FUN_002a89e0 (195 bytes) here, the base calls it: a call inlined across units where the base keeps it (the two-stage question)
Object016b9108 *FUN_002a8880(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016a7d48));
    D_59458a4.lock();
    D_59458a8 = D_57cb368;
    return new (memory) Object016a7d48(name);
}
