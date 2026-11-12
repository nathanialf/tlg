/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0134f620.h"

/* derived names: the complete destructor of the global object at 0x58222d8,
 * registered with __cxa_atexit by FUN_009f43e0; its own body is empty, so the
 * destructor of its base or first member, Object0134f620's destructor (0x134f620, which frees the
 * pointers in the array at +0x0 counted by the int at +0x8, 683 call sites),
 * runs as a tail call.
 * Written as the empty destructor of a class whose first member is that
 * record. */
struct Object01384a30 /* derived name */
{
    ~Object01384a30();

    Object0134f620 record0; /* +0x0 */
};

Object01384a30::~Object01384a30() {}
