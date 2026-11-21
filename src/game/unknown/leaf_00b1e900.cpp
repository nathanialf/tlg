/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_block.h"
#include "tlg_game_name.h"
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
class Pool016b4ed0 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16b6860
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00b1e630
 * and its complete destructor FUN_00b1e900), derived from Object0083df00:
 * a counted reference to a pool at +0x580, a Name at +0x588, an array of
 * Names at +0x590 and a block it owns at +0x5a8. The destructor gives the pool
 * up (PoolRef01343090::shutdown()); then the members are released, last
 * first, and the base's destructor 0x83df00 runs as a tail call.
 * FUN_00b1ebd0, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. The other members are not
 * traced. */
class Object016b4ed0 : public Object0083df00 /* derived name */
{
  public:
    virtual ~Object016b4ed0();

  private:
    u8 unknown8[0x578];
    PoolRef01343090<Pool016b4ed0> pool; /* +0x580 */
    Name name588;                       /* +0x588 */
    u8 unknown58c[0x4];
    Array05943280<Name> names590; /* +0x590 */
    OwnedBlock05943280 block5a8;  /* +0x5a8 */
};

Object016b4ed0::~Object016b4ed0()
{
    pool.shutdown();
}
