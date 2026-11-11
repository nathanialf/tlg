/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16b2358 (config/vtables.derived.base.txt): it stores the vtable and releases
 * the block the pointer at +0x40 holds (tlg_game_block.h). The destructor is
 * the class's key function, so this file emits the vtable; the deleting one
 * is the compiler's. The other members are not traced. */
class Object00a66790 /* derived name */
{
  public:
    virtual ~Object00a66790();

  private:
    u8 unknown8[0x38];
    void *unknown40; /* +0x40: owned block */
};

Object00a66790::~Object00a66790()
{
    releaseBlock(unknown40);
}
