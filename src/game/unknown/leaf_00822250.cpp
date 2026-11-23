/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object013d35e0.h"

/* derived names: FUN_00822250 (called at 0x8221a7 and 0x822387) and
 * FUN_00822600 (called at 0x822457) each give up the pool their object's
 * reference at +0x240 or +0x250 holds (PoolRef01343090::shutdown(), inlined),
 * then pass the object to FUN_00c57220 (a tail call). The classes are not
 * traced. */
class Pool00822250 : public Pool01343090 /* derived name */
{
};

class Pool00822600 : public Pool01343090 /* derived name */
{
};

/* the class FUN_00c57220 is given the objects as: their base, not traced */
struct Object00c57220 { /* derived name */
};

void FUN_00c57220(Object00c57220 *object); /* derived name */

struct Object00822250 : Object00c57220 { /* derived name */
    u8 unknown0[0x240];
    PoolRef01343090<Pool00822250> pool240; /* +0x240 */
};

struct Object00822600 : Object00c57220 { /* derived name */
    u8 unknown0[0x250];
    PoolRef01343090<Pool00822600> pool250; /* +0x250 */
};

/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 370 at the
 * link, over its threshold of 175: one signature changes no row) */
void FUN_00822250(Object00822250 *self) /* derived name */
{
    self->pool240.shutdown();
    FUN_00c57220(self);
}

/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 370 at the
 * link, over its threshold of 175: one signature changes no row) */
void FUN_00822600(Object00822600 *self) /* derived name */
{
    self->pool250.shutdown();
    FUN_00c57220(self);
}
