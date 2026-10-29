/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hknpStaticCompoundShape's destructor (slot 0 of its vtable): the bounding
 * volume's reference released, then the compound's destructor. */
hknpStaticCompoundShape::~hknpStaticCompoundShape()
{
    if (boundingVolumeData) {
        boundingVolumeData->removeReference();
        boundingVolumeData = 0;
    }
}
