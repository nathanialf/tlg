/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: slot 3 of the vtable at 0x16b3820 (its pointer at 0x16b3848),
 * the vtable stored by FUN_00abf490, returns the address of the object at
 * 0x582bef0: the int there holds the result of FUN_013baad0 for the string
 * "AIMODE_SOL_PlayerCondor" (its hash from FUN_013bad90), stored by the file's
 * initializer at 0xacba9a, which registers Name's destructor (0x1331800) for it
 * with __cxa_atexit: a Name (tlg_game_name.h), looked up without interning
 * (`xor ecx, ecx`). The file's initializer FUN_00acb940 builds the vector
 * constants of tlg_game_vector.h and the file's names, below. Class and method
 * unknown. */

// NONMATCHING: the file's initializer (FUN_00acb940): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15a7eba[24];

Name D_582bef0(D_15a7eba, false);

struct Object00acb930;

const Name *FUN_00acb930(const Object00acb930 *self) /* derived name */
{
    return &D_582bef0;
}
