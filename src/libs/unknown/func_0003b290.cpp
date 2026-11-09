/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hknpWorldCinfo::hknpWorldCinfo()
{
    hkString::memSet16(this, &D_14b2060[2], sizeof(*this) / 16);
    simulationType = 1;
    numSplitterCells = 16;
    solverMicrosteps = 1;
    defaultSolverTimestep = 1.0f / 30.0f;
    unitScale = 1.0f;
    applyUnitScaleToStaticConstants = true;
    relativeCollisionAccuracy = 0.005f;
    bodyBufferCapacity = 4096;
    userBodyBuffer = HK_NULL;
    motionBufferCapacity = 4096;
    userMotionBuffer = HK_NULL;
    constraintBufferCapacity = 512;
    userConstraintBuffer = HK_NULL;
    materialLibrary = HK_NULL;
    motionPropertiesLibrary = HK_NULL;
    qualityLibrary = HK_NULL;
    enableContactCaching = true;
    enableWeldingForDefaultObjects = false;
    enableWeldingForCriticalObjects = false;
    collisionFilter = HK_NULL;
    shapeTagCodec = HK_NULL;
    persistentStreamAllocator = HK_NULL;
    mergeEventsBeforeDispatch = true;
    maxApproachSpeedForHighQualitySolver = 1.0f;
    enableDeactivation = true;
    deleteCachesOnDeactivation = false;
    broadPhaseConfig = HK_NULL;
    collisionTolerance = 0.05f;
    gravity.quad = _mm_setr_ps(0.0f, -9.81f, 0.0f, 0.0f);
    solverTau = 0.6f;
    solverDamp = 1.0f;
    solverIterations = 4;
    broadPhaseAabb.min = _mm_setr_ps(-1000.0f, -1000.0f, -1000.0f, 0.0f);
    broadPhaseAabb.max = _mm_setr_ps(1000.0f, 1000.0f, 1000.0f, 0.0f);
}
