/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the stub's load of an old packfile (hkSerializeDeprecated's
 * slots 8 and 9): nothing is loaded, and the error is reported unless one
 * was already. */
void *hkSerializeDeprecated::FUN_0019a490(void *reader, const void *details,
                                          SerializeErrorDetails *errorOut)
{
    if (errorOut && errorOut->id == 0) {
        errorOut->id = 7;
        errorOut->defaultMessage = D_14cca20;
    }
    return 0;
}
