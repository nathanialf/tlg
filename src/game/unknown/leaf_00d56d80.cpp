/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16ba7c0
 * (config/vtables.derived.base.txt; its constructor FUN_00d56c70), derived
 * from Object016b9108: a counted reference at +0x38 and a name at +0x40,
 * released after its destructor's body has called FUN_00d56ed0 on the
 * object. FUN_00d57040, slot 1, is the deleting destructor. The other fields
 * are not traced. */
class Object016ba7c0 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016ba7c0();

  private:
    u8 unknown24[0x14];
    Ref00503fb0<Object016b9108> held38; /* +0x38 */
    Name name40;                        /* +0x40 */
};

void FUN_00d56ed0(Object016ba7c0 *object); /* derived name */

Object016ba7c0::~Object016ba7c0()
{
    FUN_00d56ed0(this);
}
