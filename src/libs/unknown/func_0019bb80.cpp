/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

int FUN_0019bb80(void *buffer) /* derived name */
{
    /* The buffer ends with its trailer: the records, then their count in
     * the last int, both reached back from the end by a byte offset. */
    const char *end = static_cast<const char *>(buffer) + FUN_0000bc60(D_16dc070->temp58, buffer);
    const int numObjects =
        *hkAddByteOffsetConst(reinterpret_cast<const int *>(end), -long(sizeof(int)));
    if (numObjects != 0) {
        const long trailerSize = numObjects * int(sizeof(LoadedObjectRecord)) + int(sizeof(int));
        const LoadedObjectRecord *records =
            hkAddByteOffsetConst(reinterpret_cast<const LoadedObjectRecord *>(end), -trailerSize);
        for (int i = 0; i < numObjects; i++) {
            if (records[i].type) {
                records[i].type->FUN_00092fc0(records[i].object);
            }
        }
    }
    FUN_0000bc80(*D_16dc070->temp58, buffer);
    return 0;
}
