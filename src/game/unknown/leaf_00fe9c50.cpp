/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: gives up what the owner holds: the two references at
 * +0x1d0 and +0x1d8 emptied, then the object at +0x1e8, the block at +0x220
 * and the object at +0x228 deleted, each pointer cleared behind its own
 * test. The classes are not traced. */
class Target00fe9c50 : public Node00503fb0 /* derived name */
{
};

/* deleted through slot 1 of its vtable */
class Part00fe9c50 /* derived name */
{
  public:
    virtual ~Part00fe9c50();
};

struct Block00fe9c50 { /* derived name */
};

struct Object00fe9c50 { /* derived name */
    u8 unknown0[0x1d0];
    AtomicRef0045c470<Target00fe9c50> first;  /* +0x1d0 */
    AtomicRef0045c470<Target00fe9c50> second; /* +0x1d8 */
    u8 unknown1e0[0x8];
    Part00fe9c50 *part1e8; /* +0x1e8 */
    u8 unknown1f0[0x30];
    Block00fe9c50 *block220; /* +0x220 */
    Part00fe9c50 *part228;   /* +0x228 */
};

void FUN_00fe9c50(Object00fe9c50 *self) /* derived name */
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
