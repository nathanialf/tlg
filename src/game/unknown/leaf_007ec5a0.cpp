/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_list0138c3b0.h"
#include "tlg_game_object013d35e0.h"

struct Registry05938c40_40; /* derived name */

struct Object05938c40 { /* derived name */
    u8 unknown0[0x40];
    Registry05938c40_40 *unknown40;
};

extern Object05938c40 *D_5938c40;

void FUN_00c89a10(Registry05938c40_40 *registry, const char *name); /* derived name */

/* derived name: the kind of pool the object below refers to; nothing of it
 * is traced but its base */
class Pool007ec5a0 : public Pool01343090 /* derived name */
{
};

/* derived names: the object FUN_001f4f10 and FUN_007eb4f0 hand to the
 * function below: a list at +0xa0 and a reference to a pool at +0x2e98. The
 * rest is not traced. */
struct Object007ec5a0 { /* derived name */
    u8 unknown0[0xa0];
    List0138c3b0 lista0; /* +0xa0 */
    u8 unknownd8[0x2dc0];
    PoolRef01343090<Pool007ec5a0> pool2e98; /* +0x2e98 */
};

/* derived name: the pool given up (PoolRef01343090::shutdown()), the list at
 * +0xa0 emptied, then the name "DemoMngr_Command" handed to the script
 * registry (FUN_00c89a10, a tail call) */
void FUN_007ec5a0(Object007ec5a0 *self) /* derived name */
{
    self->pool2e98.shutdown();
    FUN_0138c3b0(&self->lista0);
    FUN_00c89a10(D_5938c40->unknown40, "DemoMngr_Command");
}
