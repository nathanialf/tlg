/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0134f620.h"

/* derived names: the holder as FUN_00c29c80 sees it: its array of counted
 * references at +0x238 */
class Object00c29c80 /* derived name */
{
  public:
    unsigned add(Object016b9108 *object); /* derived name: FUN_00c29c80 */

  private:
    u8 unknown0[0x238];
    Object0134f620 objects; /* +0x238 (derived name) */
};

/* FUN_00c29c80: a reference to the object appended to the array at +0x238
 * (the array's append, FUN_0138e360, called with a temporary reference);
 * returns its index */
unsigned Object00c29c80::add(Object016b9108 *object)
{
    return objects.add(Ref00503fb0<Object016b9108>(object));
}
