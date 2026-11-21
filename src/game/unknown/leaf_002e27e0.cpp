/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_002e27e0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016a8228.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x57cbd90]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_57cbd90;

/* derived name: the creator of Object016a8228, of FUN_002188b0's shape and
 * signature (the first argument is not used): the object's 0x440 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place by its
 * constructor FUN_002e2940, which is not inlined. */
Object016b9108 *FUN_002e27e0(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016a8228));
    D_59458a4.lock();
    D_59458a8 = D_57cbd90;
    return new (memory) Object016a8228(name);
}

/* NONMATCHING FUN_002e2940: the base stores the int at +0x7c alone (`mov dword [rbx+0x7c], 0`) and clears +0x80 to +0x98 with one 16-byte and one 8-byte store; the build merges +0x7c to +0x98 into one 28-byte clear (two overlapping 16-byte stores). */
/* NONMATCHING FUN_002e6bd0: the base's clear(16) is a copy of this unit's with the 16 propagated (`cmp dword [r14+0xc], 0x10`); the module shares Array05943280<Ref00503fb0<Object016b9108>>::clear(unsigned) (0x138c8d0's), whose argument stays a register. */
/* FUN_002e2940: the fields set in order, the arrays at +0x68 and +0x88 then
 * emptied to a capacity of 16, out of line (FUN_002e6bd0: a call, then the
 * second as a tail call) */
Object016a8228::Object016a8228(const Name &name)
    : Object016b9108(name), unknown24(0), unknown80(0), unknown418(0), unknown438(0)
{
    unknown68.clear(16);
    unknown88.clear(16);
}
