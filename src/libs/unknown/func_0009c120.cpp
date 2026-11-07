/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The deleting destructor (0x9c0d0) is emitted here with it, the object
 * given back to the thread's heap at its recorded size. */
hkcdPlanarCsgOperand::~hkcdPlanarCsgOperand()
{
    regions = HK_NULL;
    solid = HK_NULL;
    danglingGeometry = HK_NULL;
}
