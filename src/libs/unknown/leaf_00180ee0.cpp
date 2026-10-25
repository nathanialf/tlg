/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: builds the layout description with the host's rules, the
 * constant {8, 1, 1, 1} (the base's copy at 0x14cb8f6), copied whole as one
 * 32-bit store. Callers 0x19b01a, 0x19c73d and 0xe9ab6f. */
static const LayoutRules00180ef0 hostLayoutRules = {8, 1, 1, 1}; /* derived name */

void FUN_00180ee0(Layout00180ef0 *self) /* derived name */
{
    self->rules = hostLayoutRules;
}
