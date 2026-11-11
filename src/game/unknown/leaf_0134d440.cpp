/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_block.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16a87b8 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00344670): it stores the vtable, releases the heap block it owns at
 * +0x260 (tlg_game_block.h), then tail-calls its base's destructor
 * (0x822440). FUN_0134d4b0, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. The other members are
 * not traced. */
class Object00822440 /* derived name */
{
  public:
    virtual ~Object00822440();
};

class Object016a87b8 : public Object00822440 /* derived name */
{
  public:
    virtual ~Object016a87b8();

  private:
    u8 unknown8[0x258];
    void *block260; /* +0x260 */
};

Object016a87b8::~Object016a87b8()
{
    releaseBlock(block260);
}
