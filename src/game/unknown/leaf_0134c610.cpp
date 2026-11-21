/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: an object of the root class with a counted reference at
 * +0x60 and more from +0x68, each exchanged by its setter, which then sets a
 * bit of the root class's flags at +0x20 (`or byte [r14+0x20], 2` and `8`);
 * called directly (0x30b839, 0x30b852, 0x769005, 0x76a219). The fields are
 * not traced further. */
/* derived name: the class of the values given, over the references' (the
 * value compared first, `cmp rsi, rbx`); not traced */
class Value0134c610 : public Object016b9108 /* derived name */
{
};

class Object0134c610 : public Object016b9108 /* derived name */
{
  public:
    void FUN_0134c610(Value0134c610 *value);
    void FUN_0134c6f0(unsigned index, Value0134c610 *value);

  private:
    u8 unknown24[0x3c];
    AtomicRef0045c470<Object016b9108> unknown60;    /* +0x60 */
    AtomicRef0045c470<Object016b9108> unknown68[2]; /* +0x68: its count not traced */
};

void Object0134c610::FUN_0134c610(Value0134c610 *value)
{
    unknown60.set(value);
    flags |= 2;
}

void Object0134c610::FUN_0134c6f0(unsigned index, Value0134c610 *value)
{
    unknown68[index].set(value);
    flags |= 8;
}
