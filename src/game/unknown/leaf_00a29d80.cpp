/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016b1cc0.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5827318]; mov [0x59458a8], rax` before the
 * constructor's call) */
extern Type059458a8 *D_5827318;

/* derived name: the creator of Object016b1cc0, registered with its type
 * through FUN_00cbb0e0 by FUN_00a2b8c0 (lea at 0xa2d6a8), whose signature it
 * keeps: the first argument is not used. The object's 0x70 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place, its
 * constructor and its base's inlined. */
// NONMATCHING: 90/97, 407 bytes: the base's constructor part equal; the base merges +0x50 and +0x54 into one qword after the
// Names at +0x58, +0x64, +0x68 (the build leaves them two stores: +0x54's store is followed by the float pair, so it ends no
// store sequence for the DAG's merge); with +0x5c and +0x60 as ints the vectoriser makes +0x50..+0x5c one vector (round 314A)
Object016b9108 *FUN_00a29d80(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016b1cc0));
    D_59458a4.lock();
    D_59458a8 = D_5827318;
    return new (memory) Object016b1cc0(name);
}
