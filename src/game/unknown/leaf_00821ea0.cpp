/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016aea40.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x581b928]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_581b928;

/* derived name: the creator of Object016aea40, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x250 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place: the
 * base's constructor 0xc55320 is called out of line, the rest inlined. */
Object016b85e0 *FUN_00821ea0(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016aea40));
    D_59458a4.lock();
    D_59458a8 = D_581b928;
    return new (memory) Object016aea40(name);
}
