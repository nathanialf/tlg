/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object0134f620.h"

/* derived names: the complete destructor of the global objects at 0x5a8cc48,
 * 0x5a8cc60 and 0x5a8cc78 (the int at +0x10 of each set from the thread record
 * at fs:0 before registration, +0x14 zeroed), registered with __cxa_atexit by
 * FUN_00e63c90; its own body is empty, so the destructor of its base or first
 * member, Object0134f620's destructor (0x134f620, which frees the pointers in the array at +0x0 counted
 * by the int at +0x8), runs as a tail call.
 * Written as the empty destructor of a class whose first member is that
 * record. */
struct Object013c9e50 /* derived name */
{
    ~Object013c9e50();

    Object0134f620 record0; /* +0x0 */
    u8 unknown10[8];        /* +0x10: an int set before registration, +0x14 zeroed; not traced */
};

Object013c9e50::~Object013c9e50() {}
