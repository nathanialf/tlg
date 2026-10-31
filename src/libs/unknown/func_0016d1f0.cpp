/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names (config/vtables.derived.base.txt): the out-of-line
 * constructor of a modifier (vtable 0x16a5600) built at +0x68 of the object the function at 0x49d8b creates
 * (a reference-counted set, vtable 0x16991e0, holding twenty modifiers from
 * +0x10 to +0xd8; the call at 0x49dd8). Its vtable has the thirteen slots of
 * the modifier interface the set's members share: slot 0 the empty body
 * 0x16a370, slot 1 the empty deleting body 0xd900, slot 2 (0x46980) the mask
 * of the callbacks it implements, 8, and of slots 3 to 12 only slot 7
 * (0x16d200), the callback of mask bit 3 in every member that sets it
 * (0x16a4dd0, 0x16a4850, 0x16a5010). Slot 7 averages the manifold's contact
 * positions, asks each body's material for its surface velocity there (the
 * object at +0x30 of the material, its slot 5, linear and angular), takes
 * the difference of the two bodies' and applies it to the contact jacobian
 * (0x348e0): a surface velocity modifier. Slot 4 is the empty 0x158a30, slot
 * 6 the shared 0x69440, the rest the empty 0x3b640. */
hknpSurfaceVelocityModifier::hknpSurfaceVelocityModifier() {}
