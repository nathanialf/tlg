/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The string set from a C string of a given length (-1: up to its
 * terminator), nothing done when it is the string held: an owned string
 * goes back to the thread's heap, then a copy of the new one from the heap,
 * marked owned, or null. */
void FUN_0000e450(hkStringPtr *self, const char *string, int length)
{
    const char *const old = self->stringAndFlag;
    if (self->cString() == string) {
        return;
    }
    if (reinterpret_cast<hkUlong>(old) & 1) {
        FUN_0000bc80(*D_16dc070->temp58, const_cast<char *>(old) - 1);
    }
    if (string) {
        int stringLength = FUN_00017fe0(string);
        char *copy;
        if (length == -1) {
            copy = static_cast<char *>(FUN_0000bc30(*D_16dc070->temp58, stringLength + 1));
            FUN_00017fc0(copy, string);
        } else {
            if (stringLength > length) {
                stringLength = length;
            }
            copy = static_cast<char *>(FUN_0000bc30(*D_16dc070->temp58, stringLength + 1));
            FUN_00017fd0(copy, string, stringLength);
            copy[stringLength] = '\0';
        }
        self->stringAndFlag = copy + 1;
    } else {
        self->stringAndFlag = 0;
    }
}
