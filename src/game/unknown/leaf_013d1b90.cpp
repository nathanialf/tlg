/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object013d35e0.h"

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016bf230 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16bf230
 * (config/vtables.derived.base.txt), with no base class: a counted
 * reference to a pool at +0x18, which its complete destructor FUN_013d1b90
 * gives up (PoolRef01343090::shutdown()) before the reference itself is
 * released; where the pool is null the reference is read again for its
 * release (`je` to it): the test reads it as the pool, the release as the
 * root class (AtomicRef0045c470). FUN_013d1d30, slot 1, is the deleting
 * destructor. The destructor is the class's key function, so this file
 * emits the vtable. The other members are not traced. */
class Object016bf230 /* derived name */
{
  public:
    virtual ~Object016bf230();

  private:
    u8 unknown8[0x10];
    PoolRef01343090<Pool016bf230> pool; /* +0x18 */
};

Object016bf230::~Object016bf230()
{
    pool.shutdown();
}
