/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
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

/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 335 at the
 * link, over its threshold of 175: one signature changes no row) */
void FUN_006182f0(Object006182f0 *self) /* derived name */
{
    self->pool28.shutdown();
}
