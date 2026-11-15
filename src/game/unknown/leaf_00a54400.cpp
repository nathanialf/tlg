/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016ce378.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5827ec0]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_5827ec0;

/* derived name: the creator of Object016ce378, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x60 bytes
 * are allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place. This
 * unit creates the object, so it emits the class's vtable and its two
 * destructors (FUN_0138cf00 and FUN_0138d020, defined in the header). */
// NONMATCHING: 373 bytes for 355: the last four floats (+0x44 to +0x50) are four scalar stores
// where the base has one 16-byte store from the constants at 0x153cd40: the vectoriser takes a
// chain at its first width that fits and leaves the rest (twelve floats: eight, then four
// scalars); a second run over what the first left would take the four
Object016b9108 *FUN_00a54400(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016ce378));
    D_59458a4.lock();
    D_59458a8 = D_5827ec0;
    return new (memory) Object016ce378(name);
}
