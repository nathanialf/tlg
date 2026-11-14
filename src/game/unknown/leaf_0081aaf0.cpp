/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array0081aaf0.h"
#include "tlg_game_node.h"

/* derived names: FUN_0081aaf0 takes one reference out of an array of exchanged
 * references without keeping the order (tlg_game_array0081aaf0.h's
 * removeUnordered), out of line: the array's own member, instantiated here
 * until a caller of it is written. The referenced class is not traced. */
class Value0081aaf0 : public Node00503fb0 /* derived name */
{
};

template void Array0081aaf0<AtomicRef0045c470<Value0081aaf0>>::removeUnordered(unsigned);
