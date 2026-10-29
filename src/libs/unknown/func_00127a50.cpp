/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

namespace
{
/* The query the compressed mesh shape's slot 29 walks its mesh tree with
 * (vtable 0x16a3df0, local to the file: its address point 0x16a3e00 stored
 * by one bare lea), 0x30 bytes on the slot's stack: the input's mode, the
 * shape's convex radius, the input's scale and its value at +0x30. Slots 0
 * and 1 are its destructors (the folded empty bodies 0xadd50 and 0x21a00),
 * slot 2 accepts every key (the folded 0x40b0), slot 3 is the work on one
 * primitive (0x127b20), slot 4 returns the scale (0x128640). derived
 * names. */
class TreeQuery00127a50 : public MeshTreeQuery00104000
{
  public:
    TreeQuery00127a50(int mode_, float radius_, const Vec4 &scale_, int value_)
        : mode(mode_), radius(radius_), scale(scale_), value(value_)
    {
    }

    virtual bool unknownVirtual2(u32 key) const
    {
        return true;
    }

    virtual void unknownVirtual3(const void *section, int primitiveIndex, void *collector);

    virtual const Vec4 *unknownVirtual4() const;

    int mode;
    float radius;
    Vec4 scale;
    int value;
};

/* Slot 4 (0x128640). */
const Vec4 *TreeQuery00127a50::unknownVirtual4() const
{
    return &scale;
}
} // namespace

int hknpCompressedMeshShape::FUN_00127a50(const hknpShapeSlot29Input &input,
                                          void *collector) const /* derived name */
{
    TreeQuery00127a50 query(input.mode, convexRadius, input.scale, input.value30);
    data->meshTree.FUN_00104000(collector, &query, false, true, input.flag4);
    return 0;
}
