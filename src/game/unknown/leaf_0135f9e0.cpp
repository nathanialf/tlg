/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0134f620.h"

/* derived names: the holder as FUN_0135f9e0 sees it: its array of counted
 * references at +0x28 */
class Object0135f9e0 /* derived name */
{
  public:
    void add(Object016b9108 *object); /* derived name: FUN_0135f9e0 */

  private:
    u8 unknown0[0x28];
    Object0134f620 objects; /* +0x28 (derived name) */
};

/* FUN_0135f9e0: a reference to the object appended to the array at +0x28
 * (the array's append, FUN_0138e360, called with a temporary reference);
 * the index is not used */
void Object0135f9e0::add(Object016b9108 *object)
{
    objects.add(Ref00503fb0<Object016b9108>(object));
}
