/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_game_object016b85e0.h"

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016b1d98 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16b1d98
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00a2f660
 * and its complete destructor FUN_00a2f810), derived from Object016b85e0:
 * a counted reference to a pool at +0x248 and a counted reference at
 * +0x270. The destructor gives the pool up (PoolRef01343090::shutdown());
 * then the references are released, last first, and the base's destructor
 * 0xc55550 runs as a tail call. FUN_00a2fa40, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. The other members are not traced. */
class Object016b1d98 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016b1d98();

  private:
    u8 unknown8[0x240];
    PoolRef01343090<Pool016b1d98> pool; /* +0x248 */
    u8 unknown250[0x20];
    Ref00503fb0<Object016b9108> held270; /* +0x270 */
};

Object016b1d98::~Object016b1d98()
{
    pool.shutdown();
}
