/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: lets go of the two objects the owner refers to at +0x1d0
 * and +0x1d8: each one's pointer at +0xa0 (back to the owner, by this use)
 * is cleared first, then the reference emptied. The classes are not traced:
 * the objects are counted objects of the root class, of no class traced
 * further (their +0xa0 is inside a scene node's rows). */
class Target01256d10 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x7c];
    void *ownera0; /* +0xa0 */
};

struct Object01256d10 { /* derived name */
    u8 unknown0[0x1d0];
    AtomicRef0045c470<Target01256d10> first;  /* +0x1d0 */
    AtomicRef0045c470<Target01256d10> second; /* +0x1d8 */
};

/* OPEN (FINISHING rule 6): its callers declare it under another signature; with one signature
 * the link inlines it into 0 rowed callers where the base calls it (round 513D: cost 355 at the
 * link, over its threshold of 175: one signature changes no row) */
void FUN_01256d10(Object01256d10 *self) /* derived name */
{
    if (self->first.get()) {
        self->first.get()->ownera0 = 0;
        self->first.clear();
    }
    if (self->second.get()) {
        self->second.get()->ownera0 = 0;
        self->second.clear();
    }
}
