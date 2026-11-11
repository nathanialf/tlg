/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_name.h"

/* derived names: the complete destructor of the class whose vtable is at
 * 0x16b2560 (config/vtables.derived.base.txt, stored by its constructor
 * FUN_00a83f20): it stores the vtable, releases its Name at +0x580, then
 * tail-calls its base's destructor (0x83df00). FUN_0138e0d0, slot 1, is the
 * deleting one. The destructor is the class's key function, so this file
 * emits the vtable. The other members are not traced. */
class Object0083df00 /* derived name */
{
  public:
    virtual ~Object0083df00();
};

class Object016b2560 : public Object0083df00 /* derived name */
{
  public:
    virtual ~Object016b2560();

  private:
    u8 unknown8[0x578];
    Name name580; /* +0x580 */
};

Object016b2560::~Object016b2560() {}
