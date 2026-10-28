/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The string pointer's destructor, out of line: a pointer
 * that holds a string is cleared, an owned one (bit 0 of the pointer set,
 * so the string starts one byte before it) going back to the thread's heap
 * first. */
hkStringPtr::~hkStringPtr()
{
    if (cString() != 0) {
        if (reinterpret_cast<hkUlong>(stringAndFlag) & 1) {
            FUN_0000bc80(*D_16dc070->temp58, const_cast<char *>(stringAndFlag - 1));
        }
        stringAndFlag = 0;
    }
}
