/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_math.h"
#include "tlg_types.h"

/* derived names: an entry of the source's array (+0x250), 0x40 bytes, two
 * vectors at +0x10 and +0x20 */
struct Element00fda8d0 { /* derived name */
    u8 unknown0[0x10];
    Float4A unknown10; /* +0x10 */
    Float4A unknown20; /* +0x20 */
    u8 unknown30[0x10];
};

struct Holder00fda8d0 { /* derived name */
    u8 unknown0[0x250];
    Element00fda8d0 *elements; /* +0x250 */
};

struct Source00fda8d0 { /* derived name */
    u8 unknown0[0x40];
    Holder00fda8d0 *holder; /* +0x40 */
};

/* derived names: an entry of a channel's array, two vectors */
struct Pair00fda8d0 {  /* derived name */
    Float4A unknown0;  /* +0x0 */
    Float4A unknown10; /* +0x10 */
};

/* derived names: a channel, 0x18 bytes, its array first */
struct Channel00fda8d0 { /* derived name */
    Pair00fda8d0 *data;  /* +0x0 */
    u8 unknown8[0x10];
};

struct Object00fda8d0 { /* derived name */

    /* a channel and its source index by a signed index (`movsxd` under the
     * unsigned counter) */
    Channel00fda8d0 &channelAt(int i) const /* derived name */
    {
        return channels[i];
    }

    int sourceIndexAt(int i) const /* derived name */
    {
        return indices[i];
    }

    u8 unknown0[0x8];
    Source00fda8d0 *source; /* +0x8 */
    int *indices;           /* +0x10: an index into the source's array per channel */
    u8 unknown18[0x10];
    Channel00fda8d0 *channels; /* +0x28 */
    u8 unknown30[0x68];
    unsigned channelCount; /* +0x98 */
    u8 unknown9c[0x8];
    int index; /* +0xa4: the entry of every channel's array written */
    u8 unknowna8[0x8c];
    float length; /* +0x134 */
};

static inline float length3(const Float4A &v) /* derived name */
{
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

/* derived names: each channel's entry at the object's index set from the
 * source's entry the channel's index names (the vectors at +0x20 and +0x10
 * into +0x10 and +0); then the length is the sum of the lengths of the
 * first vectors of channels 1 and 2 at that index. Three other units hold
 * a copy of these bytes (0x101e120, 0x1047010, 0x128e090).
 * NONMATCHING: instruction order and register assignment in the loop only
 * (71 instructions both): the base reads the holder, the channel's array,
 * the holder's entries and then the source index; here the source index
 * comes second (the statement order does not move it). Round 558C: the
 * link's IR with the index's load moved after the entries' pointer gives
 * the base, with it between the holder and the entries not; a subscript
 * emits its index first (EmitArraySubscriptExpr), so `elements[k]` reads k
 * ahead of the pointer, and the base reads the pointer twice but k once. */
void FUN_00fda8d0(Object00fda8d0 *self) /* derived name */
{
    const int index = self->index;
    for (unsigned i = 0; i < self->channelCount; ++i) {
        Source00fda8d0 *source = self->source;
        Pair00fda8d0 &entry = self->channelAt(i).data[index];
        const int k = self->sourceIndexAt(i);
        entry.unknown10 = source->holder->elements[k].unknown20;
        entry.unknown0 = source->holder->elements[k].unknown10;
    }
    Channel00fda8d0 *channels = self->channels;
    const int at = self->index;
    self->length = length3(channels[1].data[at].unknown0);
    self->length += length3(channels[2].data[at].unknown0);
}
