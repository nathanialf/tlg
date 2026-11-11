/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The deactivation's object destroyed (0x62770; the world's destructor
 * calls it at 0x4b623): every group entry deleted and the entries' array
 * emptied, then the members' own destructors, the last first. */
hknpWorldObject4f8::~hknpWorldObject4f8()
{
    for (int i = 0; i < unknown18.getSize(); i++) {
        delete unknown18[i];
    }
    unknown18.clearAndDeallocate();
}
