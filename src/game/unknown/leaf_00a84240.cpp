/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object00c19c80.h"

/* derived names: the class whose vtable is at 0x16b26f8
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00a840b0
 * and its complete destructor FUN_00a84240), derived from Object00c19c80:
 * five Names from +0x44. The destructor's body is empty; the Names are
 * released, last first, then the base's destructor 0xc19c80 runs as a tail
 * call. FUN_00a84360, slot 1, is the deleting one. The destructor is the
 * class's key function, so this file emits the vtable. The other members
 * are not traced. */
class Object016b26f8 : public Object00c19c80 /* derived name */
{
  public:
    virtual ~Object016b26f8();

  private:
    u8 unknown30[0x14];
    Name name44; /* +0x44 */
    Name name48; /* +0x48 */
    Name name4c; /* +0x4c */
    Name name50; /* +0x50 */
    Name name54; /* +0x54 */
};

Object016b26f8::~Object016b26f8() {}
