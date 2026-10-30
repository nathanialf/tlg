/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The smallest and the largest of a vector's four lanes, in every lane: the
 * halves swapped, then the pairs. derived names. */
static Vec4 horizontalMin(const Vec4 &v) /* derived name */
{
    const Vec4 pairs = _mm_min_ps(_mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 0, 3, 2)), v);
    return _mm_min_ps(pairs, _mm_shuffle_ps(pairs, pairs, _MM_SHUFFLE(2, 3, 0, 1)));
}

static Vec4 horizontalMax(const Vec4 &v) /* derived name */
{
    const Vec4 pairs = _mm_max_ps(_mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 0, 3, 2)), v);
    return _mm_max_ps(pairs, _mm_shuffle_ps(pairs, pairs, _MM_SHUFFLE(2, 3, 0, 1)));
}

/* The bounding volume's box: with a build context the simd tree's root
 * node's four boxes together (w zero), else the static tree's domain,
 * its bounds copied one after the other (each stored before the next is
 * read, as Havok's vector members assign). */
void hknpExternMeshShape::FUN_000ed580(hkAabb &aabbOut) const
{
    const hknpExternMeshShapeData *data = boundingVolumeData;
    if (data->buildContext) {
        const hkcdSimdTree::Node &root = data->simdTree.nodes[1];
        aabbOut.min = setFromScalars(horizontalMin(root.lx.quad), horizontalMin(root.ly.quad),
                                     horizontalMin(root.lz.quad), D_14b2060[2]);
        aabbOut.max = setFromScalars(horizontalMax(root.hx.quad), horizontalMax(root.hy.quad),
                                     horizontalMax(root.hz.quad), D_14b2060[2]);
    } else {
        aabbOut.min = data->aabbTree.domain.min;
        aabbOut.max = data->aabbTree.domain.max;
    }
}
