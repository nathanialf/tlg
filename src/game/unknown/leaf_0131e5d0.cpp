/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_object016d7fa8.h"

/* An input layout made from an array of element descriptions (the callers
 * pass tables of read-only data, 0xbbeb62 and on): each element's offset
 * that follows its slot's last element resolved from the slot's running
 * size, each slot's size rounded up to 4 bytes. The slot is read in the arm
 * that takes the running size (0x131e6e0 `lea rdx, [rsp + r10*4]` in the arm,
 * the store's address formed again); the offset is read back before the
 * element's width is taken (0x131e701 `lea edx, [r11 + rsi + 3]`: the unit's
 * Reassociate ranks the earlier read lower), and the width is FUN_012fd390's,
 * which the link inlines with its divide inside the table's arm. */
void FUN_0131e5d0(const InputElementDesc016d7fa8 *pInputElementDescs, u32 numElements,
                  Object016d7fa8 **ppInputLayout)
{
    Object016d7fa8 *layout = new Object016d7fa8(numElements);
    InputElementDesc016d7fa8 elements[Object016d7fa8::kMaxElements];
    u32 offsets[Object016d7fa8::kMaxElements] = {};
    for (u32 i = 0; i < numElements; i++) {
        const InputElementDesc016d7fa8 &desc = pInputElementDescs[i];
        elements[i] = desc;
        elements[i].AlignedByteOffset = elements[i].AlignedByteOffset == kAppendAlignedElement
                                            ? offsets[elements[i].InputSlot]
                                            : desc.AlignedByteOffset;
        offsets[elements[i].InputSlot] =
            (elements[i].AlignedByteOffset + FUN_012fd390(&D_5adab00[desc.Format]) + 3) & ~3u;
    }
    for (u32 i = 0; i < numElements; i++)
        layout->m_elements[i] = elements[i];
    *ppInputLayout = layout;
}
