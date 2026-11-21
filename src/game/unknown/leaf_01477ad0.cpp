/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_object013d35e0.h"

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016c1fd8 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16c1fd8
 * (config/vtables.derived.base.txt), with no base class: a counted
 * reference to a pool at +0x18, which its complete destructor FUN_01477ad0
 * gives up (PoolRef01343090::shutdown()) before the reference itself is
 * released; where the pool is null the reference is read again for its
 * release (`je` to it): the test reads it as the pool, the release as the
 * root class (AtomicRef0045c470). FUN_01477c70, slot 1, is the deleting
 * destructor. The destructor is the class's key function, so this file
 * emits the vtable. The other members are not traced. */
class Object016c1fd8 /* derived name */
{
  public:
    virtual ~Object016c1fd8();

  private:
    u8 unknown8[0x10];
    PoolRef01343090<Pool016c1fd8> pool; /* +0x18 */
};

Object016c1fd8::~Object016c1fd8()
{
    pool.shutdown();
}
