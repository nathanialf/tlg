/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: the referenced class, an int at +0x30 cleared when it is
 * added; the rest is not traced */
class Value002d9ae0 : public Object016b9108 /* derived name */
{
  public:
    u8 unknown24[0xc]; /* +0x24: in the root's tail padding; not traced */
    int unknown30;     /* +0x30 */
};

/* derived names: an object holding counted references at +0x2c8; the rest
 * is not traced */
struct Owner002d9ae0 {                                 /* derived name */
    void add(const Ref00503fb0<Value002d9ae0> &value); /* derived name */

    u8 unknown0[0x2c8];
    Array05943280<Ref00503fb0<Value002d9ae0>> values; /* +0x2c8 */
};

/* FUN_002d9ae0: a referenced object, its +0x30 cleared, then added unless
 * the array holds it (the elements compared first, the count read once,
 * then the count raised from it, the block grown when it is full and the
 * reference copied: its count raised unless the object is released) */
void Owner002d9ae0::add(const Ref00503fb0<Value002d9ae0> &value)
{
    if (Value002d9ae0 *object = value.get()) {
        object->unknown30 = 0;
        if (!values.contains(value))
            values.push(value);
    }
}
