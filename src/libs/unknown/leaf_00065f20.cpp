/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: clears the owner's flag at +0x198 (tlg_lib_unknown.h). */
void FUN_00065f20(Object00065f20 *self) /* derived name */
{
    self->open = false;
}
