/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_object05945a38.h"
#include "tlg_game_registry00cb8240.h"

/* derived names: the object of a type under a name (tlg_game_object05945a38.h
 * describes it). The name is copied for the call (`lock inc` at 0xcbc5e1,
 * released at 0xcbc7ed), so a caller's temporary is only read. The made
 * object's name at +0xc is passed by address. */
// NONMATCHING: 640 bytes for 666. The usable test is the base's (the word read before the
// thread-local's address, `mov al; xor al, 1; test al, 1`); the registers differ from the
// start (the base keeps the mode in r8d and the copy's index in ebx, spilling the flags word).
// (2) the flag at 0x16dc089 is saved and put back without the base's `and r14b, 1` (not a
// local-data row: the proof refuses a masked copy put back). (3) the early return joins the
// name's release behind its test, where the base enters it with the index known
Object016b9108 *FUN_00cbc5a0(Object05945a38 *owner, Type00503fb0 *type, const Name &name, int mode)
{
    if (!type)
        return 0;
    Name copy(name);
    if (copy.index) {
        Object016b9108 *named = static_cast<Object016b9108 *>(D_17ac870[copy.index].record18);
        if (named && ((named->flags16 & 4) || D_16dc098)) {
            if (mode != 1)
                return named->type == type ? named : 0;
            FUN_00cbc2d0(owner, named, Name());
        }
    }
    ScopedLock05945a38 lock(&owner->lock201028);
    Object016b9108 *object = 0;
    Object016b9108 *(*create)(Type00503fb0 *type, const Name *name) = type->create;
    if (create) {
        Owner05943280 *heap = D_16dc090;
        if (!heap) {
            heap = D_5943280[0];
            D_16dc090 = heap;
        }
        D_16dc090 = D_5943280[1];
        bool making = D_16dc089;
        D_16dc089 = true;
        Object016b9108 *made = create(type, &copy);
        D_16dc089 = making;
        if (type->listener)
            type->listener->created(made);
        D_16dc090 = heap;
        if (made) {
            FUN_00cbb990(owner, type, made, &made->name);
            object = made;
        }
    }
    return object;
}
