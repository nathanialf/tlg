/* src/include/tlg_game_object016c3be0.h: the class whose vtable is at
 * 0x16c3be0, over Object0130acb0, whose entries go back to the object at
 * 0x5adaaa8 (game region; docs/TARGETS.md). Every name here is derived. */
#ifndef TLG_GAME_OBJECT016C3BE0_H
#define TLG_GAME_OBJECT016C3BE0_H

#include "tlg_types.h"
#include "tlg_game_object05adaaa8.h"
#include "tlg_game_object0130acb0.h"

void FUN_0131e2d0(Target0131e2d0 *target, void *entry); /* derived name */

/* an entry handed back to the object 0x5adaaa8 points at, nothing done for
 * none: FUN_0131e2d0 with its member at +0x100b8, then its count at
 * +0x100a0 incremented (as leaf_0131e770.cpp's) */
inline void returnEntry(void *entry) /* derived name */
{
    if (entry) {
        JsDevice *owner = D_5adaaa8;
        FUN_0131e2d0(owner->unknown100b8, entry);
        __sync_fetch_and_add(&owner->unknown100a0, 1);
    }
}

/* derived name: the same for the list at +0x100e8, its count at +0x100b0
 * (as leaf_013224a0.cpp's; JsDeviceContext's destructor) */
inline void returnEntryE8(void *entry) /* derived name */
{
    if (entry) {
        JsDevice *owner = D_5adaaa8;
        FUN_0131e2d0(owner->unknown100e8, entry);
        __sync_fetch_and_add(&owner->unknown100b0, 1);
    }
}

/* derived names: the class whose vtable is at 0x16c3be0
 * (config/vtables.derived.base.txt; built by FUN_012ff2f0 and others). Its
 * complete destructor (0x131fdb0, the row named Object0131fdb0's) hands
 * back the four entries at +0x30, +0x40, +0x48 and +0x58 unless its state
 * at +0x124 is 1 or 3 (`or eax, 2; cmp eax, 3; je`), then runs the base's.
 * The classes over it (leaf_01324580.cpp) hand them back themselves. The
 * other fields are not traced. */
class Object016c3be0 : public Object0130acb0 /* derived name */
{
  public:
    virtual ~Object016c3be0();

  protected:
    /* the context's slot 16 reads the descriptor; AsyncMap reads the
     * descriptors and the dimension */
    friend class JsDeviceContext;
    friend class JsComputeContext;

    void *entry30; /* +0x30: the memory of a texture (AsyncMap adds the surface's offset) */
    u8 unknown38[0x8];
    void *entry40; /* +0x40 */
    void *entry48; /* +0x48 */
    u8 unknown50[0x8];
    void *entry58; /* +0x58 */
    /* +0x60: the buffer's descriptor; its first word the base address's low
     * 32 bits, bits 0 to 11 of the second the high ones, the stride in bits
     * 16 to 29, then the element count (JsDeviceContext's slot 16,
     * AsyncMap, FUN_01314290) */
    u32 descriptor[4]; /* derived name */
    /* +0x70: a texture's descriptor, passed to the surface queries
     * FUN_001ae8e0 and FUN_001ada10 by AsyncMap */
    u32 textureRegs70[8];
    u8 unknown90[0x124 - 0x90];
    /* +0x124: the resource's dimension (AsyncMap's check names the
     * unknown one: `dim != JS_RESOURCE_DIMENSION_UNKNOWN`) */
    int state124;
};

#endif
