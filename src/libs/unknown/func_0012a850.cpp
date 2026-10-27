/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the complete destructor (slot 0 of the vtable at
 * 0x16a3e40) of a reference-counted class runs the out-of-line destructor
 * body FUN_0012a8c0, which stores the same vtable and frees the array of
 * 24-byte elements at +0xb0; the deleting destructor FUN_0012a860 frees
 * 0xf0 bytes by default. Written as a call because neither variant has a
 * name yet. */
void FUN_0012a850(Object0012a8c0 *self) /* derived name */
{
    FUN_0012a8c0(self);
}
