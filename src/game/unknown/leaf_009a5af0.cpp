/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_009a5af0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). After it, the base copies D_5822b10 to the five records with two 8-byte loads and four 4-byte stores each where this build makes 16-byte copies. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016cde78.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5822340]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_5822340;

/* derived name: the creator of Object016cde78, of FUN_002188b0's
 * signature (the first argument is not used): the object's 0x170 bytes
 * are allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place: the
 * root's constructor 0xcb6310 a call, the class's own inlined after it. */
Object016b9108 *FUN_009a5af0(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016cde78));
    D_59458a4.lock();
    D_59458a8 = D_5822340;
    return new (memory) Object016cde78(name);
}
