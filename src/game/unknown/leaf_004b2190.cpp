/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the object FUN_004b2190 takes: a counted object, its field
 * at +0x28 handed on; not traced further */
class Value004b2190 : public Object016b9108 /* derived name */
{
  public:
    void *unknown28; /* +0x28 */
};

/* derived names: its owner: the counted reference at +0x60 exchanged, of
 * the root class (the value compared first) */
struct Owner004b2190 { /* derived name */
    u8 unknown0[0x60];
    AtomicRef0045c470<Object016b9108> unknown60; /* +0x60 */
};

void FUN_004afab0(Owner004b2190 *self, void *value); /* derived name */

/* derived name: the reference at +0x60 replaced by `value` (exchanged, the
 * new one raised and the old one dropped where they differ), then the
 * value's field at +0x28 handed to FUN_004afab0 (a tail call; `mov rsi,
 * [r15+0x28]` with no null test) */
void FUN_004b2190(Owner004b2190 *self, Value004b2190 *value)
{
    self->unknown60.set(value);
    FUN_004afab0(self, value->unknown28);
}
