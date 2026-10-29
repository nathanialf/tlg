/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hknpCompoundShape's destructor (slot 0 of its vtable): the destroyed
 * signal fired, then the members: the signals, the instances' free-list
 * array (each live instance's shape released, then the storage), and the
 * composite shape's inline. The deleting destructor (0x41600, slot 1) is
 * emitted beside it. */
// NONMATCHING: the fire loop (docs/NOTES.md, Round 50): the inlining is the
// base's since the free-list array's and hkArray's destructors and
// clearAndDeallocate are declared inline (the hinted threshold, D21); the
// coalescer joins the outer slot phi with the next link (the outer latch
// block numbered before the outer header) where the base joins it with the
// inner slot phi: 96 of 137 instructions, 514 bytes against 530, the rest
// equal but for the loop's alignment.
hknpCompoundShape::~hknpCompoundShape()
{
    mutationSignals.shapeDestroyed.fire();
}
