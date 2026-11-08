/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the previous surface velocity's address, beside the
 * setter 0x3ea60; the on-ground state calls it (0x6fdd7), and a game
 * class's identical body was folded onto it, so it also fills slot 4 of
 * the vtable at 0x16b1508. */
const Vec4 &hknpCharacterContext::FUN_0003ea80() const
{
    return previousSurfaceVelocity;
}
