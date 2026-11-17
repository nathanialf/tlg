/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"

/* derived names: the counted reference at +0x1d8 of the object (FUN_00958ef0
 * calls it at 0x95934a) set to the object the name at 0x15b48d0 names, of
 * the type D_593a048 points to (usable by this thread), or emptied. The
 * name is a static of the function (at 0x5945a78), looked up once (not interned: the last
 * argument of FUN_013baad0 0) and destroyed at exit with Name's destructor.
 * The classes are not traced. */
struct Owner00cca7c0 { /* derived name */
    u8 unknown0[0x1d8];
    AtomicRef0045c470<Object016b9108> target; /* +0x1d8 */
};

struct Target00cca7c0 : Object016b9108 /* derived name */
{};

extern const char D_15b48d0[33];
extern const Type00503fb0 *D_593a048; /* derived name: the target's type */

void FUN_00cca7c0(Owner00cca7c0 *self) /* derived name */
{
    static Name D_5945a78(D_15b48d0, false);
    self->target.set(findNamed<Target00cca7c0>(D_5945a78, D_593a048));
}
