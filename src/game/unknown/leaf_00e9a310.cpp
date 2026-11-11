/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"

/* derived names: the function at 0x16be508 (+0x78 from the vtable stored at
 * 0x16be490): has the memory system (FUN_00006c50) collect the garbage of the
 * router the game's thread-local pointer at 0x16dc0c0 (tp offset -16) holds,
 * slot 13 garbageCollectThread, a tail call. The object itself is not read; its
 * class is not traced. */
struct Object00e9a310; /* derived name */

extern __thread hkMemoryRouter *D_16dc0c0;

// NONMATCHING: list-ilp order: the base loads slot 13 into r14 before the thread-local's general-dynamic call (GetTLSADDR chains it to the entry, free to move), the build calls first and keeps no r14
void FUN_00e9a310(Object00e9a310 *) /* derived name */
{
    FUN_00006c50()->garbageCollectThread(*D_16dc0c0);
}
