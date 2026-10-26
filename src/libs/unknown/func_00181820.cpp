/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The static class name registry's constructor (derived names): the list
 * and its version kept, the flag set, the name stored in the body. */
// NONMATCHING: equal, but the vtable 0x16a63b0 has no row (no type info; a D14 ruling)
hkStaticClassNameRegistry::hkStaticClassNameRegistry(const hkClass *const *classes,
                                                     int classVersion, const char *name)
    : classes(classes), classVersion(classVersion), ready(1)
{
    this->name = name;
}
