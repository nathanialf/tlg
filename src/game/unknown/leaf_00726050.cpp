/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_fieldtable.h"
#include "tlg_game_object016b85e0.h"

/* the field's value in `word`, the field passed by value (the pair read as
 * one quadword: `mov rcx, [D_57ca4e8]`, the shift from cl, the width from
 * `shr rcx, 0x20`) */
static inline unsigned bitFieldOf(unsigned word, BitField0057ca430 field) /* derived name */
{
    return (word >> field.shift) & ((1u << field.width) - 1);
}

struct Object00726050 { /* derived name */
    u8 unknown0[0x28];
    Object016b85e0 *node; /* +0x28 */
};

/* derived names: whether the field of the table's record 4 (0x57ca4e8) is
 * set in the word `index` of the node's component of the type at 0x57ca3d0;
 * true when the node has no such component */
// NONMATCHING: 50/68, 209 against 204 bytes: the mode's test `cmp edx, 1; ja` where the base has
// `cmp edx, 2; jae` (the same test inverted), and the width taken from a copy (`mov rax, rcx; shr rax,
// 0x20; mov cl, al`) where the base shifts rcx itself (round 588D)
int FUN_00726050(Object00726050 *self, unsigned index) /* derived name */
{
    if (Component00503fb0 *found = self->node->component(D_57ca3d0)) {
        unsigned *words = reinterpret_cast<Fields0057ca430 *>(found)->held->words();
        if (!bitFieldOf(words[index], D_57ca430[4].field))
            return 0;
    }
    return 1;
}
