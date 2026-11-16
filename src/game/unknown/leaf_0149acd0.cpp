/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 3 of the vtable at 0x16d8080 (its pointer at
 * 0x16d80a8; Object016d8080, stored by FUN_01324860, home
 * JsUnorderedAccessView.cpp), as FUN_0149a270 (leaf_0149a270.cpp) for
 * another class: brings the object's copy of its source's surface up to date
 * when the source's buffer (+0x160) is not the one seen last: kind 1 copies
 * the word at +0x60 and the low twelve bits of the one at +0x64 to +0x74 and
 * +0x78; any other kind sets the object's descriptor at +0x54 from the value
 * FUN_012fcd90 reads out of the source's descriptor at +0x70. The descriptor
 * and both classes are not traced. */
struct Descriptor0149acd0; /* derived name */

struct Source0149acd0 { /* derived name */
    u8 unknown0[0x60];
    unsigned unknown60;      /* +0x60 */
    unsigned unknown64 : 12; /* +0x64 */
    unsigned unknown64b : 20;
    u8 unknown68[8];
    u8 unknown70[0xf0]; /* +0x70: a descriptor */
    void *buffer;       /* +0x160 */
};

struct Object0149acd0 { /* derived name */
    u8 unknown0[0x30];
    Source0149acd0 *source; /* +0x30 */
    void *seen;             /* +0x38: the source's buffer when last brought up to date */
    u8 unknown40[4];
    int kind; /* +0x44 */
    u8 unknown48[0xc];
    u8 unknown54[0x20];      /* +0x54: a descriptor */
    unsigned unknown74;      /* +0x74 */
    unsigned unknown78 : 12; /* +0x78 */
    unsigned unknown78b : 20;
};

unsigned FUN_012fcd90(const Descriptor0149acd0 *descriptor);
void FUN_012fcb30(Descriptor0149acd0 *descriptor, unsigned value);

void FUN_0149acd0(Object0149acd0 *self) /* derived name */
{
    Source0149acd0 *source = self->source;
    if (self->seen == source->buffer)
        return;
    if (self->kind == 1) {
        const unsigned first = source->unknown60;
        const unsigned second = source->unknown64;
        self->unknown74 = first;
        self->unknown78 = second;
    } else {
        FUN_012fcb30(reinterpret_cast<Descriptor0149acd0 *>(self->unknown54),
                     FUN_012fcd90(reinterpret_cast<Descriptor0149acd0 *>(source->unknown70)));
    }
    self->seen = self->source->buffer;
}
