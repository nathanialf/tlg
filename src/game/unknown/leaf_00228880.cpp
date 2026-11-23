/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: FUN_00228880 appends a pointer to an array unless the
 * array holds it already (tlg_game_array.h's addUnique), out of line: the
 * array's own member, instantiated here until its caller FUN_00220f80 is
 * written. The pointed-to class is not traced. */
struct Object00228880; /* derived name */

// NONMATCHING: the new slot's index, FUN_002db990's residual: the base keeps the count it read
// as a value of its own after the search (`xor r15d, r15d` before it, `mov r15d, eax` on the
// not-found exit: 0 when the array is empty, else the count); the build stores at the search's
// own counter.
template void Array05943280<Object00228880 *>::addUnique(Object00228880 *const &);
