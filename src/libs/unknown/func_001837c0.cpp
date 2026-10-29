/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The lock and the handlers' array go with the display; the class's key
 * function: its vtable (0x16a64f0) and deleting destructor (0x1837c0) are
 * emitted with it. */
hkDebugDisplay::~hkDebugDisplay()
{
    delete lock;
}
