/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_fieldtable.h"
#include "tlg_game_object016b85e0.h"

extern const Type00503fb0 *D_5948180; /* derived name */

struct Object0075e810 { /* derived name */
    u8 unknown0[0x8];
    Object016b9108 *object; /* +0x8: of the type at 0x5948180 */
    Object016b85e0 *node;   /* +0x10 */
    u8 unknown18[0x48];
    int word; /* +0x60: the index of the node's word */
};

/* derived names: the value of the table's field `field` in the node's word
 * (the component of the type at 0x57ca3d0); -1 when the object at +0x8 is
 * not of the type at 0x5948180, there is no node or word, or the node has
 * no such component */
// NONMATCHING: 314 against 312 bytes: the found component in rdx and the count in eax where the base
// has rax and ecx (cookbook 10301's class, here with no cast to move), the word's index sign-extended
// (`movsxd`) where the base uses the 32-bit load as it is, and the mode's test `cmp 1; ja` against
// the base's `cmp 2; jae` (round 588D)
int FUN_0075e810(Object0075e810 *self, unsigned field) /* derived name */
{
    if (!self->object || !self->object->isKindOf(D_5948180))
        return -1;
    Object016b85e0 *node = self->node;
    int word = self->word;
    if (!node || word < 0)
        return -1;
    Component00503fb0 *found = node->component(D_57ca3d0);
    if (!found)
        return -1;
    unsigned *words = reinterpret_cast<Fields0057ca430 *>(found)->held->words();
    const BitField0057ca430 &bits = D_57ca430[field].field;
    return (words[word] >> bits.shift) & ((1u << bits.width) - 1);
}
