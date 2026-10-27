/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The character context's destructor (slot 0 of its vtable, 0x16969d0; the
 * deleting destructor 0x3e8c0 in slot 1): the reference to the state
 * manager is given back. */
hknpCharacterContext::~hknpCharacterContext()
{
    stateManager->removeReference();
}
