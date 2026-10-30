/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

StreamReader *FUN_00093180(const char *path)
{
    SceFiosOpenParams params = {};
    params.openFlags = 1; /* read */
    SceFiosFH handle;
    if (sceFiosFHOpenSync(0, &handle, path, &params) != 0) {
        return 0;
    }
    return new FiosStreamReader(handle);
}
