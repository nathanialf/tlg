/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkArrayStreamWriter's destructor (slot 0 of its vtable, 0x16a32f0): an
 * array the writer took goes back to the thread's heap at its 16 bytes. */
// NONMATCHING: equal with its deleting destructor (0x8fe60) but for the
// vptr: the vtable 0x16a32f0 has no row in either vtables file (its
// hkClass, which slot 3 returns, names the class; no type info registers
// it), so the vptr store cannot resolve; a ruling for the supervisor.
hkArrayStreamWriter::~hkArrayStreamWriter()
{
    if (ownership == ARRAY_TAKE && array) {
        D_16dc070->temp58->blockFree(array, sizeof(hkArray<char>));
    }
}
