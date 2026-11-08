/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hknpBodyManager::hknpBodyManager(void *argument, hknpBody *userBodyBuffer, int capacity)
    : pointer0(argument), motionManager(HK_NULL), firstFreeBodyId(0x7fffffff),
      firstFreeRecord68(-1), numBodies98(0), peakBodyId(0)
{
    FUN_0015fd30(userBodyBuffer, capacity);

    /* Body 0, the static body: cleared as zero vectors, its byte at +0x7f
     * one, static, no motion, the default material, at the identity. */
    hknpBody &body = bodies[0];
    hkString::memSet16(&body, &D_14b2060[2], sizeof(hknpBody) / 16);
    body.byte7f = 1;
    body.flags = hknpBody::IS_STATIC;
    body.motionId = 0;
    body.materialId.value = 0;
    body.setTransformKeepingW(reinterpret_cast<const hkTransform &>(identityTransform()));
    previousAabbs[0].setEmpty();
    activeBodyCellIndices[0] = 0xff;
    scheduledBodyChangeIndices[0] = 0x7fffffff;
    firstFreeBodyId = 1;
    peakBodyId = 0;
    numBodies98 = 1;
}
