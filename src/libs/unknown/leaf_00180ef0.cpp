/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: builds a four-byte layout description from a given one.
 * Its callers (0x19a9ca, 0x19b47a, 0x19b48c, 0xe9abb4, 0xe9abd0) pass the
 * constants {8, 1, 1, 1} and {8, 1, 0, 1}; FUN_00180ee0 beside it stores
 * {8, 1, 1, 1} with no argument. */
void FUN_00180ef0(Layout00180ef0 *self, const LayoutRules00180ef0 *rules) /* derived name */
{
    self->rules = *rules;
}
