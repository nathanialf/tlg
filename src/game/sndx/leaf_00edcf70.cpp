/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_game_memory.h"

/* derived names: a group of the sound runtime reset with every group under
 * it: its 16 bytes at +0xcc and the int at +0xdc cleared, the byte at +0xe4
 * copied to +0xe5, each child (the first through the link at +0x48, the
 * next through the child's own link at +0x18, each link's +0x10) reset in
 * turn, then the byte at +0x2ad cleared. The structures are not traced
 * further. */
struct Group00edcf70;

struct Link00edcf70 { /* derived name */
    u8 unknown0[0x10];
    Group00edcf70 *next; /* +0x10 */
};

struct Group00edcf70 { /* derived name */
    u8 unknown0[0x18];
    Link00edcf70 *link18; /* +0x18 */
    u8 unknown20[0x28];
    Link00edcf70 *children; /* +0x48 */
    u8 unknown50[0x7c];
    u8 unknowncc[0x10]; /* +0xcc */
    int unknowndc;      /* +0xdc */
    u8 unknowne0[0x4];
    u8 unknowne4; /* +0xe4 */
    u8 unknowne5; /* +0xe5 */
    u8 unknowne6[0x1c7];
    u8 unknown2ad; /* +0x2ad */
};

void FUN_00edcf70(Group00edcf70 *group) /* derived name */
{
    clearMemory(group->unknowncc, sizeof(group->unknowncc));
    group->unknowndc = 0;
    group->unknowne5 = group->unknowne4;
    for (Group00edcf70 *child = group->children->next; child; child = child->link18->next)
        FUN_00edcf70(child);
    group->unknown2ad = 0;
}
