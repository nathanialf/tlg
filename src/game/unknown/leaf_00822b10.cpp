/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"
#include "tlg_game_node.h"
#include "tlg_game_object013d35e0.h"
#include "tlg_game_object016b85e0.h"

void FUN_00c57220(Object016b85e0 *node); /* derived name */

/* derived name: the kind of pool the node below refers to; nothing of it
 * is traced but its base */
class Pool00822b10 : public Pool01343090 /* derived name */
{
};

/* derived names: a node (FUN_00c57220 takes it last) with two arrays of
 * counted references at +0x258 and +0x270 and a reference to a pool at
 * +0x290; called by FUN_00826c90 and FUN_008271e0. The rest is not
 * traced. */
class Node00822b10 : public Object016b85e0 /* derived name */
{
  public:
    u8 unknown238[0x20];
    Array05943280<Ref00503fb0<Object016b9108>> references258; /* +0x258 */
    Array05943280<Ref00503fb0<Object016b9108>> references270; /* +0x270 */
    u8 unknown288[0x8];
    PoolRef01343090<Pool00822b10> pool290; /* +0x290 */
};

/* derived name: the pool given up (PoolRef01343090::shutdown()), both arrays
 * emptied and their blocks given back (Array05943280::clear()), then the node
 * handed to FUN_00c57220 as a tail call */
void FUN_00822b10(Node00822b10 *node) /* derived name */
{
    node->pool290.shutdown();
    node->references258.clear();
    node->references270.clear();
    FUN_00c57220(node);
}
