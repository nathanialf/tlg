/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a vtable slot (its pointer at 0x16cafa8), written as a free
 * function that does not read its object: copies the second argument's
 * state into the third through FUN_005155c0 (destination first; it returns
 * at once when both are the same), with a zeroed int for its third argument
 * and 0 for its fourth. FUN_003c8010 passes the field at +0x268 of its
 * object there. Its meaning is not traced. */
struct Object005155c0; /* derived name */

void FUN_005155c0(Object005155c0 *destination, Object005155c0 *source, int *count,
                  int unknown); /* derived name */

struct Object01354ee0; /* derived name */

void FUN_01354ee0(Object01354ee0 *, Object005155c0 *source,
                  Object005155c0 *destination) /* derived name */
{
    int count = 0;
    FUN_005155c0(destination, source, &count, 0);
}
