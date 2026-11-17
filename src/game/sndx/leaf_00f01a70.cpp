/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a ring of recent requests, 32 bytes each at +0xa0 of the
 * owner, the number held at +0xa8 and the next slot at +0xaa, its size the
 * int at +0x164 of the runtime's settings (the pointer at 0x5a8e0e0): a
 * request equal to the last one held (its three words) counts once more in
 * that entry's first byte; otherwise, while the ring is not full, it is
 * stored in the next slot with a count of one (callers 0xef6d53, 0xf0154c,
 * 0xf017ab). */
struct Settings05a8e0e0 { /* derived name */
    u8 unknown0[0x164];
    u32 ringSize; /* +0x164 */
};

extern Settings05a8e0e0 *D_5a8e0e0;

struct Request00f01a70 { /* derived name */
    u8 repeats;
    void *unknown8;
    void *unknown10;
    void *unknown18;
};

struct Owner00f01a70 { /* derived name */
    u8 unknown0[0xa0];
    Request00f01a70 *ring; /* +0xa0 */
    u8 count;              /* +0xa8 */
    u8 unknownA9;
    u8 next; /* +0xaa */

    Request00f01a70 *last()
    {
        if (count == 0)
            return 0;
        return &ring[(next + D_5a8e0e0->ringSize - 1) % D_5a8e0e0->ringSize];
    }
};

void FUN_00f01a70(Owner00f01a70 *owner, void *a, void *b, void *c) /* derived name */
{
    const u8 count = owner->count;
    Request00f01a70 *last = owner->last();
    if (last && last->unknown8 == a && last->unknown10 == b && last->unknown18 == c) {
        ++last->repeats;
        return;
    }
    const u32 size = D_5a8e0e0->ringSize;
    if (size > count) {
        const u8 next = owner->next;
        Request00f01a70 *request = &owner->ring[next];
        request->repeats = 1;
        request->unknown8 = a;
        request->unknown10 = b;
        request->unknown18 = c;
        owner->next = (next + 1) % size;
        owner->count = count + 1;
    }
}
