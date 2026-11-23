/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: FUN_00228880 appends a pointer to an array unless the
 * array holds it already (tlg_game_array.h's addUnique), out of line: the
 * array's own member, instantiated here until its caller FUN_00220f80 is
 * written. The pointed-to class is not traced. */
struct Object00228880; /* derived name */

// NONMATCHING: the registers of the last store: the base loads the value first (`mov ecx, [r14];
// mov edx, r15d`), the build takes the slot's index first (ecx) and the value second. Both are local
// to the block and allocated in order; the IR forms the index before the value's load (the
// placement's address first). Over counted references the value is used after the store (the
// count's raise), a range of its own allocated first, and FUN_002db990 is equal.
template void Array05943280<Object00228880 *>::addUnique(Object00228880 *const &);
