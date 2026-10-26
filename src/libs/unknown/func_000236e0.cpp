/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkIndexedTransformSet's finish constructor: the loaded arrays and strings
 * need no fixing up, so only the vtable is set (called by the finish
 * callback 0x24400 and by the reflection initializer at 0x24525). */
hkIndexedTransformSet::hkIndexedTransformSet(hkFinishLoadedObjectFlag flag)
    : hkReferencedObject(flag), matrices(flag), inverseMatrices(flag), matricesOrder(flag),
      matricesNames(flag), indexMappings(flag)
{
}
