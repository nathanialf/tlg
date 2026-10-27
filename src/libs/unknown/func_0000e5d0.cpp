/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the string pointer's destructor, out of line: a pointer
 * that holds a string is cleared, an owned one (bit 0 of the pointer set,
 * so the string starts one byte before it) going back to the thread's heap
 * first. */
void FUN_0000e5d0(hkStringPtr *self)
{
    if (self->cString() != 0) {
        if (reinterpret_cast<hkUlong>(self->stringAndFlag) & 1) {
            FUN_0000bc80(*D_16dc070->temp58, const_cast<char *>(self->stringAndFlag - 1));
        }
        self->stringAndFlag = 0;
    }
}
