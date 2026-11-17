/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016aa098.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x57d76f8]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_57d76f8;

/* derived name: the creator of Object016aa098, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x90 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place. */
// NONMATCHING: the base stores 4.0 at +0x44 alone and +0x48/+0x4c as one eight-byte store; this build merges +0x44 with +0x48 and stores +0x4c alone (init list or body alike)
Object016b9108 *FUN_004adaf0(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016aa098));
    D_59458a4.lock();
    D_59458a8 = D_57d76f8;
    return new (memory) Object016aa098(name);
}
