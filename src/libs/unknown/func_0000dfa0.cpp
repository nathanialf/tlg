/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Slot 8 of hkSimpleLocalFrame's vtable (address point 0x168d8f0). */
void hkSimpleLocalFrame::FUN_0000dfa0(const Vec4 &target, float maxDistance,
                                      hkLocalFrameCollector &collector) const
{
    const float distance = _mm_cvtss_f32(length3(_mm_sub_ps(target, transform.translation)));
    if (distance <= maxDistance) {
        collector.addFrame(this, distance);
    }
    if (children.getSize() > 0) {
        Vec4 targetLocal;
        FUN_00010f90(targetLocal, transform, target);
        for (int i = 0; i < children.getSize(); i++) {
            children[i]->FUN_0000dfa0(targetLocal, maxDistance, collector);
        }
    }
}
