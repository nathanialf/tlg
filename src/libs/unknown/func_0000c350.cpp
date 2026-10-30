/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the memory system's deleting destructor (slot 1 of 0x168d690)
 * tail-calls the complete destructor and frees nothing, so the class's
 * operator delete is empty. Written as a call because the complete
 * destructor has no name yet. */
void FUN_0000c350(hkFreeListMemorySystem *self) /* derived name */
{
    FUN_0000c360(self);
}
