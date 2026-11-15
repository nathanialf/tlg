/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object00c1b7f0.h"

/* derived name: the destructor of the part at +0x40 of the classes over
 * Object00c1b7f0 (tlg_game_object00c1b7f0.h): FUN_013cd5c0 first, then the
 * two arrays made with new[] are deleted and their pointers cleared, each
 * only where it is set (`test rdi, rdi; je` over the call and the store at
 * 0x13cd33d); the members follow, last first. */
Object013cd320::~Object013cd320()
{
    FUN_013cd5c0();
    if (array130) {
        delete[] array130;
        array130 = 0;
    }
    if (array138) {
        delete[] array138;
        array138 = 0;
    }
}
