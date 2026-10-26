/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Clean a loaded object up through the type's cleanup callback, when it has
 * one. Called on the type info the registry looks up by name (0x17d946) and
 * for each object of a loaded image (0x19bbec). */
void hkTypeInfo::FUN_00092fc0(void *object) const /* derived name */
{
    if (cleanupFunction) {
        cleanupFunction(object);
    }
}
