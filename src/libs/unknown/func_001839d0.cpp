/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkDebugDisplay::FUN_001839d0(const hkVector4 &start, const hkVector4 &end, int color, int id,
                                  int tag)
{
    lock->enter();
    for (int i = 0; i < handlers.getSize(); i++) {
        handlers[i]->displayLine(start, end, color, id, tag);
    }
    lock->leave();
}
