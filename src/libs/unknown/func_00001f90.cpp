/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: TwoBaseAllocator's deleting destructor (slot 1 of
 * 0x168c640) tail-calls the complete destructor and frees nothing, so the
 * class's operator delete is empty: the object lives in storage it does not
 * own. Written as a call because the complete destructor has no name yet. */
void FUN_00001f90(TwoBaseAllocator *self) /* derived name */
{
    FUN_00001fb0(self);
}
