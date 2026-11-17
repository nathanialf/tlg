/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016b9108_inline.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5822320]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_5822320;

/* derived name: the creator of Object016cd510, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x70 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place: the
 * base's constructor 0xcb6310 is called out of line, the rest inlined. */
Object016b9108 *FUN_009959a0(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016cd510));
    D_59458a4.lock();
    D_59458a8 = D_5822320;
    return new (memory) Object016cd510(name);
}
