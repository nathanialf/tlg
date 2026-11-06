/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A four-byte layout description built from the rules given.
 * Its callers (0x19a9ca, 0x19b47a, 0x19b48c, 0xe9abb4, 0xe9abd0) pass the
 * constants {8, 1, 1, 1} and {8, 1, 0, 1}; the default constructor 0x180ee0 stores
 * {8, 1, 1, 1} with no argument. */
Layout00180ef0::Layout00180ef0(const LayoutRules00180ef0 &rules_)
{
    rules = rules_;
}
