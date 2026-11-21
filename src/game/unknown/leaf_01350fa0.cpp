/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_01350fa0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
/* NONMATCHING FUN_01352bb0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_creation.h"
#include "tlg_math.h"

/* derived names: two values of four floats of one object, each read under
 * the spin lock at +0x2c and copied to the caller's value (`vmovups` of
 * +0x140 and of +0x120 into [rdi], the object in rsi; nothing returned):
 * FUN_01350fa0 (called at 0x457792 and 0x48695b) and FUN_01352bb0 (0x484ccd,
 * 0x489777, 0x4ad1f1 and more). The class is not traced. The values are
 * 16-byte aligned: other functions read +0x120 with `vmovaps` (0x457782),
 * the callers' values sit on 16-byte boundaries and are read back with
 * `vmovaps` (0x484cd2; FUN_004ad230 is equal only so); the copies here are
 * `vmovaps` in the build where the base has `vmovups`, a second residual. */
struct Object01350fa0 { /* derived name */
    u8 unknown0[0x2c];
    Lock059458a4 lock; /* +0x2c */
    u8 unknown30[0xf0];
    Float4A unknown120; /* +0x120 */
    u8 unknown130[0x10];
    Float4A unknown140; /* +0x140 */
};

void FUN_01350fa0(Float4A &value, Object01350fa0 *self) /* derived name */
{
    self->lock.lock();
    value = self->unknown140;
    self->lock.unlock();
}

void FUN_01352bb0(Float4A &value, Object01350fa0 *self) /* derived name */
{
    self->lock.lock();
    value = self->unknown120;
    self->lock.unlock();
}
