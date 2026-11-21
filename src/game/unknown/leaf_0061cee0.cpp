/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_0061cee0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016cb378.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x580f6a8]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_580f6a8;

/* derived name: the creator of Object016cb378, registered with its type
 * through FUN_00cbb0e0 by FUN_0061d140 (lea at 0x622f47), whose signature it
 * keeps: the first argument is not used. The object's 0x138 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place, its
 * constructor inlined. */
Object016b9108 *FUN_0061cee0(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016cb378));
    D_59458a4.lock();
    D_59458a8 = D_580f6a8;
    return new (memory) Object016cb378(name);
}
