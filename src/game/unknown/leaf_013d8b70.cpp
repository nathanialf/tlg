/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_block.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16d3dd0 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00f71bc0): it stores the vtable, runs the class's FUN_013d8be0 on the object,
 * then releases the heap block it owns at +0x8 (tlg_game_block.h). It has no
 * base. FUN_013d9060, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. The other members are not
 * traced. */
class Object016d3dd0 /* derived name */
{
  public:
    virtual ~Object016d3dd0();
    void FUN_013d8be0(); /* derived name */

  private:
    void *block8; /* +0x8 */
};

Object016d3dd0::~Object016d3dd0()
{
    FUN_013d8be0();
    releaseBlock(block8);
}
