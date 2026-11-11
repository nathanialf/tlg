/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_name.h"
#include "tlg_game_vector.h"

/* derived names: slot 3 of the vtable at 0x16b37d0 (its pointer at 0x16b37f8),
 * the vtable stored by FUN_00abf490, returns the address of the object at
 * 0x582bdd8: the int there holds the result of FUN_013baad0 for the string
 * "AIMODE_SOL_PlayerInterest" (its hash from FUN_013bad90), stored by the
 * file's initializer at 0xacb382, which registers Name's destructor (0x1331800) for it
 * with __cxa_atexit: a Name (tlg_game_name.h), looked up without interning
 * (`xor ecx, ecx`). The file's initializer FUN_00acb1a0 builds the vector
 * constants of tlg_game_vector.h and the file's names, below. Class and method
 * unknown. */

// NONMATCHING: the file's initializer (FUN_00acb1a0): the last name's index
// store and `lea rsi` before the tail call to __cxa_atexit are in the other
// order (the parked order class: the base's instruction selection puts the
// store first in a tail block).
extern const char D_15a7e62[11];
extern const char D_15a7e6d[13];
extern const char D_15a7e7a[26];
extern const char D_15a7e94[19];
extern const char D_15a7ea7[19];

Name D_582bdd0(D_15a7e62, false);
Name D_582bdd4(D_15a7e6d, false);
Name D_582bdd8(D_15a7e7a, false);
Name D_582bda0(D_15a7e94, false);
Name D_582bda4(D_15a7ea7, false);

struct Object00acb190;

const Name *FUN_00acb190(const Object00acb190 *self) /* derived name */
{
    return &D_582bdd8;
}
