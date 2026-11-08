/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the worker's arrays, the last three sized to the vertices
 * and four more, then the weld itself (0x189540) with the flag clear. */
void FUN_001891e0(hkGeometry *geometry, float tolerance)
{
    hkArray<int> arrayA;
    hkArray<int> arrayB;
    hkArray<Vec4> arrayC;
    hkArray<WeldRecord00189540> arrayD(geometry->vertices.getSize() + 4);
    hkArray<WeldLink00189540> arrayE(geometry->vertices.getSize() + 4);
    hkArray<WeldRecord00189540> arrayF(geometry->vertices.getSize() + 4);
    FUN_00189540(geometry, tolerance, false, arrayA, arrayB, arrayC, arrayD, arrayE, arrayF);
}
