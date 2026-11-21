/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_game_object016b85e0.h"

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016b6440 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16b6440
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00b4a640
 * and its complete destructor FUN_00b4a7b0), derived from Object016b85e0: a
 * counted reference to a pool at +0x250. Its complete destructor gives
 * the pool up (PoolRef01343090::shutdown()), then the reference is released
 * and the base's destructor 0xc55550 runs as a tail call; FUN_00b4a960, slot 1,
 * is the deleting one. The destructor is the class's key function, so this
 * file emits the vtable. The other members are not traced. */
class Object016b6440 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016b6440();

  private:
    u8 unknown24[0x22c];
    PoolRef01343090<Pool016b6440> pool; /* +0x250 */
};

// where the pool is null the reference is read again for its release (`je` to it): the test reads it as the
// pool, the release as the root class (AtomicRef0045c470)
Object016b6440::~Object016b6440()
{
    pool.shutdown();
}
