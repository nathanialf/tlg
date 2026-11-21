/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_lib_unknown.h"

/* derived names: a shape's mass properties set from a description (called
 * by 0xea5100, 0xea53a0, 0xea5be0, 0xea6330, 0xea6700, 0xea6d90 and
 * 0xeaaa30): built by the shape's slot 28 for quality 2, the description's
 * inertia factor (+0x68) and its density (+0x64, at least 1e-05), the
 * centre of mass moved by the description's three floats at +0x70 (w
 * zero), then kept compressed under key 0xf100 as the static compound
 * shape's constructor keeps them (0x38440): in the object already there or
 * a new one, whose own reference is released once the properties hold it.
 * The description is not traced. */
/* A configuration for a density, at least 1e-05, and an inertia factor,
 * returned by value (twelve bytes in two registers: the quality and the
 * inertia factor stored as one eight-byte word). derived name. */
inline MassConfig00168340 massConfigForDensity(float density, float inertiaFactor)
{
    MassConfig00168340 config;
    config.quality = 2;
    config.inertiaFactor = inertiaFactor;
    config.massOrNegativeDensity = -(density > 1e-05f ? density : 1e-05f);
    return config;
}

struct MassDescription00eaaf80 { /* derived name */
    u8 unknown0[0x64];
    float density;       /* +0x64 */
    float inertiaFactor; /* +0x68 */
    u8 unknown6c[0x70 - 0x6c];
    float centerOfMassOffset[3]; /* +0x70 */
};

// NONMATCHING: loadXYZ_0's zero upper lane only (the zero's vxorps before the double's vunpcklpd; 106 of 109 equal); equal with r248784's demanded-elements change for bitcasts (the probe -tlg-bitcast-demanded at both stages, round 388D), as leaf_00ea0b80.cpp
void FUN_00eaaf80(hknpShape *shape, const MassDescription00eaaf80 *description) /* derived name */
{
    const MassConfig00168340 config =
        massConfigForDensity(description->density, description->inertiaFactor);
    hkDiagonalizedMassProperties massProperties;
    shape->unknownVirtual28(&config, &massProperties);
    massProperties.centerOfMass =
        _mm_add_ps(loadXYZ_0(description->centerOfMassOffset), massProperties.centerOfMass);
    hknpShapeMassProperties *shapeMassProperties =
        static_cast<hknpShapeMassProperties *>(shape->getProperty(0xf100));
    const bool kept = shapeMassProperties != HK_NULL;
    if (!kept) {
        shapeMassProperties = new hknpShapeMassProperties();
    }
    shapeMassProperties->compressedMassProperties.FUN_00026100(massProperties);
    shape->setProperty(0xf100, shapeMassProperties);
    if (!kept) {
        shapeMassProperties->removeReference();
    }
}
