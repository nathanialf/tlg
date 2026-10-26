/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* Seek: a negative new offset is a failed seek, and the reader keeps
 * whether it worked. */
hkResult FiosStreamReader::FUN_000933a0(int offset, int whence) /* derived name */
{
    ok = sceFiosFHSeek(handle, offset, whence) >= 0;
    return ok ? HK_SUCCESS : HK_FAILURE;
}
