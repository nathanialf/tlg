/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: FUN_002db990 appends a counted reference to an array unless
 * the array holds one to the same object (tlg_game_array.h's addUnique),
 * out of line: the array's own member, instantiated here until a caller of
 * it is written (called at 0x2da26c, 0x2da9b1, 0x2daa12). FUN_005a42c0 is the same body. The referenced class is
 * not traced. */
class Value002db990 : public Object016b9108 /* derived name */
{
};

// NONMATCHING: the new slot's index: the base keeps the count it read as a value of its own
// after the search (`xor r15d, r15d` before it, `mov r15d, eax` on the not-found exit: 0 when
// the array is empty, else the count); the build stores at the search's own counter (this
// form) or reuses the count's register (contains() then the count raised: `test rbx, rbx`,
// pushUnique's shape, 0xce22e0). Three forms tried. Round 500C: the base's
// value is phi(0, count): the loop's exit value rewritten to the count, which
// IndVarSimplify does only with a computable backedge-taken count
// (ScalarEvolution::computeSCEVAtScope), not over this loop's early return;
// the search written `index != count` gives the phi through GVN's equality on
// the exit edge, but its exit test is `cmp eax, esi; jne` over a 64-bit guard
// (`test rax, rax`) where the base has `cmp esi, eax; jb`; with a `break` and
// `if (index != count) return;` the empty path is threaded apart. The same
// body is FUN_00871630, FUN_008e3410 and FUN_00d6dd50.
template void
Array05943280<Ref00503fb0<Value002db990>>::addUnique(const Ref00503fb0<Value002db990> &);
