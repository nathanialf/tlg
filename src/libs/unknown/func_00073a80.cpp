/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

int hknpCapsuleShape::FUN_00073a80(const SignedDistanceInput00073a80 *input,
                                   const SignedDistanceQueryBody &queryBody, float maxDistance,
                                   int vertexIdOffset, void *argument5,
                                   hkBlockStreamWriter *contactsOut) const
{
    const hknpShape *queryShape = queryBody.rootShape;
    if (queryShape->unknownVirtual5() != 3) {
        FUN_0006ebf0(input, queryBody, maxDistance, vertexIdOffset, argument5, contactsOut);
        return 3;
    }
    const hknpCapsuleShape *queryCapsule = static_cast<const hknpCapsuleShape *>(queryShape);
    const hkTransform &transform = *queryBody.transform;
    Vec4 segment[2];
    segment[0] = transformPosition(transform, queryCapsule->a);
    segment[1] = transformPosition(transform, queryCapsule->b);
    hkContactPoint points[3];
    points[0].setDistance(maxDistance);
    points[1].setDistance(maxDistance);
    points[2].setDistance(maxDistance);
    FUN_000950b0(segment, queryCapsule->convexRadius, &a, convexRadius, points);
    if (input->flags & 4) {
        int nearest;
        if (points[1].getDistance() < points[0].getDistance()) {
            points[0].setDistance(HK_REAL_MAX);
            nearest = 1;
        } else {
            points[1].setDistance(HK_REAL_MAX);
            nearest = 0;
        }
        if (points[nearest].getDistance() > points[2].getDistance()) {
            points[nearest].setDistance(HK_REAL_MAX);
        } else {
            points[2].setDistance(HK_REAL_MAX);
        }
    }
    for (int i = 0; i < 3; i++) {
        if (points[i].getDistance() < maxDistance) {
            SignedDistanceContact *contact = static_cast<SignedDistanceContact *>(
                contactsOut->reserve(sizeof(SignedDistanceContact)));
            contact->position = points[i].position;
            contact->normal = points[i].separatingNormal;
            contact->distance = points[i].getDistance();
            contact->sphereIndex = u8(vertexIdOffset + i);
            contact->queryShapeKey = queryBody.shapeKey;
            contact->queryFilterData = queryBody.filterData;
            contact->shapeKey = 0xffffffff;
            contact->shapeTag = 0xffff;
            contactsOut->advance(sizeof(SignedDistanceContact));
        }
    }
    return 3;
}
