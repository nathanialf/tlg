/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hknpCompoundShape's destructor (slot 0 of its vtable): the destroyed
 * signal fired, then the members: the signals, the instances' free-list
 * array (each live instance's shape released, then the storage), and the
 * composite shape's inline. The deleting destructor (0x41600, slot 1) is
 * emitted beside it. The fire loop is cookbook 168. */
hknpCompoundShape::~hknpCompoundShape()
{
    mutationSignals.shapeDestroyed.fire();
}
