/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

// NONMATCHING: 77 of 107, size equal. Two classes left. (1) Each block's
// free sets the size before the allocator (`mov edx, 0xa20; mov rdi, r15`):
// here MachineLICM hoists the size's MOV32ri out of the loop and the
// register coalescer (RegisterCoalescer.cpp, reMaterializeTrivialDef: "Remat:
// %EDX<def> = MOV32ri 2592", a78/llvm33dbg -debug-only=regalloc) puts it
// back at the copy, after the allocator's; the base's stays where isel put
// it, before the copies. (2) The keep test (`test r14b`) is the last
// instruction before the branch in the base, scheduled among the stores
// here. NOTES "Round 78A".
void hkgpConvexHullData::FUN_000aeb20(bool keep100)
{
    freeBlocks(vertexBlocks);
    firstVertex = HK_NULL;
    numVertices = 0;
    freeBlocks(triangleBlocks);
    firstTriangle = HK_NULL;
    numTriangles = 0;
    array68.clear();
    array58.clear();
    array78.clear();
    const Vec4 maxValue = D_14b2060[33];
    vector90 = _mm_blend_ps(_mm_setzero_ps(), maxValue, 8);
    vectorA0 = vector90;
    aabbB0.setEmpty();
    aabbD0.setEmpty();
    flag1ec = false;
    flag1ee = false;
    flag1ed = false;
    value1e4 = 0;
    frame140.setIdentity();
    vector170 = _mm_setzero_ps();
    vector180 = _mm_setzero_ps();
    frame190.setIdentity();
    vectorF0 = _mm_setzero_ps();
    vector1c0 = _mm_setzero_ps();
    vector1d0 = _mm_setzero_ps();
    dimension = -1;
    vector110 = _mm_setzero_ps();
    vector120 = _mm_setzero_ps();
    pointer130 = HK_NULL;
    pointer138 = HK_NULL;
    if (!keep100) {
        vector100 = _mm_setzero_ps();
    }
}
