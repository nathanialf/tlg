/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_block.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16d4948 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00fba720): it stores the vtable, releases the heap block it owns at
 * +0x110 (tlg_game_block.h), then tail-calls its base's destructor
 * (0x13e1ea0). FUN_013e4a20, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. The other members are
 * not traced. */
class Object013e1ea0 /* derived name */
{
  public:
    virtual ~Object013e1ea0();
};

class Object016d4948 : public Object013e1ea0 /* derived name */
{
  public:
    virtual ~Object016d4948();

  private:
    u8 unknown8[0x108];
    void *block110; /* +0x110 */
};

Object016d4948::~Object016d4948()
{
    releaseBlock(block110);
}
