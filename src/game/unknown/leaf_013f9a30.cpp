/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_block.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16d5548 (config/vtables.derived.base.txt): it stores the vtable and releases
 * the block the pointer at +0x18 holds (tlg_game_block.h). The destructor is
 * the class's key function, so this file emits the vtable; the deleting one
 * is the compiler's. The other members are not traced. */
class Object013f9a30 /* derived name */
{
  public:
    virtual ~Object013f9a30();

  private:
    u8 unknown8[0x10];
    void *unknown18; /* +0x18: owned block */
};

Object013f9a30::~Object013f9a30()
{
    releaseBlock(unknown18);
}
