/* src/include/tlg_game_object016d7fa8.h: the render's input layout object
 * (derived name), made by FUN_0131e5d0 from an array of element
 * descriptions. No string names the class; it is named for its vtable row
 * _ZTV14Object016d7fa8 (0x16d7fa8, config/vtables.derived.base.txt, D12).
 * Its destructors are the empty ones five classes share (0x14968f0 and
 * 0x1496900, in the stretch of inline functions): it declares none, and the
 * unit that constructs it emits them and the vtable. */
#ifndef TLG_GAME_OBJECT016D7FA8_H
#define TLG_GAME_OBJECT016D7FA8_H

#include "tlg_types.h"

#include "tlg_game_format012fd300.h"
#include "tlg_game_object0130acb0.h"

/* derived name: an element's offset that follows the slot's last element */
static const u32 kAppendAlignedElement = 0xffffffff;

/* derived names: an element of the layout (0x20 bytes: the creator copies
 * them whole), as the creator reads them: the slot at +0x10, the offset at
 * +0x14, the format at +0xc indexing the format words at 0x5adab00 */
struct InputElementDesc016d7fa8 { /* field names derived */
    const char *SemanticName;     /* +0x0 */
    u32 SemanticIndex;            /* +0x8 */
    u32 Format;                   /* +0xc */
    u32 InputSlot;                /* +0x10 */
    u32 AlignedByteOffset;        /* +0x14 */
    u32 InputSlotClass;           /* +0x18 */
    u32 InstanceDataStepRate;     /* +0x1c */
};

/* derived name: the format words an element's format selects, built by the
 * static initializer 0x131e4d0 */
extern Format012fd300 D_5adab00[];

class Object016d7fa8 : public Object0130acb0 /* derived name */
{
  public:
    /* derived name: the most elements a layout holds (0x400 bytes of them
     * from +0x30) */
    static const u32 kMaxElements = 32;

    /* kind 0x11 */
    explicit Object016d7fa8(u32 numElements) : Object0130acb0(0x11), m_numElements(numElements) {}

    InputElementDesc016d7fa8 m_elements[kMaxElements]; /* +0x30 (derived name) */
    u32 m_numElements;                                 /* +0x430 (derived name) */
};

#endif
