/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_game_object016b85e0.h"

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016b2b90 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16b1d98
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00a99070
 * and its complete destructor FUN_00a991f0), derived from Object016b85e0:
 * two Names at +0x254 and +0x258, a counted reference at +0x260 and a
 * counted reference to a pool at +0x268. The destructor gives the pool up
 * (PoolRef01343090::shutdown()); then the members are released, last
 * first, and the base's destructor
 * 0xc55550 runs as a tail call. FUN_00a994a0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. The other members are not traced. */
class Object016b2b90 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016b2b90();

  private:
    u8 unknown8[0x24c];
    Name name254; /* +0x254 */
    Name name258; /* +0x258 */
    u8 unknown25c[0x4];
    Ref00503fb0<Object016b9108> held260; /* +0x260 */
    PoolRef01343090<Pool016b2b90> pool;  /* +0x268 */
};

// where the pool is null the reference is read again for its destructor (`lea r15, [r14+0x268]` above the test):
// the test reads it as the pool, the release as the root class (AtomicRef0045c470)
Object016b2b90::~Object016b2b90()
{
    pool.shutdown();
}
