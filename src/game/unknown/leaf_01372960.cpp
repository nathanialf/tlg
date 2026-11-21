/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_name.h"
#include "tlg_game_node.h"
#include "tlg_game_object01372e50.h"

/* derived names: 64 bytes, a name, a counted reference and an
 * Object01372e50 (0x1372960: `shl rbx, 6`, the member at +0x10 destroyed
 * first by 0x1372e50, then the reference at +0x8 and the name) */
struct Entry01372960 /* derived name */
{
    Name name0;                           /* +0x0 */
    Ref00503fb0<Object016b9108> unknown8; /* +0x8 */
    Object01372e50 unknown10;             /* +0x10 */
};

/* The emptying of an array of those records to a given capacity: the
 * array's own member, a function of its own in the executable,
 * instantiated here. */
template void Array05943280<Entry01372960>::clear(unsigned);
