/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_memory.h"

/* derived names: the runtime's table of callbacks at D_5a8e010 emptied: each
 * entry's function (at +0x10 of its record at +0x18; none for a null one)
 * called with the entry's two pointers and its int, the table read again
 * after each call, then the table's 0x60 bytes cleared and the pointer to it
 * made null; 0 is returned. */
struct Callback00edbf60 { /* derived name */
    u8 unknown0[0x10];
    void (*function)(void *, void *, int); /* +0x10 */
};

struct Entry00edbf60 { /* derived name */
    void *unknown0;
    void *unknown8;
    int unknown10;
    u8 unknown14[0x4];
    Callback00edbf60 *callback; /* +0x18 */
    u8 unknown20[0x20];
};

struct Table00edbf60 { /* derived name */
    u8 unknown0[0x8];
    Entry00edbf60 *entries; /* +0x8 */
    unsigned count;         /* +0x10 */
    u8 unknown14[0x4c];
};

extern Table00edbf60 *D_5a8e010; /* derived name */

int FUN_00edbf60() /* derived name */
{
    if (D_5a8e010) {
        for (unsigned i = 0; i < D_5a8e010->count; ++i) {
            Entry00edbf60 &entry = D_5a8e010->entries[i];
            if (entry.callback->function)
                entry.callback->function(entry.unknown0, entry.unknown8, entry.unknown10);
        }
        clearMemory(D_5a8e010, sizeof(Table00edbf60));
        D_5a8e010 = 0;
    }
    return 0;
}
