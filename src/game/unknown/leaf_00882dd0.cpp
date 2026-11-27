/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00882dd0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
/* Round 582D (scratch d582): an exchange written as an inline function whose body is `lock cmpxchg` (eax out, or its own sete) gives no pushfq anywhere in the module: the flags copied are a compiler exchange's. */
#include "tlg_game_creation.h"

/* derived names: slot 12 of the vtable at 0x16af2d8 (its pointer at
 * 0x16af348): sets the byte at +0x214 under the spin lock at +0x21c. The
 * class and what the byte means are not traced. */
struct Object00882dd0 { /* derived name */
    u8 unknown0[0x214];
    bool unknown214; /* +0x214 */
    u8 unknown215[0x7];
    Lock059458a4 lock; /* +0x21c */
};

void FUN_00882dd0(Object00882dd0 *self) /* derived name */
{
    self->lock.lock();
    self->unknown214 = true;
    self->lock.unlock();
}
