/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00c1b7f0.h"

/* derived name: the destructor of the part at +0x40 of the classes over
 * Object00c1b7f0 (tlg_game_object00c1b7f0.h): FUN_013cd5c0 first, then the
 * two arrays made with new[] are deleted and their pointers cleared; the
 * members follow, last first. */
// NONMATCHING: an inline-cost margin: the base holds the destructor of the array at +0x108 inlined (659 bytes),
// the build calls the instantiation (393 bytes), in the single-file and the whole module alike
Object013cd320::~Object013cd320()
{
    FUN_013cd5c0();
    delete[] array130;
    array130 = 0;
    delete[] array138;
    array138 = 0;
}
