/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"

/* derived names: FUN_01392310 is the release of an array of counted
 * references (tlg_game_array.h's release(): every reference dropped, the
 * count cleared, the block given back), out of line: the array's own
 * member, instantiated here until a caller of it is written. The counted
 * class is not traced: its count at +0x8 and its slot 2, which destroys it. */
class Counted01392310 /* derived name */
{
  public:
    virtual void unknown0();
    virtual void unknown1();
    virtual void destroy(); /* derived name; slot 2 */

    int references; /* +0x8 */
};

void FUN_00c14bc0(Counted01392310 *object); /* derived name: releases it later */

template void Array05943280<Ref00503fb0<Counted01392310>>::release();
