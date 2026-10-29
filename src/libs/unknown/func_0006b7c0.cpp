/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the complete destructor (slot 0 of the vtable 0x169ab20)
 * runs the out-of-line destructor body. Written as a call until the class's
 * destructor body (0x5a230) is written, whose vtable has no row yet. */
void FUN_0006b7c0(RefArrays0005a230 *self) /* derived name */
{
    self->RefArrays0005a230::~RefArrays0005a230();
}
