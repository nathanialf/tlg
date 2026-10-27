/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the stub's XML save (hkSerializeDeprecated's slot 6):
 * nothing is written, and the error is reported unless one was already. */
hkResult hkSerializeDeprecated::FUN_0019a450(const void *object, const void *klass, void *writer,
                                             const void *options, void *listener,
                                             SerializeErrorDetails *errorOut)
{
    if (errorOut && errorOut->id == 0) {
        errorOut->id = 7;
        FUN_0000e620(&errorOut->defaultMessage, D_14cc986);
    }
    return HK_FAILURE;
}
