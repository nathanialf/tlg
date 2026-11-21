/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_sndx_block05a8e0d8.h"
#include "tlg_sndx_lock.h"
#include "tlg_types.h"

/* derived name: the count of the entries of the block at 0x5a8e0d8, their ids through `ids`
 * (up to `idCount` of them, none when it is null), -3 when the runtime is
 * not running */
int FUN_00efae90(u32 *ids, u32 idCount) /* derived name */
{
    /* volatile: the API lock's slots (tlg_sndx_lock.h) */
    volatile s32 current;
    /* volatile: the API lock's slots (tlg_sndx_lock.h) */
    volatile s32 next;
    int result = -3;
    if (sndxEnter(current, next) == 0) {
        const u32 capacity = D_5a8e0d8->capacity;
        Entry05a8e0d8 **entries =
            static_cast<Entry05a8e0d8 **>(alloca(capacity * sizeof(Entry05a8e0d8 *)));
        sndxReadLock(&D_5a8e0d8->readers);
        u32 count = 0;
        for (Entry05a8e0d8 *entry = D_5a8e0d8->head->entry; entry; entry = entry->next->entry) {
            if (count < capacity)
                entries[count] = entry;
            ++count;
        }
        sndxReadUnlock(&D_5a8e0d8->readers);
        for (u32 i = 0; i < count; ++i) {
            if (ids && i < idCount)
                ids[i] = entries[i]->id;
        }
        if (sndxLeave(current, next) == 0)
            result = count;
    }
    return result;
}
