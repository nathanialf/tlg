/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 100 of 104, the FoldTwoEntryPHINode class of 0x1571c0 (docs/NOTES.md, Round 76B):
// the combined properties' lifetime ends in a block of its own after the volume test, whose
// two-entry phi [1, 0] SimplifyCFG folds into a select and InstCombine into `zext` (`sete;
// movzx`), where the base branches (`je` to the shared exit holding 1, `xor r15d, r15d` on the
// way out). The success return inside a scope keeps the branch with the arms reversed.
hkResult FUN_00168590(const MassConfig00168340 &config, const Vec4 *vertices, float radius,
                      hkDiagonalizedMassProperties &propertiesOut)
{
    hkInplaceArray<hkMassElement, 2> elements(2);
    if (FUN_000280e0(vertices[0], vertices[1], vertices[2], 1.0f, radius, elements[0].properties) ==
        HK_FAILURE) {
        return HK_FAILURE;
    }
    if (FUN_000280e0(vertices[2], vertices[3], vertices[0], 1.0f, radius, elements[1].properties) ==
        HK_FAILURE) {
        return HK_FAILURE;
    }
    hkMassProperties massProperties;
    FUN_000298a0(elements, massProperties);
    propertiesOut.FUN_00026300(massProperties);
    if (massProperties.volume == 0.0f) {
        return HK_FAILURE;
    }
    return HK_SUCCESS;
}
