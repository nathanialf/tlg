/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_block.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16cb4b0 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_006703a0): it stores the vtable, releases the heap block it owns at
 * +0x248 (tlg_game_block.h), then tail-calls its base's destructor
 * (0x822190). FUN_006708b0, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. The other members are
 * not traced. */
class Object00822190 /* derived name */
{
  public:
    virtual ~Object00822190();
};

class Object016cb4b0 : public Object00822190 /* derived name */
{
  public:
    virtual ~Object016cb4b0();

  private:
    u8 unknown8[0x240];
    void *block248; /* +0x248 */
};

Object016cb4b0::~Object016cb4b0()
{
    releaseBlock(block248);
}
