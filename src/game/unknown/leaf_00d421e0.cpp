/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"

/* derived names: the class whose vtable is at 0x16ba2a0
 * (config/vtables.derived.base.txt; its constructor FUN_00c82620): two
 * counted references at +0x60 and +0x68 and two arrays of references at
 * +0x70 and +0x88, torn down after its destructor's body has called
 * FUN_00d42320 on the object. FUN_00d42860, slot 1, is the deleting
 * destructor. The other fields are not traced. */
class Object016ba2a0 /* derived name */
{
  public:
    virtual ~Object016ba2a0();

  private:
    u8 unknown8[0x58];
    Ref00503fb0<Object016b9108> held60; /* +0x60 */
    Ref00503fb0<Object016b9108> held68; /* +0x68 */
    Object0134f620 unknown70;           /* +0x70 */
    Object0134f620 unknown88;           /* +0x88 */
};

void FUN_00d42320(Object016ba2a0 *object); /* derived name */

Object016ba2a0::~Object016ba2a0()
{
    FUN_00d42320(this);
}
