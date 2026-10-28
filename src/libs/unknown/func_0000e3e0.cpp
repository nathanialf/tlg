/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* A copy of a string on the thread's heap, marked owned (bit 0): its
 * length taken before the heap is read. derived name. */
static const char *duplicateOwned(const char *string)
{
    const int length = FUN_00017fe0(string);
    char *copy = static_cast<char *>(FUN_0000bc30(*D_16dc070->temp58, length + 1));
    FUN_00017fc0(copy, string);
    return copy + 1;
}

hkStringPtr::hkStringPtr(const char *string)
{
    stringAndFlag = 0;
    if (string) {
        stringAndFlag = duplicateOwned(string);
    }
}

hkStringPtr::hkStringPtr(const hkStringPtr &other)
{
    stringAndFlag = 0;
    const char *string = other.cString();
    if (string) {
        stringAndFlag = duplicateOwned(string);
    }
}
