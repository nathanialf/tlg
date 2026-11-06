/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: a collision cache collided between two bodies of the
 * context's world: each body given as its body, quality and material, the
 * whole shape (no motion, no leaf shape, no shape key), the world's shared
 * data filled, and the detector of the cache's type asked (its slot 4).
 * Its one caller is 0x71da6. */
void FUN_00176200(const hknpCollisionCache *cache, hknpWorldContextPool::Context *context,
                  void *argument3, void *argument4, int bodyIndexA, int bodyIndexB,
                  int argument7) /* derived name */
{
    const hknpWorld *world = context->world;
    const hknpBodyQualityLibrary *qualityLibrary = world->qualityLibrary;
    const hknpMaterialLibrary *materialLibrary = world->materialLibrary;
    const hknpBody *bodies = world->bodyManager.bodies.data;
    hknpCdBodyForCollide cdBodyA;
    const hknpBody &bodyA = bodies[bodyIndexA];
    const hknpBodyQuality *qualityA = &qualityLibrary->qualities[bodyA.qualityId];
    const hknpMaterial *materialA = &materialLibrary->entries.elements[bodyA.materialId.value];
    cdBodyA.body = &bodyA;
    cdBodyA.motion = HK_NULL;
    cdBodyA.leafShape = HK_NULL;
    cdBodyA.quality = qualityA;
    cdBodyA.material = materialA;
    cdBodyA.shapeKey = 0xffffffff;
    hknpCdBodyForCollide cdBodyB;
    const hknpBody &bodyB = bodies[bodyIndexB];
    const hknpBodyQuality *qualityB = &qualityLibrary->qualities[bodyB.qualityId];
    const hknpMaterial *materialB = &materialLibrary->entries.elements[bodyB.materialId.value];
    cdBodyB.body = &bodyB;
    cdBodyB.motion = HK_NULL;
    cdBodyB.leafShape = HK_NULL;
    cdBodyB.quality = qualityB;
    cdBodyB.material = materialB;
    cdBodyB.shapeKey = 0xffffffff;
    ModifierSharedData shared;
    shared.FUN_00167c90(world);
    context->modifierManager->collisionDetectors[cache->type]->collide(
        context, &shared, cache, argument3, argument4, &cdBodyA, &cdBodyB, argument7);
}
