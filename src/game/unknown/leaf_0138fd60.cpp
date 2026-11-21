/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
/* NONMATCHING FUN_0138fd60: the base keeps the release of the five references at +0x58 as a loop, last to first (`sub rbx, -0x80` ... `cmp rbx, r15; jne`); the build unrolls it. */
#include "tlg_game_object016cc130.h"

/* derived names: the destructors of two classes over Object016cc130
 * (tlg_game_object016cc130.h), each its class's key function, the bodies
 * empty: the members are released, last first, then the base's destructor
 * FUN_01370c30 runs as a tail call (FUN_0138fd60, FUN_01371b50). */
Object016b4c60::~Object016b4c60() {}

Object016af138::~Object016af138() {}
