/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the object given: its kind at +0x40 */
class Value0136f790 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0x1c];
    int kind; /* +0x40 */
};

/* derived names: the holder: a counted reference at +0x48 and a bit at
 * +0x44 that says whether the held object's kind is 1 or 2 (`dec ecx; cmp
 * ecx, 2; sbb`, the bit put in place of bit 0) */
struct Holder0136f790 { /* derived name */
    u8 unknown0[0x44];
    unsigned flags44; /* +0x44: bit 0, whether the held object's kind is 1 or 2 */
    AtomicRef0045c470<Object016b9108> unknown48; /* +0x48 */
};

/* derived name: the reference at +0x48 replaced by `value`, then the bit set
 * from the value's kind (the value is not tested for null); called at
 * 0x81b548, 0x820be6, 0x8f5e33 and 0xcb2bf3 */
void FUN_0136f790(Holder0136f790 *self, Value0136f790 *value)
{
    self->unknown48.set(value);
    self->flags44 = (self->flags44 & ~1u) | (value->kind == 1 || value->kind == 2);
}
