/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_006182f0: the creation lock's wait loop: the base copies the exchange's flags (`pushfq; pop rax; push rax; popfq`) before the branch; no source form gives it and the barrier that did was removed (docs/DECISIONS.md D88). */
#include "tlg_game_object013d35e0.h"

/* derived names: a virtual method of two classes (its address in the
 * vtable at 0x16c7770, slot 14, and at 0x16abed8): gives up the pool the
 * object's reference at +0x28 holds (PoolRef01343090::shutdown(), inlined).
 * The classes are not traced. */
class Pool006182f0 : public Pool01343090 /* derived name */
{
};

struct Object006182f0 { /* derived name */
    u8 unknown0[0x28];
    PoolRef01343090<Pool006182f0> pool28; /* +0x28 */
};

void FUN_006182f0(Object006182f0 *self) /* derived name */
{
    self->pool28.shutdown();
}
