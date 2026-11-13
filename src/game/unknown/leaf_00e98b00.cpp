/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_block.h"
#include "tlg_game_object00c55550.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16be430 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00e988c0): it stores the vtable, releases the heap block it owns at
 * +0x258 (tlg_game_block.h), then tail-calls its base's destructor
 * (0xc55550). FUN_00e98b70, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. The other members are
 * not traced. */
class Object016be430 : public Object00c55550 /* derived name */
{
  public:
    virtual ~Object016be430();

  private:
    u8 unknown8[0x250];
    void *block258; /* +0x258 */
};

Object016be430::~Object016be430()
{
    releaseBlock(block258);
}
