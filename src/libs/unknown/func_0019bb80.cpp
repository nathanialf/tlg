/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: the count's load addresses [size + buffer] where the base has
// [buffer + size], and the loop's guard reuses the empty test's flags where
// the base tests the count again (MachineCSE finds no clobber between); the
// records' offset is the base's int product (docs/NOTES.md, Round 54).
int FUN_0019bb80(void *buffer) /* derived name */
{
    char *end = static_cast<char *>(buffer) + FUN_0000bc60(D_16dc070->temp58, buffer);
    const int numObjects = reinterpret_cast<const int *>(end)[-1];
    if (numObjects != 0) {
        const LoadedObjectRecord *records = reinterpret_cast<const LoadedObjectRecord *>(
            end - sizeof(int) - numObjects * int(sizeof(LoadedObjectRecord)));
        for (int i = 0; i < numObjects; i++) {
            if (records[i].type) {
                records[i].type->FUN_00092fc0(records[i].object);
            }
        }
    }
    FUN_0000bc80(*D_16dc070->temp58, buffer);
    return 0;
}
