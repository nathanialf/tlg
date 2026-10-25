/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: writes a buffer to hkOstream's writer (slot 6 of the writer
 * at +0x10); the callers pass a string and its strlen. */
int hkOstream::FUN_000089f0(const void *buffer, int size) /* derived name */
{
    return writer->write(buffer, size);
}
