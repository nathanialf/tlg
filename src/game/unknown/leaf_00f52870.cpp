/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array01343a80.h"
#include "tlg_game_object0134f620.h"

/* derived names: the element of the locked array FUN_00f40940
 * copy: one counted reference; the class is this unit's own, not traced
 * (FUN_008e3910 is the same copy over the reference itself) */
struct Entry00f52870 {                  /* derived name */
    Ref00503fb0<Object016b9108> object; /* +0x0 */
};

/* FUN_00f52870: the locked array copied: each object's count raised as its
 * reference is copied */
template Array01343a80<Entry00f52870>::Array01343a80(const Array01343a80<Entry00f52870> &);
