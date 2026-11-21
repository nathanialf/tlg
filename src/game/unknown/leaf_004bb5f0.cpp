/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_004bb5f0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_array01343a80.h"
#include "tlg_game_name.h"

/* derived names: makes an array of Names a copy of another, under the
 * other's lock (tlg_game_array.h's assignment: the target emptied to the
 * other's count by FUN_01344d90, then each Name copied with its reference).
 * Called five times from FUN_004b8c60 (0x4b9287 to 0x4b92d6). FUN_00464d20 is the same body. */
void FUN_004bb5f0(Array01343a80<Name> *names, Array01343a80<Name> *other) /* derived name */
{
    other->lock.lock();
    *names = *other;
    other->lock.unlock();
}
