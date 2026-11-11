/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Whether a and b are equal in x, y and z (derived name). */
static inline bool allEqual3(const Vec4 &a, const Vec4 &b)
{
    const __m128 xyz = _mm_blend_ps(_mm_setzero_ps(), _mm_castsi128_ps(_mm_set1_epi32(-1)), 7);
    return _mm_testc_si128(_mm_castps_si128(_mm_and_ps(_mm_cmpeq_ps(a, b), xyz)),
                           _mm_castps_si128(xyz));
}

/* Slot 22: the leaf of the instance the first key names (derived names).
 * The instance's transform is composed into the output's, its translation
 * under the output's scale, and the scale multiplied by the instance's; a
 * composite child is recorded as a level and handed the leading keys that
 * stay in the instance (at most ten, each past this shape's bits); a
 * convex child under a scale other than one is built as a scaled convex
 * shape in the output's buffer, any other child is the leaf itself. */
// NONMATCHING: 144 of 216 by difflib at the base's instruction count, 957 bytes for 941. Landed: the
// instance's transform read into a local first (its columns loaded once for the three cases), the
// translation multiplied as instance by scale (the scale's load then stays in each path and is PRE'd
// where neither flag is set), the composed translation read after the columns are stored (computed
// last, as in the base). Residuals: (1) that translation's load is folded into its add here, where
// the base loads it with the columns and adds in xmm0, which lets the translation-only case share
// the store and mask by tail merging (the 16 bytes; the xmm numbering follows); (2) the loop's key
// compare is 32-bit (InstCombine turns the key's sext(trunc) into shl/ashr); u16 operands give a
// 16-bit `xor`, not the base's `cmp ax, r8w`.
void hknpCompoundShape::FUN_00041a80(const u32 *keys, int numKeys,
                                     hknpShapeSlot22Output *output) const
{
    hknpShapeInstanceId instanceId;
    instanceId.value = short(keys[0] >> (32 - numShapeKeyBits));
    const hknpShapeInstance &instance = instances[instanceId];
    const hknpShape *shape = instance.shape;
    const int flags = instance.getFlags();
    if (flags & hknpShapeInstance::HAS_ROTATION) {
        hkTransform transform;
        transform.translation = _mm_mul_ps(instance.transform.translation, output->scale);
        transform.rotation = instance.transform.rotation;
        if (output->flags & hknpShapeSlot22Output::TRANSFORM_IS_IDENTITY) {
            output->transform = transform;
        } else if (output->flags & hknpShapeSlot22Output::TRANSFORM_IS_TRANSLATION) {
            output->transform.rotation = transform.rotation;
            output->transform.translation =
                _mm_add_ps(transform.translation, output->transform.translation);
        } else {
            const Vec4 c0 = output->transform.rotation.col0;
            const Vec4 c1 = output->transform.rotation.col1;
            const Vec4 c2 = output->transform.rotation.col2;
            output->transform.rotation.col0 = combineColumns(c0, c1, c2, transform.rotation.col0);
            output->transform.rotation.col1 = combineColumns(c0, c1, c2, transform.rotation.col1);
            output->transform.rotation.col2 = combineColumns(c0, c1, c2, transform.rotation.col2);
            output->transform.translation = _mm_add_ps(
                output->transform.translation, combineColumns(c0, c1, c2, transform.translation));
        }
        output->flags = (output->flags & ~(hknpShapeSlot22Output::TRANSFORM_IS_IDENTITY |
                                           hknpShapeSlot22Output::TRANSFORM_IS_SET |
                                           hknpShapeSlot22Output::TRANSFORM_IS_TRANSLATION)) |
                        hknpShapeSlot22Output::TRANSFORM_IS_SET;
    } else if (flags & hknpShapeInstance::HAS_TRANSLATION) {
        const Vec4 translation = _mm_mul_ps(instance.transform.translation, output->scale);
        if (output->flags & hknpShapeSlot22Output::TRANSFORM_IS_TRANSLATION) {
            output->transform.translation = _mm_add_ps(translation, output->transform.translation);
        } else {
            const hkMatrix3 &rotation = output->transform.rotation;
            output->transform.translation =
                _mm_add_ps(combineColumns(rotation.col0, rotation.col1, rotation.col2, translation),
                           output->transform.translation);
        }
        output->flags = (output->flags & ~(hknpShapeSlot22Output::TRANSFORM_IS_IDENTITY |
                                           hknpShapeSlot22Output::TRANSFORM_IS_SET)) |
                        hknpShapeSlot22Output::TRANSFORM_IS_SET;
    }
    output->scale = _mm_mul_ps(output->scale, instance.scale.quad);
    output->leafShape = this;

    if (shape->dispatchType == hknpCollisionDispatchType::COMPOSITE) {
        hknpShapeSlot22Output::Level &level = output->levels[output->numLevels++];
        level.shapeTag = instance.shapeTag;
        level.shape = this;
        level.index = instanceId.value;
        level.child = shape;
        const int count = hkMath::min2(numKeys, 10);
        u32 childKeys[10];
        childKeys[0] = keys[0] << numShapeKeyBits;
        int n = 1;
        for (; n < count; n++) {
            if (short(keys[n] >> (32 - numShapeKeyBits)) != instanceId.value) {
                break;
            }
            childKeys[n] = keys[n] << numShapeKeyBits;
        }
        shape->unknownVirtual22(childKeys, n, output);
        return;
    }

    if (!allEqual3(output->scale, D_14b2060[3]) &&
        shape->dispatchType == hknpCollisionDispatchType::CONVEX) {
        hknpScaledConvexShapeBase *scaledShape =
            reinterpret_cast<hknpScaledConvexShapeBase *>(output->scaledShapeBuffer);
        output->shape = scaledShape;
        const int scaleMode = (flags & hknpShapeInstance::SCALE_SURFACE) ? 0 : 1;
        new (scaledShape)
            hknpScaledConvexShapeBase(shape->asConvexShape(), output->scale, scaleMode);
        scaledShape->setMemSize(0);
        output->scale = D_14b2060[3];
    } else {
        output->shape = shape;
    }
    output->quadShapeTags[0] = instance.shapeTag;
    output->flags &= ~8;
    output->value = 1;
}
