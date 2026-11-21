/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"

/* derived names: what the class below holds at +0x80: an object over the
 * root class whose byte at +0x24 takes the flag 0x80 when it is let go; not
 * traced further */
class Target00ad82b0 : public Object016b9108 /* derived name */
{
  public:
    u8 flags24; /* +0x24 */
};

/* derived names: the class whose vtable is at 0x16b3ae8
 * (config/vtables.derived.base.txt): a counted reference at +0x80,
 * exchanged, and one at +0x88. Its destructor marks the object at +0x80
 * (flag 0x80 at its +0x24) and empties that reference by compare-and-swap;
 * the members are released after it. FUN_00ad8480, slot 1, is the deleting
 * destructor. The other fields are not traced. */
class Object016b3ae8 /* derived name */
{
  public:
    virtual ~Object016b3ae8();

  private:
    u8 unknown8[0x78];
    AtomicRef0045c470<Target00ad82b0> held80; /* +0x80 */
    Ref00503fb0<Object016b9108> held88;       /* +0x88 */
};

Object016b3ae8::~Object016b3ae8()
{
    if (Target00ad82b0 *target = held80.get())
        target->flags24 |= 0x80;
    held80.clear();
}
