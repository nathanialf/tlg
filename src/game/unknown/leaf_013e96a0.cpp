/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16d50b0 (config/vtables.derived.base.txt): it stores the vtable and releases
 * the block the pointer at +0x8 holds (tlg_game_block.h). The destructor is
 * the class's key function, so this file emits the vtable; the deleting one
 * is the compiler's. The other members are not traced. */
class Object013e96a0 /* derived name */
{
  public:
    virtual ~Object013e96a0();

  private:
    void *unknown8; /* +0x8: owned block */
};

Object013e96a0::~Object013e96a0()
{
    releaseBlock(unknown8);
}
