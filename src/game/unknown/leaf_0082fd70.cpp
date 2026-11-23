/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_node.h"
#include "tlg_game_object016b9108.h"
#include "tlg_game_object016c70d0.h"

/* derived name: the elements of Object016aec40's array: not traced (its
 * destructor FUN_0082ff60 empties them as references another thread may
 * replace: the pointer cleared, then the reference dropped) */
class Element0082fd70;

/* derived names: the class whose vtable is at 0x16aec40
 * (config/vtables.derived.base.txt, stored by its constructor FUN_0082fd70
 * and its destructor FUN_0082ff60), over the counted base: a reference
 * another thread may replace at +0x10, which the constructor makes an
 * Object016c70d0, a locked array of such references at +0x18 and an int at
 * +0x30. The destructor is not written; the rest is not traced. */
class Object016aec40 : public Counted00c14bc0 /* derived name */
{
  public:
    Object016aec40();
    virtual ~Object016aec40();

  private:
    AtomicRef0045c470<Object016c70d0> object10;                  /* +0x10 */
    Array01343a80<AtomicRef0045c470<Element0082fd70>> objects18; /* +0x18 */
    int unknown30; /* +0x30: zero from the constructor */
};

/* FUN_0082fd70: the members made empty, then a new Object016c70d0 put in
 * the reference at +0x10 by exchange (0x82fea6: `lock cmpxchg [r15], r14`),
 * its count raised and the old object's dropped */
Object016aec40::Object016aec40() : unknown30(0)
{
    object10.set(new Object016c70d0);
}
