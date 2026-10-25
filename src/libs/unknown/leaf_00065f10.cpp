/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: clears the union-find's int at +0xc, which its constructor
 * sets to 1; called before the edges are added (0x6dd08, 0x14e8f4). */
void FUN_00065f10(Object00065f20 *self) /* derived name */
{
    self->unionFind->state = 0;
}
