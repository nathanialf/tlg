/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 109 of the vtable of Object00f0e560 (0x16bedb8,
 * config/vtables.derived.base.txt; its pointer at 0x16bf130), written as a
 * free function: in each of the 96-byte records from +0x10, as many as the
 * unsigned int at +0xd0 counts, sets the int at +0x0 to 1 and the one at
 * +0x50 to 0. */
struct Entry013d2860 /* derived name */
{
    int unknown0; /* +0x0 */
    u8 unknown4[0x4c];
    int unknown50; /* +0x50 */
    u8 unknown54[0xc];
};

/* an array of a fixed capacity: raw storage for its elements, then how many
 * are in use; the end is formed from the size in bytes (the base tests the
 * product, `shl rax, 5; lea rax, [rax + rax*2]; test rax, rax`, not the
 * count). The capacity of two is the room between +0x10 and the count. */
template <typename T, int N>
struct FixedArray013d2860 /* derived name */
{
    T *begin()
    {
        return reinterpret_cast<T *>(storage);
    }

    T *end()
    {
        return reinterpret_cast<T *>(storage + count * sizeof(T));
    }

    u8 storage[N * sizeof(T)]; /* +0x0 */
    unsigned count;            /* +N * sizeof(T) */
};

struct Object013d2860 /* derived name */
{
    u8 unknown0[0x10];
    FixedArray013d2860<Entry013d2860, 2> unknown10; /* +0x10, its count at +0xd0 */
};

void FUN_013d2860(Object013d2860 *self) /* derived name */
{
    for (Entry013d2860 *entry = self->unknown10.begin(), *end = self->unknown10.end(); entry != end;
         ++entry) {
        entry->unknown0 = 1;
        entry->unknown50 = 0;
    }
}
