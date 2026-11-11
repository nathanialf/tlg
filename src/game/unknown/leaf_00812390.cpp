/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_block.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16ae5d0 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_001bd010): it stores the vtable, runs
 * FUN_013b2e90 on its member at +0x10 (written as a free function on its
 * record), then releases the heap block it owns at +0x28
 * (tlg_game_block.h). It has no base. FUN_00812400, slot 1, is the deleting
 * one. The destructor is the class's key function, so this file emits the
 * vtable. The other members are not traced. */
struct Object013b2e90 /* derived name */
{
    u8 unknown0[0x18];
};

void FUN_013b2e90(Object013b2e90 *self); /* derived name */

class Object016ae5d0 /* derived name */
{
  public:
    virtual ~Object016ae5d0();

  private:
    u8 unknown8[0x8];
    Object013b2e90 unknown10; /* +0x10 */
    void *block28;            /* +0x28 */
};

Object016ae5d0::~Object016ae5d0()
{
    FUN_013b2e90(&unknown10);
    releaseBlock(block28);
}
