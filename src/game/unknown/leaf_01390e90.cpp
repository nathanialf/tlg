/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b4ce0.h"

/* derived name: the entries walked from the first to the end (`shl rcx, 3`
 * on the count, then `add rdx, 8; add rcx, -8; jne`). It is Object016b4ce0's
 * search for an entry by name, written as a free friend function only
 * because the layout places an unrowed callee by its FUN_<addr> name and a
 * member draft has none (round 572C): when it is a row it returns to a
 * member of the class. */
// NONMATCHING: 290 bytes against 314, the exits' copies: the return's phi now has the base's six
// edges from the exchange's release (the object returned as the arrays hold it, no cast to sink: with
// Entry016b4ce0 * the cast is sunk into each predecessor by CodeGenPrepare and its copies are killed
// there, so PHIElimination split no edge), and each split edge holds its `mov rax, rbx`; the post-RA
// tail merge (BranchFolding.cpp:569-573) then joins them with the release's last block, the return's
// layout predecessor (`call 0xc14bc0; mov rax, rbx`), where the base keeps six `mov rax, rbx; jmp`.
// So in the base something else falls into the return before placement; the lead is the loop's
// latch, which LoopRotate's simplifyLoopLatch folds into the body here (the increment speculated, the
// latch left at the header's place, LoopRotation.cpp shouldSpeculateInstrs), the base's latch after
// the release. Forms compiled this round: an index loop (movsxd, worse), a counter beside the
// pointer (`++i, ++at`: LSR keeps the index, 290 bytes), the end cached, the search before the
// exchange with `at` tested after the loop (322 bytes), `return at->get()` (a reload).
Object016b9108 *FUN_01390e90(Object016b4ce0 *self, const Name &name) /* derived name */
{
    Object016b9108 *found = self->found10.get();
    if (found != 0 && Entry016b4ce0::of(found)->name310 == name.index)
        return found;
    for (const Ref00503fb0<Object016b9108> *at = self->entries.begin(); at != self->entries.end();
         ++at) {
        Object016b9108 *object = at->get();
        if (Entry016b4ce0::of(object)->name310 == name.index) {
            self->found10.set(object);
            return object;
        }
    }
    return 0;
}
