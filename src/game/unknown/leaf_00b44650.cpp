/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_game_object016b9108.h"

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016b6020 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16b6020
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00b444d0 and its
 * complete destructor FUN_00b44650), derived from Object016b9108: a
 * counted reference at +0x28 and a counted reference to a pool at +0x38.
 * The destructor gives the pool up (PoolRef01343090::shutdown()); then the
 * references are released, last first, and the base's destructor is
 * inlined (its vptr store, then the two names). FUN_00b448e0, slot 1, is
 * the deleting one. The destructor is the class's key function, so this
 * file emits the vtable. The other members are not traced. */
class Object016b6020 : public Object016b9108 /* derived name */
{
  public:
    virtual ~Object016b6020();

  private:
    u8 unknown24[0x4];
    Ref00503fb0<Object016b9108> held28; /* +0x28 */
    u8 unknown30[0x8];
    PoolRef01343090<Pool016b6020> pool; /* +0x38 */
};

// NONMATCHING: where the pool is null the base reads the reference again for its destructor (`lea r15, [r14+0x38]`
// above the test, `mov r12, [r15]` at 0xb44756); the module knows it null on that path and skips the release
// (nothing is called between the two reads here; leaf_00a2f810.cpp, with a release between, is equal). The
// deleting destructor FUN_00b448e0 is equal
Object016b6020::~Object016b6020()
{
    pool.shutdown();
}
