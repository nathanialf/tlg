/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The ray cast with the provider and its storage on the stack: inlined
 * into the caller after the caller's view is built, so the provider's slot
 * comes before the view's in the frame. derived name. */
static bool castRay(const VertexView000a6d60 &view, const void *ray, RayHit000a6d60 *hit)
{
    Collector000a6d60 collector;
    RayCastStorage0009fed0 storage;
    return FUN_0009fed0(&storage, &collector, &view, HK_NULL, ray, &collector, &hit->fraction,
                        &hit->normal);
}

/* A ray cast against a set of vertices (0xa6d60; hknpConvexShape's
 * vertices from 0x435a0 and six other callers): true when it hits with a
 * fraction other than zero. derived name. */
bool FUN_000a6d60(const Vec4 *vertices, int numVertices, const void *ray, RayHit000a6d60 *hit)
{
    VertexView000a6d60 view;
    view.vertices = vertices;
    view.numVertices = numVertices;
    return castRay(view, ray, hit) && _mm_ucomineq_ss(hit->fraction, _mm_setzero_ps());
}
