/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: FUN_01391cd0 exchanges two references another thread may
 * replace (tlg_game_node.h's exchange over AtomicRef0045c470: a copy of the
 * first held, the first assigned from the second, the second from the
 * copy), out of line: the function template instantiated here until a
 * caller of it is written. The referenced class is not traced. */
class Value01391cd0 : public Node00503fb0 /* derived name */
{
};

template void exchange<AtomicRef0045c470<Value01391cd0>>(AtomicRef0045c470<Value01391cd0> &,
                                                         AtomicRef0045c470<Value01391cd0> &);
