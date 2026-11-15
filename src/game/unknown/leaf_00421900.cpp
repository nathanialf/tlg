/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016cacb8.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x57d3a90]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_57d3a90;

/* derived name: the creator of Object016cacb8, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x50 bytes
 * are allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place. This
 * unit creates the object, so it emits the class's vtable and its two
 * destructors (FUN_01350410 and FUN_01350530, defined in the header). */
// NONMATCHING: 89 of 98, 387 bytes for 387: the stack guard's address is loaded one store
// earlier in the base (before the store at +0x48, after the last use of the first value's high
// half) and the registers of the two halves follow (rdx and rcx the other way round): the
// scheduler's order
Object016b9108 *FUN_00421900(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016cacb8));
    D_59458a4.lock();
    D_59458a8 = D_57d3a90;
    return new (memory) Object016cacb8(name);
}
