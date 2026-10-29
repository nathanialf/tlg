/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hknpCompoundShape's destructor (slot 0 of its vtable): the destroyed
 * signal fired, then the members: the signals, the instances' free-list
 * array (each live instance's shape released, then the storage), and the
 * composite shape's inline. The deleting destructor (0x41600, slot 1) is
 * emitted beside it. */
// NONMATCHING: two residuals (docs/NOTES.md, Round 49). The inliner: the
// base inlines the instances' storage free (hkArray::clearAndDeallocate);
// the fixed line calls it, and inlines it at a threshold of 275, -O3's
// (0x33990's class, D21). The fire loop (0x93570's family): at 275 the loop
// separates into an outer and an inner loop as in the base, but the
// coalescer joins the outer slot phi with the next link (the outer latch
// block numbered before the outer header) where the base joins it with the
// inner slot phi: 96 of 137 instructions, 514 bytes against 530.
hknpCompoundShape::~hknpCompoundShape()
{
    mutationSignals.shapeDestroyed.fire();
}
