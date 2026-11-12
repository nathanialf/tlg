/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"

/* derived names: a handler whose address FUN_0058d410, FUN_00aec5d0,
 * FUN_00be6da0 and FUN_00c10ac0 take (lea at 0x58d4a5, 0xaef9ce, 0xbe7743
 * and 0xc10c22): makes its argument the owner's current node
 * (Owner583950::select), then dispatches the nodes at +0x28 and +0x30 of its
 * argument through the owner's handler table, in that order; returns 0.
 * Handler unknown. */
// NONMATCHING: the base widens the search index to 64 bits from a zero-extended start (`mov rcx, r9`);
// Owner583950::find with an unsigned index keeps it 32 bits (`mov eax, ecx` each pass), with an int
// index it widens from a sign-extended start (movsxd): the shape of 0x58da20's residual (round 217C)
int FUN_00c060d0(Owner583950 *self, void *arg) /* derived name */
{
    self->select(arg);
    self->dispatch(static_cast<Node583950 *>(arg)->child);
    self->dispatch(static_cast<Node583950 *>(arg)->child30);
    return 0;
}
