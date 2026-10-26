/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hkcdPlanarCsgOperand::hkcdPlanarCsgOperand(hkFinishLoadedObjectFlag flag)
    : hkReferencedObject(flag), regions(0)
{
}
