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
 * a counted reference to a pool at +0x250. Slots 2 to 7 are the base's;
 * this class's slots 8 and 9 (the empty body at 0x1af750 in the base) are
 * FUN_00a52f40 and FUN_00a53160. The destructor gives the pool up
 * (PoolRef01343090::shutdown()) and calls slot 9 through the vtable; then
 * the reference is released and the base's destructor 0xc55550 runs as a
 * tail call. FUN_00a52ea0, slot 1, is the deleting one. The destructor is
 * the class's key function, so this file emits the vtable. The other
 * members are not traced. */
class Object016b2060 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016b2060();
    virtual void slot8(); /* derived name; FUN_00a52f40, not traced */
    virtual void slot9(); /* derived name; FUN_00a53160, not traced */

  private:
    u8 unknown24[0x22c];
    PoolRef01343090<Pool016b2060> pool; /* +0x250 */
};

Object016b2060::~Object016b2060()
{
    pool.shutdown();
    slot9();
}
