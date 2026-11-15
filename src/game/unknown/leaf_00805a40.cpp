/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016ae220.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x581a398]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_581a398;

/* derived name: the creator of Object016ae220, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x40 bytes
 * are allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place. This
 * unit creates the object, so it emits the class's vtable and its two
 * destructors (FUN_00805bb0 and FUN_00805ca0, defined in the header). */
Object016b9108 *FUN_00805a40(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016ae220));
    D_59458a4.lock();
    D_59458a8 = D_581a398;
    return new (memory) Object016ae220(name);
}
