/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_game_array.h"

/* derived names: the node FUN_00c0a9f0 is given: a count at +0x30 and two
 * arrays of floats, one entry for each, at +0x48 and +0x60 */
struct Node00c0a9f0 { /* derived name */
    u8 unknown0[0x30];
    unsigned count; /* +0x30 */
    u8 unknown34[0x14];
    Array05943280<float> values48; /* +0x48 */
    Array05943280<float> values60; /* +0x60 */
};

/* derived names: a handler whose address FUN_00be6da0 takes (lea at
 * 0xbe7528): the node's two arrays are brought to its count, each new
 * entry -1. Where the arrays are longer than the count, both counts are
 * lowered by the difference worked out as count minus length, as the base
 * does (0xc0ab57 to 0xc0ab69: the new length is twice the old less the
 * count). Returns 0. Handler unknown. */
// NONMATCHING: 10/118 in the module (387 bytes against 397), the count
// shifted from the entry on; side by side only the count kept in eax at the
// entry and the shrinking arm differ: the
// base keeps the count in eax and lowers each array's count as its own
// (count + length) - wanted (`mov ecx, [rbx+0x68]; add ecx, r15d; add r15d,
// r15d; sub r15d, eax; sub ecx, eax`), where the build reuses the difference
// the growing loop counts down (`sub r15d, r14d`). The difference written out
// at each use is shared by EarlyCSE as well, and loses the loop's guard.
int FUN_00c0a9f0(DeviceOwner583950 *self, Node00c0a9f0 *node) /* derived name */
{
    const unsigned size = node->values48.size();
    const unsigned added = node->count - size;
    if (node->count > size) {
        for (unsigned i = 0; i < added; ++i) {
            node->values48.push(-1.0f);
            node->values60.push(-1.0f);
        }
    } else if (node->count < size) {
        node->values48.removeLast(added);
        node->values60.removeLast(added);
    }
    return 0;
}
