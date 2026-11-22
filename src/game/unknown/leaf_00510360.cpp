/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_game_object016b85e0.h"

/* derived name: the kind of pool the class below refers to; nothing of it
 * is traced but its base */
class Pool016aaff8 : public Pool01343090
{
};

/* derived names: the class whose vtable is at 0x16aaff8
 * (config/vtables.derived.base.txt, stored by its constructor FUN_0050bda0,
 * which calls Object016b85e0's): a scene node with a reference to a pool at
 * +0x240 and a Name at +0x24c. Its complete destructor 0x510360 is the key
 * function. The rest is not traced. */
class Object016aaff8 : public Object016b85e0 /* derived name */
{
  public:
    virtual ~Object016aaff8();

  private:
    u8 unknown238[0x8];
    PoolRef01343090<Pool016aaff8> pool; /* +0x240 */
    u8 unknown248[0x4];
    Name name24c; /* +0x24c */
};

/* 0x510360: the pool given up, its word at +0x48 reset first; the Name
 * and the reference released, then the base's destructor as a tail call */
Object016aaff8::~Object016aaff8()
{
    pool.resetAndShutdown();
}
