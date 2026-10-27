/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: a copy of the string in a block of the thread's heap with
 * FUN_0000bc30's header (the XML reader's names and values, 0x19c895 to
 * 0x19d2cd; FUN_00018090 frees one). */
char *FUN_000180c0(const char *string) /* derived name */
{
    AllocatorBase &heap = *D_16dc070->temp58;
    char *copy = static_cast<char *>(FUN_0000bc30(heap, int(strlen(string)) + 1));
    strcpy(copy, string);
    return copy;
}
