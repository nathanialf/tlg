/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The finish constructor, empty: placed by its bytes at the base's shared
 * empty body 0x3b640 (the row FUN_0003b640 keeps its name). */
hknpWorldCinfo::hknpWorldCinfo(hkFinishLoadedObjectFlag flag)
    : materialLibrary(flag), motionPropertiesLibrary(flag), qualityLibrary(flag),
      broadPhaseConfig(flag), collisionFilter(flag), shapeTagCodec(flag)
{
}

hknpWorldCinfo::~hknpWorldCinfo() {}
