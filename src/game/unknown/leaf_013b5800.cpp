/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the object given: an int at +0x1e4 set to 1 when it is
 * held; not traced further */
class Value013b5800 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x1c0];
    int unknown1e4; /* +0x1e4 */
};

/* derived names: the holder: a counted reference at +0x28, of the root
 * class (the value compared first, `cmp r14, rbx`) */
struct Holder013b5800 { /* derived name */
    u8 unknown0[0x28];
    AtomicRef0045c470<Object016b9108> unknown28; /* +0x28 */
};

/* derived name: the reference at +0x28 replaced by `value`, then the
 * value's int at +0x1e4 set where there is a value */
void FUN_013b5800(Holder013b5800 *self, Value013b5800 *value)
{
    self->unknown28.set(value);
    if (value)
        value->unknown1e4 = 1;
}
