/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"
#include "tlg_game_object05945a38.h"
#include "tlg_game_registry00cb8240.h"

/* derived names: the object of a type under a name (tlg_game_object05945a38.h
 * describes it). The name is copied for the call (`lock inc` at 0xcbc5e1,
 * released at 0xcbc7ed), so a caller's temporary is only read. The node's
 * name at +0xc is passed by address: Node00503fb0 does not declare it yet
 * (the root class of the named objects has three models in the tree). */
// NONMATCHING: 620 bytes for 666. (1) the usable test: the base tests the object's flag 4 first
// (the word read before the thread-local's address) and the thread's flag second (`mov al;
// xor al, 1; test al, 1`), the build the thread's flag first: Reassociate puts the lower rank
// first and the one-bit load of the shrunk flag ranks below the bit test; compiled alone (the
// flag a byte load and a compare) the two tie and the object's flag stays first. (2) the flag at
// 0x16dc089 is saved and put back without the base's `and r14b, 1` (not a local-data row: the
// proof refuses a masked copy put back). (3) the early return joins the name's release behind
// its test, where the base enters it with the index known
Node00503fb0 *FUN_00cbc5a0(Object05945a38 *owner, Type00503fb0 *type, const Name &name, int mode)
{
    if (!type)
        return 0;
    Name copy(name);
    if (copy.index) {
        Node00503fb0 *named = static_cast<Node00503fb0 *>(D_17ac870[copy.index].record18);
        if (named && isUsable(named)) {
            if (mode != 1)
                return named->type == type ? named : 0;
            FUN_00cbc2d0(owner, named, Name());
        }
    }
    ScopedLock05945a38 lock(&owner->lock201028);
    Node00503fb0 *object = 0;
    Node00503fb0 *(*create)(Type00503fb0 *type, const Name *name) = type->create;
    if (create) {
        Owner05943280 *heap = D_16dc090;
        if (!heap) {
            heap = D_5943280[0];
            D_16dc090 = heap;
        }
        D_16dc090 = D_5943280[1];
        bool making = D_16dc089;
        D_16dc089 = true;
        Node00503fb0 *made = create(type, &copy);
        D_16dc089 = making;
        if (type->listener)
            type->listener->created(made);
        D_16dc090 = heap;
        if (made) {
            FUN_00cbb990(owner, type, made, reinterpret_cast<const Name *>(made->unknownc));
            object = made;
        }
    }
    return object;
}
