/* src/game/sndx/: functions inside the sndx sound runtime (0xec18b0 to 0xf15220; its assert strings name sndx_buss_fx.c, sndx_player_sequence.c and sndx_audioout_orbis.c), built without -ffast-math (config/flags.base.txt); matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a node of the runtime's tree: its state bits at +0xe4 (bit
 * 1 or 2 one of two exclusive states, the others one bit per state), its
 * flags at +0xb8 (bit 0: state 3 is not taken, bit 1: state 3 stops at it)
 * and the list of its children (the link at +0x48 holds the first, each
 * child's link at +0x18 the next one). The other fields are not traced. */
struct SndxNode00edd740;

struct SndxLink00edd740 { /* derived name */
    u8 unknown0[0x10];
    SndxNode00edd740 *next; /* +0x10 */
};

struct SndxNode00edd740 { /* derived name */
    u8 unknown0[0x18];
    SndxLink00edd740 *sibling; /* +0x18 */
    u8 unknown20[0x28];
    SndxLink00edd740 *children; /* +0x48 */
    u8 unknown50[0x68];
    u32 flags; /* +0xb8 */
    u8 unknownbc[0x28];
    u8 states; /* +0xe4 */
};

/* derived name: sets a state on a node and on its tree, the children after
 * the node (called from FUN_00ede020 and FUN_00ee5950); the third argument
 * is handed down unread. Returns 0. */
// NONMATCHING: the chain on the state: the base keeps it a chain in source order (state 3's
// own arm with the shift unfolded, `shl edx, cl`, then 2, then 1, the byte read once above them);
// the build makes a switch of 1 and 2 (lowered 1 first) and joins state 3 to the default arm
// (the switch formation of round 388D's notes; with state 3 its own arm all four become one switch)
int FUN_00edd740(SndxNode00edd740 *node, const int *state, int unknown)
{
    const int s = *state;
    if (s == 3 && (node->flags & 1))
        return 0;
    if (s == 2)
        node->states = (node->states & ~6) | 4;
    else if (s == 1)
        node->states = (node->states & ~6) | 2;
    else
        node->states |= 1 << s;
    if (s == 3 && (node->flags & 2))
        return 0;
    for (SndxNode00edd740 *child = node->children->next; child; child = child->sibling->next)
        FUN_00edd740(child, state, unknown);
    return 0;
}
