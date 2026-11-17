/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016b9108_inline.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x58222f8]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_58222f8;

/* derived name: the creator of Object016cd3f8, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0xb0 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place: the
 * base's constructor 0xcb6310 is called out of line, the rest inlined. */
// NONMATCHING: the base reads the value at 0x58224c0 eight bytes at a time between its stores (the second half after +0x60 and +0x64 are stored); this build reads both halves first
Object016b9108 *FUN_00991bf0(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016cd3f8));
    D_59458a4.lock();
    D_59458a8 = D_58222f8;
    return new (memory) Object016cd3f8(name);
}
