/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: whether a sorts before b: a record with no count never
 * does, one with a count goes before one without, then the targets' order
 * and the keys decide. */
bool FUN_00062100(const SortRecord00062100 &a, const SortRecord00062100 &b)
{
    if (a.count == 0) {
        return false;
    }
    if (b.count == 0) {
        return true;
    }
    if (a.target->order == b.target->order) {
        return a.key < b.key;
    }
    return a.target->order < b.target->order;
}
