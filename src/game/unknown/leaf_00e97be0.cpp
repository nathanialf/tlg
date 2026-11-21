/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16be370
 * (config/vtables.derived.base.txt), derived from Object016b9108: a counted
 * reference at +0x38 and two names at +0x40 and +0x44, released after its
 * destructor's body has called FUN_00e97d70 on the object. FUN_00e97e90,
 * slot 1, is the deleting destructor. The other fields are not traced. */
class Object016be370 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016be370();

  private:
    u8 unknown24[0x14];
    Ref00503fb0<Object016b9108> held38; /* +0x38 */
    Name name40;                        /* +0x40 */
    Name name44;                        /* +0x44 */
};

void FUN_00e97d70(Object016be370 *object); /* derived name */

Object016be370::~Object016be370()
{
    FUN_00e97d70(this);
}
