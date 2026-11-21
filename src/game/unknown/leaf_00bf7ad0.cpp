/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object0134f620.h"
#include "tlg_game_object016b9108.h"

/* derived names: the class whose vtable is at 0x16b7d98
 * (config/vtables.derived.base.txt), derived from Object016b9108: an array
 * of counted references at +0x28, a pointer at +0x40 and two counted
 * references at +0x60 and +0x68. Its destructor's body releases the
 * array's elements (the block kept for the array's own destructor) and
 * clears the pointer; the members are torn down after it. FUN_00bf7d50,
 * slot 1, is the deleting destructor. The other fields are not traced. */
class Object016b7d98 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b7d98();

  private:
    u8 unknown24[0x4];
    Object0134f620 unknown28; /* +0x28 */
    void *unknown40;          /* +0x40 */
    u8 unknown48[0x18];
    Ref00503fb0<Object016b9108> held60; /* +0x60 */
    Ref00503fb0<Object016b9108> held68; /* +0x68 */
};

Object016b7d98::~Object016b7d98()
{
    unknown28.removeAll();
    unknown40 = 0;
}
