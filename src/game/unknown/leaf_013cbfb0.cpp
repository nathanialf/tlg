/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"

/* derived names: a game class derived from the library's Pool00007880 with no
 * members of its own (its deleting destructor FUN_013cbfc0, slot 1, frees
 * 0x348 bytes by default, Pool00007880's size); FUN_00e99520 constructs the
 * base (FUN_00006d70 on a WorkerThreadPoolCinfo) and stores the vtable at
 * 0x16d3380, which is unnamed; slots 2 to 14 are Pool00007880's own. The
 * destructor's body is empty, so the base destructor (0x73e0, D2 answering
 * for D1, D15) runs as a tail call, with no vtable store before it. */
class Pool16d3380 : public Pool00007880 /* derived name */
{
  public:
    virtual ~Pool16d3380();
};

Pool16d3380::~Pool16d3380() {}
