/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object016b85e0.h"

/* derived names: the class whose vtable is at 0x16b2c50
 * (config/vtables.derived.base.txt), derived from Object016b85e0: three Names (+0x23c, +0x248,
 * +0x278).
 * Its complete destructor FUN_00a99f90 releases them in reverse order, then
 * tail-calls the base's destructor 0xc55550; FUN_00a9a070, slot 1, is the deleting
 * one. The destructor is the class's key function, so this file emits the
 * vtable. The other members are not traced. */
class Object016b2c50 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016b2c50();

  private:
    u8 unknown238[0x4];
    Name name23c; /* +0x23c */
    u8 unknown240[0x8];
    Name name248; /* +0x248 */
    u8 unknown24c[0x2c];
    Name name278; /* +0x278 */
};

Object016b2c50::~Object016b2c50() {}
