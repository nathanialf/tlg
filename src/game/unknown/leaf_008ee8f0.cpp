/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016aed28.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object013d35e0.h"

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016b04c8 : public Pool01343090 /* derived name */
{
};

/* derived names: the class whose vtable is at 0x16b04c8
 * (config/vtables.derived.base.txt, stored by its constructor FUN_008ee780
 * and its complete destructor FUN_008ee8f0), derived from Object016aed28:
 * a counted reference to a pool at +0x580 and a Name at +0x588. The
 * destructor gives the pool up (PoolRef01343090::shutdown()); then the
 * name and the pool's reference are released and the base's destructor
 * 0x83df00 runs as a tail call. FUN_008eeae0, slot 1, is the deleting one.
 * The destructor is the class's key function, so this file emits the
 * vtable. The other members are not traced. */
class Object016b04c8 : public Object016aed28 /* derived name */
{
  public:
    virtual ~Object016b04c8();

  private:
    PoolRef01343090<Pool016b04c8> pool; /* +0x580 */
    Name name588;                       /* +0x588 */
};

Object016b04c8::~Object016b04c8()
{
    pool.shutdown();
}
