/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_node.h"
#include "tlg_game_object013d35e0.h"

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016a9870 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16a9870
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00422ff0
 * and its complete destructor FUN_004231c0), derived from Object016b9108
 * (its destructor ends in that class's: the vptr 0x16b9118): a counted
 * reference to a pool at +0x70, which the destructor gives up
 * (PoolRef01343090::shutdown()) before the reference itself is released;
 * where the pool is null the reference is read again for its release (`je`
 * to it): the test reads it as the pool, the release as the root class
 * (AtomicRef0045c470). FUN_004233d0, slot 1, is the deleting destructor.
 * The destructor is the class's key function, so this file emits the
 * vtable. The other members are not traced. */
class Object016a9870 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016a9870();

  private:
    u8 unknown24[0x4c];
    PoolRef01343090<Pool016a9870> pool; /* +0x70 */
};

Object016a9870::~Object016a9870()
{
    pool.shutdown();
}
