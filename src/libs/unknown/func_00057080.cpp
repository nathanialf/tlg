/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: an extern mesh's closest points against the target, a
 * triangle at a time: each triangle set into the context's query triangle
 * with the mesh's convex radius, its key appended to the query's path (no
 * key mask below the mesh), its filter data decoded from its shape tag when
 * the context has a codec, then the pair dispatched. */
void FUN_00057080(hknpCollisionQueryContext *context, const hknpClosestPointsQuery &query,
                  const hknpShapeQueryInfo &queryShapeInfo, const hknpShape &targetShape,
                  const hknpQueryFilterData &targetShapeFilterData,
                  const hknpShapeQueryInfo &targetShapeInfo, const hkTransform &queryToTarget,
                  bool queryAndTargetSwapped, hknpCollisionQueryCollector *collector)
{
    const hknpExternMeshShape *meshShape = static_cast<const hknpExternMeshShape *>(query.shape);
    const hknpExternMeshShape::Geometry *geometry = meshShape->geometry;
    for (int i = 0; i < geometry->unknownVirtual5(); i++) {
        Vec4 vertices[3];
        geometry->unknownVirtual6(i, vertices);
        hknpTriangleShape *triangle = context->queryTriangle;
        triangle->FUN_00078500(vertices[0], vertices[1], vertices[2]);
        triangle->convexRadius = meshShape->convexRadius;
        hknpShapeQueryInfo triangleInfo(queryShapeInfo, HK_NULL);
        triangleInfo.keyPath.appendSubKey(i, meshShape->numShapeKeyBits);
        hknpClosestPointsQuery triangleQuery = query;
        triangleQuery.shape = triangle;
        if (context->shapeTagCodec) {
            const u16 shapeTag = geometry->unknownVirtual7(i);
            context->shapeTagCodec->unknownVirtual6(
                shapeTag, 4, queryShapeInfo.body, queryShapeInfo.unknown8, meshShape,
                triangleInfo.keyPath.key, triangle, &triangleQuery.filterData);
        }
        context->dispatcher->FUN_00070ae0(context, triangleQuery, triangleInfo, targetShape,
                                          targetShapeFilterData, targetShapeInfo, queryToTarget,
                                          queryAndTargetSwapped, collector);
    }
}
