/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include <new>

#include "tlg_game_creation.h"
#include "tlg_game_object016ba510.h"

/* derived name: the record of the class's type, left for Object016b9108's
 * constructor (`mov rax, [0x5948c38]; mov [0x59458a8], rax` before the
 * base's constructor) */
extern Type059458a8 *D_5948c38;

/* derived name: the creator of Object016ba510, registered with its type
 * through FUN_00cbb0e0 by FUN_00e10cd0 (lea at 0xe358d8), whose signature it
 * keeps: the first argument is not used. The object's 0x290 bytes are
 * allocated, the creation lock taken, the type's record left for
 * Object016b9108's constructor, and the object constructed in place, its
 * constructor inlined. */
// NONMATCHING: whole module, every instruction the base's but one store's place: the five references' clear (+0x240, one
// memset) comes after the float pair at +0x26c (the clear's scan runs on to the 1.0 at +0x274 and the memset is placed there),
// so the pair's merged store is scheduled before it; the base stores the pair after +0x260 (round 314A)
Object00c55550 *FUN_00d48670(void *, const Name &name)
{
    void *memory = operator new(sizeof(Object016ba510));
    D_59458a4.lock();
    D_59458a8 = D_5948c38;
    return new (memory) Object016ba510(name);
}
