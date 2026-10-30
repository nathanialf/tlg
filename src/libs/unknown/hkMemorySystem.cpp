/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The memory system interface's destructor, out of line and empty: the
 * free-list system's complete destructor 0xc360 ends in a tail jump to it.
 * The linker kept this body (0x6c80, a lone ret) for empty functions of
 * other classes too: nine vtable slots and six address takers cite it, and
 * resolve by address (D15). */
hkMemorySystem::~hkMemorySystem() {}
