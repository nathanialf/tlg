/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00879380: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). After it, reset() (FUN_01372870) is inlined here by the link while the base calls it: its other callers, FUN_00885840 and FUN_00886300, are not written. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016cc308.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x581e420]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_581e420;

/* derived name: the creator of Object016cc308, of FUN_002188b0's signature
 * (the first argument is not used): the object's 0x50 bytes are allocated,
 * the creation lock taken, the type's record left for Object016b9108's
 * constructor, and the object constructed in place: the root's constructor
 * 0xcb6310 and the class's reset() FUN_01372870 are calls. */
Object016b9108 *FUN_00879380(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016cc308));
    D_59458a4.lock();
    D_59458a8 = D_581e420;
    return new (memory) Object016cc308(name);
}
