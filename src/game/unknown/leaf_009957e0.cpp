/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016b9108_inline.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5822318]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_5822318;

/* derived name: the creator of Object016cd4d8, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x90 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place: the
 * base's constructor 0xcb6310 is called out of line, the rest inlined. */
// NONMATCHING: the base stores +0x80/+0x84 (0.0, 45.0) as one eight-byte constant loaded first and +0x88 alone; this build stores +0x80 alone and merges +0x84 with +0x88
Object016b9108 *FUN_009957e0(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016cd4d8));
    D_59458a4.lock();
    D_59458a8 = D_5822318;
    return new (memory) Object016cd4d8(name);
}
