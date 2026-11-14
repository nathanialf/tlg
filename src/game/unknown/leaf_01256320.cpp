/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: gives up what the owner holds: the two references at
 * +0x1d0 and +0x1d8 emptied, then the object at +0x1e8, the block at +0x220
 * and the object at +0x228 deleted, each pointer cleared behind its own
 * test. The classes are not traced. */
class Target01256320 : public Node00503fb0 /* derived name */
{
};

/* deleted through slot 1 of its vtable */
class Part01256320 /* derived name */
{
  public:
    virtual ~Part01256320();
};

struct Block01256320 { /* derived name */
};

struct Object01256320 { /* derived name */
    u8 unknown0[0x1d0];
    AtomicRef0045c470<Target01256320> first;  /* +0x1d0 */
    AtomicRef0045c470<Target01256320> second; /* +0x1d8 */
    u8 unknown1e0[0x8];
    Part01256320 *part1e8; /* +0x1e8 */
    u8 unknown1f0[0x30];
    Block01256320 *block220; /* +0x220 */
    Part01256320 *part228;   /* +0x228 */
};

void FUN_01256320(Object01256320 *self) /* derived name */
{
    self->first.clear();
    self->second.clear();
    if (self->part1e8) {
        delete self->part1e8;
        self->part1e8 = 0;
    }
    if (self->block220) {
        delete self->block220;
        self->block220 = 0;
    }
    if (self->part228) {
        delete self->part228;
        self->part228 = 0;
    }
}
