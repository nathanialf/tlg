/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a sound runtime callback that, unless its flag is set,
 * finds the node of the list at +0x10 of the object at +0x4d0 whose id at
 * +0xa0 is the key's id (+0xa8), the next node at +0x10 of the link at +0x8,
 * and copies the parameters of the record given into it; it returns 1. The
 * second parameter is not read. The classes are not traced. */
struct Node00eead50; /* derived name */

struct Link00eead50 { /* derived name */
    u8 unknown0[0x10];
    Node00eead50 *next;
};

struct Node00eead50 { /* derived name */
    u8 unknown0[0x8];
    Link00eead50 *link;
    u8 unknown10[0xa0 - 0x10];
    int id; /* +0xa0 */
    int unknownA4;
    int unknownA8;
    int unknownAC;
    int unknownB0;
    int unknownB4;
    int unknownB8;
    u8 unknownBC[0xcc - 0xbc];
    int unknownCC;
    u8 unknownD0[0xf0 - 0xd0];
    u64 unknownF0;
    u64 unknownF8;
};

struct List00eead50 { /* derived name */
    u8 unknown0[0x10];
    Node00eead50 *first;
};

struct Player00eead50 { /* derived name */
    u8 unknown0[0x4d0];
    List00eead50 *unknown4d0;
};

struct Key00eead50 { /* derived name */
    u8 unknown0[0xa8];
    int id;
};

struct Parameters00eead50 { /* derived name */
    u64 unknown0;
    u8 unknown8[0x4];
    int unknownC;
    u8 unknown10[0x4];
    int unknown14;
    int unknown18;
    int unknown1C;
    int unknown20;
    int unknown24;
    u64 unknown28;
};

int FUN_00eead50(Player00eead50 *player, int, const Key00eead50 *key, int skip,
                 const Parameters00eead50 *parameters) /* derived name */
{
    if (skip == 0) {
        Node00eead50 *node = player->unknown4d0->first;
        while (node != 0 && node->id != key->id) {
            node = node->link->next;
        }
        if (node != 0) {
            node->unknownA4 = parameters->unknownC;
            node->unknownA8 = node->unknownAC = parameters->unknown18;
            node->unknownB8 = parameters->unknown14;
            node->unknownB0 = parameters->unknown1C;
            node->unknownB4 = parameters->unknown20;
            node->unknownCC = parameters->unknown24;
            node->unknownF0 = parameters->unknown28;
            node->unknownF8 = parameters->unknown0;
        }
    }
    return 1;
}
