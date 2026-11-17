/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016c81c0.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x57c9270]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_57c9270;

/* derived name: the creator of Object016c6610, of FUN_002188b0's signature (the first
 * argument is not used): the object's 0x98 bytes are allocated, the creation
 * lock taken, the type's record left for Object016b9108's constructor, and
 * the object constructed in place: the base's constructor 0xd68470 is called
 * out of line, then the class's vptr stored. */
Object016b9108 *FUN_001b8610(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016c6610));
    D_59458a4.lock();
    D_59458a8 = D_57c9270;
    return new (memory) Object016c6610(name);
}
