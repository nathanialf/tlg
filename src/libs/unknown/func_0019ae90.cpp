/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 6 of the platform object writer (address point
 * 0x16a6920): write the bytes as they are; a short write is a failure. */
hkResult hkPlatformObjectWriter::FUN_0019ae90(hkStreamWriter *writer, const void *data,
                                              int size) /* derived name */
{
    return writer->write(data, size) == size ? HK_SUCCESS : HK_FAILURE;
}
