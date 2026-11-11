/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_block.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16d1fa8 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00cf9e30): it stores the vtable, releases the heap block it owns at
 * +0xc8 (tlg_game_block.h), then tail-calls its base's destructor
 * (0xcf7fb0). FUN_013b36d0, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. The other members are
 * not traced. */
class Object00cf7fb0 /* derived name */
{
  public:
    virtual ~Object00cf7fb0();
};

class Object016d1fa8 : public Object00cf7fb0 /* derived name */
{
  public:
    virtual ~Object016d1fa8();

  private:
    u8 unknown8[0xc0];
    void *blockc8; /* +0xc8 */
};

Object016d1fa8::~Object016d1fa8()
{
    releaseBlock(blockc8);
}
