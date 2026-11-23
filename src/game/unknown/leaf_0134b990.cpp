/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_math.h"

/* derived name: the library region's point turned by a rotation, returned by
 * value through the hidden pointer (a 16-byte aligned result) */
Float4A FUN_00315a10(const Float4 &rotation, float x, float y, float z); /* derived name */

/* derived names: a point turned in place by the rotation at the first
 * argument, through FUN_00315a10 (the result's slot on the stack copied
 * back whole), and returned. Called and never inlined in the base: defined
 * over its own parameter types, leaf_00ff5e60.cpp's declaration is of
 * another name. */
Float4A *FUN_0134b990(const Float4 *rotation, Float4A *point) /* derived name */
{
    *point = FUN_00315a10(*rotation, point->x, point->y, point->z);
    return point;
}
