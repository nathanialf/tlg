/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016b4148.h"

/* derived names: the complete destructor FUN_00aeae40: the array emptied (each
 * reference released, then the block given back with no capacity), then the
 * members and the base torn down. The class's key function: this unit emits
 * the vtable and the deleting destructor FUN_00aeb010. */
// NONMATCHING: the base holds the array's clear(0) inlined (the loop over the references, then the block given
// back with no capacity: 459 bytes); the build calls the shared Array05943280<Ref00503fb0<Object016b9108>>::clear(unsigned)
// (157 bytes), and the deleting destructor then inlines this one
Object016b4148::~Object016b4148()
{
    array30.clear(0);
}
