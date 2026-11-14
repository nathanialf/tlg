/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: brings an object's copy of its source's surface up to
 * date when the source's buffer (+0x160) is not the one seen last: kinds 1
 * and 11 copy the word at +0x60 and the low twelve bits of the one at
 * +0x64; any other kind sets the object's descriptor at +0x58 from the
 * value FUN_012fcd90 reads out of the source's descriptor at +0x70. The
 * descriptor and both classes are not traced. */
struct Descriptor0149a270; /* derived name */

struct Source0149a270 { /* derived name */
    u8 unknown0[0x60];
    unsigned unknown60;      /* +0x60 */
    unsigned unknown64 : 12; /* +0x64 */
    unsigned unknown64b : 20;
    u8 unknown68[8];
    u8 unknown70[0xf0]; /* +0x70: a descriptor */
    void *buffer;       /* +0x160 */
};

struct Object0149a270 { /* derived name */
    u8 unknown0[0x30];
    Source0149a270 *source; /* +0x30 */
    void *seen;             /* +0x38: the source's buffer when last brought up to date */
    u8 unknown40[4];
    int kind; /* +0x44 */
    u8 unknown48[0x10];
    u8 unknown58[0x20];      /* +0x58: a descriptor */
    unsigned unknown78;      /* +0x78 */
    unsigned unknown7c : 12; /* +0x7c */
    unsigned unknown7cb : 20;
};

unsigned FUN_012fcd90(const Descriptor0149a270 *descriptor);
void FUN_012fcb30(Descriptor0149a270 *descriptor, unsigned value);

void FUN_0149a270(Object0149a270 *self) /* derived name */
{
    Source0149a270 *source = self->source;
    if (self->seen == source->buffer)
        return;
    if (self->kind == 1 || self->kind == 11) {
        const unsigned first = source->unknown60;
        const unsigned second = source->unknown64;
        self->unknown78 = first;
        self->unknown7c = second;
    } else {
        FUN_012fcb30(reinterpret_cast<Descriptor0149a270 *>(self->unknown58),
                     FUN_012fcd90(reinterpret_cast<Descriptor0149a270 *>(source->unknown70)));
    }
    self->seen = self->source->buffer;
}
