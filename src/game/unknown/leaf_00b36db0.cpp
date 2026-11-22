/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_game_object016b85e0.h"

void FUN_00c57220(Object016b85e0 *node); /* derived name */

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016b56c0 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16b56c0
 * (config/vtables.derived.base.txt; its constructor FUN_00b36290 stores it),
 * derived from Object016b85e0. Its complete destructor FUN_00b36db0 hands
 * each node its references at +0x240 and +0x248 hold to FUN_00c57220 and
 * empties the reference, closes the pool the reference at +0x268 holds and
 * empties that one either way (the null test jumps to the exchange), then
 * the members go last first (the three references, the Name at +0x238) and
 * the base's destructor 0xc55550 runs as a tail call; FUN_00b371f0, slot 1,
 * is the deleting one. The rest is not traced. */
class Object016b56c0 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016b56c0();

  private:
    Name name238;                              /* +0x238 */
    AtomicRef0045c470<Object016b85e0> node240; /* +0x240 */
    AtomicRef0045c470<Object016b85e0> node248; /* +0x248 */
    u8 unknown250[0x18];
    AtomicRef0045c470<Pool016b56c0> pool; /* +0x268 */
};

/* the destructor is the class's key function: this file emits the vtable */
Object016b56c0::~Object016b56c0()
{
    if (Object016b85e0 *node = node240.get()) {
        FUN_00c57220(node);
        node240.clear();
    }
    if (Object016b85e0 *node = node248.get()) {
        FUN_00c57220(node);
        node248.clear();
    }
    if (Pool016b56c0 *held = pool.get())
        held->close();
    pool.clear();
}
