/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: slots 9 and 10 of the vtables at 0x16a9ba8 and 0x16b2930,
 * over slots 9 and 10 of the vtables at 0x16a9990 and 0x16a9a38
 * (FUN_0042d100, FUN_0042d380), which each ends with: the object the holder
 * at +0x310 refers to (+0x28), taken as a counted reference for the test
 * alone, is handed to FUN_01367fa0, as FUN_007204a0 hands its two. The
 * classes are not traced. */
struct Holder00a8d620 { /* derived name */
    u8 unknown0[0x28];
    Object016b9108 *target28; /* +0x28 */

    Ref00503fb0<Object016b9108> target() const /* derived name */
    {
        return Ref00503fb0<Object016b9108>(target28);
    }
};

struct Object00a8d620 { /* derived name */
    u8 unknown0[0x310];
    Holder00a8d620 *holder310; /* +0x310 */
};

void FUN_01367fa0(Object016b9108 *target); /* derived name */
void FUN_0042d100(Object00a8d620 *self);   /* derived name */
void FUN_0042d380(Object00a8d620 *self);   /* derived name */

static inline void releaseTarget(Object00a8d620 *self) /* derived name */
{
    if (Holder00a8d620 *holder = self->holder310) {
        if (Object016b9108 *target = holder->target().get())
            FUN_01367fa0(target);
    }
}

// NONMATCHING: 27/54, 172 bytes against 193: the base tests the target for null again after the
// temporary reference's release (`test r15, r15; je` before the call) and holds the object in r14,
// the target in r15; the build folds the third test. Same with the target set under the holder's test
// and tested after it.
void FUN_00a8d620(Object00a8d620 *self) /* derived name */
{
    releaseTarget(self);
    FUN_0042d100(self);
}

// NONMATCHING: as FUN_00a8d620
/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 215 at the
 * link, over its threshold of 175: one signature changes no row) */
void FUN_00a8d6f0(Object00a8d620 *self) /* derived name */
{
    releaseTarget(self);
    FUN_0042d380(self);
}
