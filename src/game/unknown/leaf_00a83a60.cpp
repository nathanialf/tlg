/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_game_object016b85e0.h"

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016b24a0 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16b24a0
 * (config/vtables.derived.base.txt), derived from Object016b85e0: a counted
 * reference to a pool at +0x248. Its complete destructor FUN_00a83a60 gives
 * the pool up (PoolRef01343090::shutdown()), then the reference is released
 * and the base's destructor 0xc55550 runs as a tail call; FUN_00a83c10, slot
 * 1, is the deleting one. The destructor is the class's key function, so
 * this file emits the vtable. The other members are not traced. */
class Object016b24a0 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016b24a0();

  private:
    u8 unknown8[0x240];
    PoolRef01343090<Pool016b24a0> pool; /* +0x248 */
};

// NONMATCHING: the deleting destructor inlines this one in stage 1 (the body's cost there is under 225 with
// shutdown() kept a call: shutdown() costs between 325 and 350 in it, measured with -inline-threshold), so the
// link stage sees shutdown() called twice and keeps both calls; the base calls this destructor from the deleting
// one and holds shutdown() inlined (a stage-1 inline-cost margin)
Object016b24a0::~Object016b24a0()
{
    pool.shutdown();
}
