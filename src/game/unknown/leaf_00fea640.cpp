/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: lets go of the two objects the owner refers to at +0x1d0
 * and +0x1d8: each one's pointer at +0xa0 (back to the owner, by this use)
 * is cleared first, then the reference emptied. The classes are not traced. */
class Target00fea640 : public Node00503fb0 /* derived name */
{
  public:
    u8 unknown68[0x38];
    void *ownera0; /* +0xa0 */
};

struct Object00fea640 { /* derived name */
    u8 unknown0[0x1d0];
    AtomicRef0045c470<Target00fea640> first;  /* +0x1d0 */
    AtomicRef0045c470<Target00fea640> second; /* +0x1d8 */
};

void FUN_00fea640(Object00fea640 *self) /* derived name */
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
