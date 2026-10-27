/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The thread taken down, then its router given back to the memory system;
 * the router's own destructor runs last. */
hkWorkerThreadContext::~hkWorkerThreadContext()
{
    FUN_00009a80();
    FUN_00006c50()->threadQuit(memoryRouter, 3);
}
