/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_block.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16c7598 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_003442a0): it stores the vtable, releases the heap block it owns at
 * +0x248 (tlg_game_block.h), then tail-calls its base's destructor
 * (0x822190). FUN_0134d3d0, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. The other members are
 * not traced. */
class Object00822190 /* derived name */
{
  public:
    virtual ~Object00822190();
};

class Object016c7598 : public Object00822190 /* derived name */
{
  public:
    virtual ~Object016c7598();

  private:
    u8 unknown8[0x240];
    void *block248; /* +0x248 */
};

Object016c7598::~Object016c7598()
{
    releaseBlock(block248);
}
