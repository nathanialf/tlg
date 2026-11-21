/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_game_object016b85e0.h"

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016b6788 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16b1d98
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00b4cc10
 * and its complete destructor FUN_00b4cd70), derived from Object016b85e0:
 * a counted reference to a pool at +0x238 and two Names at +0x240 and
 * +0x244. The destructor gives the pool up (PoolRef01343090::shutdown());
 * then the Names and the reference are released, last first, and the base's destructor
 * 0xc55550 runs as a tail call. FUN_00b4cfa0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. The other members are not traced. */
class Object016b6788 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016b6788();

  private:
    u8 unknown8[0x230];
    PoolRef01343090<Pool016b6788> pool; /* +0x238 */
    Name name240;                       /* +0x240 */
    Name name244;                       /* +0x244 */
};

Object016b6788::~Object016b6788()
{
    pool.shutdown();
}
