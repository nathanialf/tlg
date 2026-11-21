/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_math.h"

/* derived names: the 0x40-byte slot FUN_0058dd30 asks the device for and
 * fills: three eight-byte fields cleared, one at +0x18 left, an eight-byte
 * and a four-byte field cleared, the x axis at +0x2c (FLOAT4_X: the four
 * floats reach the link as integers, `mov ecx, 0x3f800000; vmovd xmm1, ecx;
 * vmovups [rax+0x2c], xmm1`) and 1 at +0x3c. */
struct Slot58dd30 /* derived name */
{
    void *unknown0;
    void *unknown8;  /* +0x8 */
    void *unknown10; /* +0x10 */
    u8 unknown18[8];
    void *unknown20;  /* +0x20 */
    int unknown28;    /* +0x28 */
    Float4 unknown2c; /* +0x2c */
    float unknown3c;  /* +0x3c */
};

/* derived names: a handler whose address FUN_00525530 takes (lea at
 * 0x52595d): asks the device at +0xf0 for a 0x40-byte slot for its
 * argument (method 0) and fills it when it gets one, then dispatches the
 * node at +0x28 through the owner's handler table; returns 0. Handler
 * unknown. */
int FUN_0058dd30(DeviceOwner583950 *self, Node583950 *node) /* derived name */
{
    Slot58dd30 *slot = static_cast<Slot58dd30 *>(
        self->device->vtable->method0(self->device, node, sizeof(Slot58dd30)));
    if (slot) {
        slot->unknown0 = 0;
        slot->unknown8 = 0;
        slot->unknown10 = 0;
        slot->unknown20 = 0;
        slot->unknown28 = 0;
        slot->unknown2c = FLOAT4_X;
        slot->unknown3c = 1.0f;
    }
    self->dispatch(node->child);
    return 0;
}
