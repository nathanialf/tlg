/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_game_object016b85e0.h"

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016b2060 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16b2060
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00a52b70
 * and its complete destructor FUN_00a52ce0), derived from Object016b85e0:
 * a counted reference to a pool at +0x250. Slots 2 to 9 are the base's
 * (slots 8 and 9 the empty body at 0x1af750 there); this class's slot 9 is
 * FUN_00a53160. The destructor gives the pool up
 * (PoolRef01343090::shutdown()) and calls slot 9 through the vtable; then
 * the reference is released and the base's destructor 0xc55550 runs as a
 * tail call. FUN_00a52ea0, slot 1, is the deleting one. The destructor is
 * the class's key function, so this file emits the vtable. The other
 * members are not traced. */
class Object016b2060 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016b2060();
    virtual void slot2(); /* derived name; 0xcb66f0, the base's */
    virtual void slot3(); /* derived name; 0x134a390, the base's */
    virtual void slot4(); /* derived name; 0x134a3a0, the base's */
    virtual void slot5(); /* derived name; 0xc573b0, the base's */
    virtual void slot6(); /* derived name; 0xc575d0, the base's */
    virtual void slot7(); /* derived name; 0xc59010, the base's */
    virtual void slot8(); /* derived name; FUN_00a52f40, not traced */
    virtual void slot9(); /* derived name; FUN_00a53160, not traced */

  private:
    u8 unknown8[0x248];
    PoolRef01343090<Pool016b2060> pool; /* +0x250 */
};

// NONMATCHING: the deleting destructor inlines this one in stage 1 (the body's cost there is under 225 with
// shutdown() kept a call: shutdown() costs between 325 and 350 in it, measured with -inline-threshold), so the
// link stage sees shutdown() called twice and keeps both calls; the base calls this destructor from the deleting
// one and holds shutdown() inlined (a stage-1 inline-cost margin)
Object016b2060::~Object016b2060()
{
    pool.shutdown();
    slot9();
}
