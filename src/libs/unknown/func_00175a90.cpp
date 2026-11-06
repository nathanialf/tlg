/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The shape tag is kept in a local that starts invalid (its constant debug
 * value trails the size compare, so the branch folder hoists the z
 * maximum both arms begin with between the compare and the jump, cookbook
 * 480); the first sample's index is written x first, as the arms' GVN
 * copies then are. */
void hknpCompressedHeightFieldShape::getQuadInfoAt(int x, int z, Vec4 *heightsOut, u16 *shapeTagOut,
                                                   int *triangleFlipOut) const
{
    *triangleFlipOut = triangleFlip ? 1 : 0;
    u16 shapeTag = 0xffff;
    if (shapeTags.getSize()) {
        shapeTag = shapeTags[sampleIndex(x, z)];
    }
    *shapeTagOut = shapeTag;
    const float h00 = float(storage[hkMath::clamp(x, 0, intSizeX) +
                                    hkMath::clamp(z, 0, intSizeZ) * (intSizeX + 1)]) *
                          scale +
                      offset;
    *heightsOut = _mm_setr_ps(h00, heightAt(x + 1, z), heightAt(x, z + 1), heightAt(x + 1, z + 1));
}
