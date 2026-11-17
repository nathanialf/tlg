/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a sound runtime node handed a flag and a value down its
 * tree: the flag is forced on when either int at +0x248 or +0xdc is set or
 * the byte at +0x2ad is; the node's callback (+0x58 of the record at +0x90)
 * is called with them when it has one (the flag kept in a byte and passed
 * as a bool), then each child of the list at +0x10
 * of the object at +0x48 in turn, the next child (+0x10 of the child's link
 * at +0x18) read before the child is visited. The classes are not traced. */
struct Node00ede520; /* derived name */

struct Link00ede520 { /* derived name */
    u8 unknown0[0x10];
    Node00ede520 *next;
};

struct List00ede520 { /* derived name */
    u8 unknown0[0x10];
    Node00ede520 *first;
};

struct Methods00ede520 { /* derived name */
    u8 unknown0[0x58];
    void (*unknown58)(Node00ede520 *node, bool flag, float value);
};

struct Node00ede520 { /* derived name */
    u8 unknown0[0x18];
    Link00ede520 *link; /* +0x18 */
    u8 unknown20[0x48 - 0x20];
    List00ede520 *children; /* +0x48 */
    u8 unknown50[0x90 - 0x50];
    Methods00ede520 *methods; /* +0x90 */
    u8 unknown98[0xdc - 0x98];
    int unknownDC;
    u8 unknownE0[0x248 - 0xe0];
    int unknown248;
    u8 unknown24C[0x2ad - 0x24c];
    u8 unknown2AD;
};

void FUN_00ede520(Node00ede520 *node, bool flag, float value) /* derived name */
{
    u8 forced = flag;
    if ((node->unknownDC | node->unknown248) != 0) {
        forced = 1;
    }
    if (node->unknown2AD != 0) {
        forced = 1;
    }
    if (node->methods->unknown58 != 0) {
        node->methods->unknown58(node, forced, value);
    }
    Node00ede520 *child = node->children->first;
    while (child != 0) {
        Node00ede520 *next = child->link->next;
        FUN_00ede520(child, forced, value);
        child = next;
    }
}
