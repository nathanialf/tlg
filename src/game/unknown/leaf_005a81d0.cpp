/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016ab968.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x57fcd80]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_57fcd80;

/* derived name: the creator of Object016ab968, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x30 bytes
 * are allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place. This
 * unit creates the object, so it emits the class's vtable and its two
 * destructors (FUN_005aac20 and FUN_005aace0, defined in the header). */
// NONMATCHING: 83/86, 341 bytes for 341: the base stores the name and -1.0 as one 8-byte value
// (`movabs rdx, 0xbf80000000000000; mov [r15+0x24], rdx`) and 0.5 alone; the build pairs the two
// floats (`mov dword [r15+0x24], 0; mov [r15+0x28], rdx`): the last store of a run is visited first
// and two floats next to each other merge before the name can. The base's pairing is what the code
// generator gives when one of the two floats reaches it as an integer store (a one-float value
// assigned whole: measured, equal); which of the two, and its type, is not traced
Object016b9108 *FUN_005a81d0(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016ab968));
    D_59458a4.lock();
    D_59458a8 = D_57fcd80;
    return new (memory) Object016ab968(name);
}
