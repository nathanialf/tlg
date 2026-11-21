/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00464d20: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"

/* derived names: makes an array of Names a copy of another, under the
 * other's lock (tlg_game_array.h's assignment: the target emptied to the
 * other's count by FUN_01344d90, then each Name copied with its reference).
 * Called five times from FUN_004315b0 (0x431a31 to 0x431a7b). FUN_004bb5f0 is the same body. */
void FUN_00464d20(Array01343a80<Name> *names, Array01343a80<Name> *other) /* derived name */
{
    other->lock.lock();
    *names = *other;
    other->lock.unlock();
}
