/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 28's default: the shape's bounds in its own space
 * (slot 7 under the identity), handed on with both arguments. */
// NONMATCHING: equal in quick_diff (34 instructions, 104 bytes); the gate's
// layout cannot place the folded GOT load of the constant table (`mov esi,
// 0x1d0; add rsi, [rip+GOT]`, slot 0x16d80d8, a RELATIVE relocation to
// 0x14b2060): "no GOT slot in the base and not a relaxable load". A tooling
// question, docs/NOTES.md Round 44.
void hknpShape::FUN_0006fc70(const void *argument1, void *argument2) const
{
    hkAabb aabb;
    unknownVirtual7(identityTransform(), aabb);
    FUN_00168230(argument1, aabb, argument2);
}
