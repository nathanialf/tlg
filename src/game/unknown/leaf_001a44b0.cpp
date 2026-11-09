/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: calls FUN_001a4350 with its first argument twice and its two
 * ints, as a tail call; no caller found. The types and the return type are not
 * traced. Class and method unknown. */
struct Object001a44b0; /* derived name */

void FUN_001a4350(Object001a44b0 *first, Object001a44b0 *second, int, int); /* derived name */

void FUN_001a44b0(Object001a44b0 *object, int first, int second) /* derived name */
{
    FUN_001a4350(object, object, first, second);
}
