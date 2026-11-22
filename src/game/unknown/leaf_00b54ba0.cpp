/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aed28.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object013d35e0.h"

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016b6860 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16b6860
 * (config/vtables.derived.base.txt, stored by its constructor FUN_00b54a20
 * and its complete destructor FUN_00b54ba0), derived from Object016aed28:
 * a counted reference to a pool at +0x580, a Name at +0x588 and counted
 * references at +0x590, +0x598 and +0x5a0. The destructor gives the pool
 * up (PoolRef01343090::shutdown()); then the members are released, last
 * first, and the base's destructor 0x83df00 runs as a tail call.
 * FUN_00b54f00, slot 1, is the deleting one. The destructor is the class's
 * key function, so this file emits the vtable. The other members are not
 * traced. */
class Object016b6860 : public Object016aed28 /* derived name */
{
  public:
    virtual ~Object016b6860();

  private:
    PoolRef01343090<Pool016b6860> pool; /* +0x580 */
    Name name588;                       /* +0x588 */
    u8 unknown58c[0x4];
    Ref00503fb0<Object016b9108> held590; /* +0x590 */
    Ref00503fb0<Object016b9108> held598; /* +0x598 */
    Ref00503fb0<Object016b9108> held5a0; /* +0x5a0 */
};

Object016b6860::~Object016b6860()
{
    pool.shutdown();
}
