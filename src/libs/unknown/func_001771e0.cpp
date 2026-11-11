/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The pointer to a body's element of a property map's field, none when
 * the body has none (derived name). */
static inline void *const *bodyProperty(const BitFieldMap00199770 &map, int bodyIndex,
                                        u16 key) /* derived name */
{
    const BitFieldMap00199770::Block *block =
        map.fields.FUN_00199520<BitFieldMap00199770::Block *>(key, 0);
    if (block && u32(bodyIndex) < u32(block->bits.storage.numBits) && block->bits.get(bodyIndex)) {
        return &block->elements[u32(bodyIndex)];
    }
    return HK_NULL;
}

// NONMATCHING: 109 of 111 (docs/NOTES.md, Round 76B): the touched body's id is loaded once,
// sign-extended (`movsxd rbx`); CodeGenPrepare's MoveExtToFormExtLoad moves the property index's
// zext of that i32 load into the flags test's block, a live-out copy list-ilp schedules first,
// so the id's load comes before the world's (`mov r15, [r14+0x18]`), where the base loads the
// world first: in the base the zext's operand was not the load (no zext was live out).
void hknpCharacterProxy::FUN_001771e0(const hknpCharacterProxyContact &contact,
                                      const hknpMaterial *material, Elements000760c0 *sink)
{
    const float distance = lane(contact.contactPoint.separatingNormal, 3);
    hknpManifold manifold;
    manifold.init();
    manifold.numPoints = 1;
    for (int i = 0; i < 4; i++) {
        manifold.distances[i] = distance;
    }
    manifold.minDistance = distance;
    for (int i = 0; i < 4; i++) {
        manifold.positions[i].quad = contact.contactPoint.position;
    }
    manifold.normal.quad = contact.contactPoint.separatingNormal;
    manifold.material = material;

    ContactParams001771e0 params;
    params.restitution = contact.flag28 == 1 ? 0.0f : 1.0f;
    Pair08Owner *record = HK_NULL;
    sink->FUN_000769c0(bodyId.value, contact.bodyId.value, &manifold, material, material, &params,
                       &record);

    const hknpWorld *const proxyWorld = world;
    const int bodyIndex = contact.bodyId.value;
    if (proxyWorld->bodyManager.bodies[bodyIndex].flags & 2) {
        const float share = contactShare;
        Pair08Owner *const contactRecord = record;
        if (!bodyProperty(proxyWorld->bodyManager.fieldMap, bodyIndex, 0xf002)) {
            FUN_00034970(contactRecord, 3, share * _mm_cvtss_f32(proxyWorld->solverInfo.vector20));
        }
    }
}
