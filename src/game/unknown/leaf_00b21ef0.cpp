/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_00b21ef0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_creation.h"

/* derived names: sets the float at +0x290 of the object a holder points to,
 * under that object's spin lock at +0x294 (the lock's address taken once,
 * `lea r15, [rcx+0x294]`, the object read again for the store); reached by
 * the tail call at 0xb21905 with the holder at +0x108 of the caller's
 * object. The classes and the value are not traced. */
struct Object00b21ef0 { /* derived name */
    u8 unknown0[0x290];
    float unknown290;  /* +0x290 */
    Lock059458a4 lock; /* +0x294 */
};

struct Holder00b21ef0 {     /* derived name */
    Object00b21ef0 *object; /* +0x0 */
};

void FUN_00b21ef0(Holder00b21ef0 *self, float value) /* derived name */
{
    Lock059458a4 &lock = self->object->lock;
    lock.lock();
    self->object->unknown290 = value;
    lock.unlock();
}
