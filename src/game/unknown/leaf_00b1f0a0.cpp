/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object013d35e0.h"

/* derived name: the class whose complete destructor is 0x83df00 (its row
 * named for it, D15), as leaf_00b430c0.cpp declares it */
class Object0083df00 /* derived name */
{
  public:
    virtual ~Object0083df00();
};

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016b51f0 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16b51f0
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00b1ef30
 * and its complete destructor FUN_00b1f0a0), derived from Object0083df00: a
 * counted reference to a pool at +0x580. Its complete destructor gives
 * the pool up (PoolRef01343090::shutdown()), then the reference is released
 * and the base's destructor 0x83df00 runs as a tail call; FUN_00b1f250, slot 1,
 * is the deleting one. The destructor is the class's key function, so this
 * file emits the vtable. The other members are not traced. */
class Object016b51f0 : public Object0083df00 /* derived name */
{
  public:
    virtual ~Object016b51f0();

  private:
    u8 unknown8[0x578];
    PoolRef01343090<Pool016b51f0> pool; /* +0x580 */
};

// where the pool is null the reference is read again for its release (`je` to it): the test reads it as the
// pool, the release as the root class (AtomicRef0045c470)
Object016b51f0::~Object016b51f0()
{
    pool.shutdown();
}
