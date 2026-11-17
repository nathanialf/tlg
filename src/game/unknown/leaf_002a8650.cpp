/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016a7ce8.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x57cb228]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_57cb228;

/* derived name: the creator of Object016a7ce8, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x240 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place: the
 * base's constructor 0xc55320 is called out of line, the rest inlined. */
Object016b85e0 *FUN_002a8650(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016a7ce8));
    D_59458a4.lock();
    D_59458a8 = D_57cb228;
    return new (memory) Object016a7ce8(name);
}
