/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: FUN_00c149a0 appends an index to an array unless the
 * array holds it already (tlg_game_array.h's addUnique over int), out of
 * line: the array's own member, instantiated here until its callers are
 * written, FUN_00c14850 and FUN_00d4a7a0 (int: FUN_00c14850 passes its
 * unsigned counter as a temporary, stored just before the call). Both are
 * needed: with one caller in the module the link inlines the member into it
 * and deletes it (round 559D: FUN_00c14850 written alone held it inlined;
 * with a second caller it was equal). */
// NONMATCHING: the registers of the last store: the base loads the value first (`mov ecx, [r14];
// mov edx, r15d`), the build takes the slot's index first (ecx) and the value second. Both are local
// to the block and allocated in order; the IR forms the index before the value's load (the
// placement's address first). Over counted references the value is used after the store (the
// count's raise), a range of its own allocated first, and FUN_002db990 is equal.
template void Array05943280<int>::addUnique(const int &);
