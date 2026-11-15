/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016a7870.h"

/* derived name: the record FUN_00cbb0e0 returns when the class is registered
 * (`mov [0x57ca3d0], rax` at 0x2192b0, with this creator passed to it) */
extern Type059458a8 *D_57ca3d0;

/* derived name: the creator of Object016a7870, registered with its type
 * through FUN_00cbb0e0 (`lea rax, [0x2188b0]; mov [rsp], rax` at 0x219289),
 * whose signature it keeps: the first argument is not used. The object's 0x40
 * bytes are allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place. This
 * unit creates the object, so it emits the class's vtable and its two
 * destructors (FUN_0021bdf0 and FUN_0021bf10, defined in the header). */
Object016b9108 *FUN_002188b0(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016a7870));
    D_59458a4.lock();
    D_59458a8 = D_57ca3d0;
    return new (memory) Object016a7870(name);
}
