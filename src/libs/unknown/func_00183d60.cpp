/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The lock and the entries go with the factory; the class's key function:
 * its vtable (0x16a6530) and deleting destructor (0x183d60) are emitted with
 * it. */
hkProcessFactory::~hkProcessFactory()
{
    delete lock;
}
