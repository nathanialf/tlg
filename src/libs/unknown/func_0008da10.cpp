/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the cleanup callback of hkxEnvironment::Variable's type
 * info (0x57c8100): destroys the struct in place, its strings in the
 * reverse of their order through hkStringPtr's out-of-line destructor. */
void FUN_0008da10(void *object) /* derived name */
{
    static_cast<hkxEnvironmentVariable *>(object)->~hkxEnvironmentVariable();
}
