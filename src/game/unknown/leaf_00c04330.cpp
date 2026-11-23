/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_device_thunk.h"
#include "tlg_math.h"

/* derived names: the 0x78-byte value the nodes FUN_00c04330 is given keep in
 * each list: an int, six 16-byte rows and an eight-byte field. */
struct Value00c04330 { /* derived name */
    int unknown0;
    Float4A unknown10[6]; /* +0x10 */
    void *unknown70;      /* +0x70 */
};

/* derived names: a handler of the table FUN_005269a0 builds on its stack
 * (and FUN_00aec5d0's): a node found in both of the 'XAIT' owner's lists has
 * its state byte and its value copied from the first list to the second,
 * then its nodes at +0x28 and +0x30 dispatched. Returns 0. Handler unknown. */
// NONMATCHING: 132/180 in the module: the value's copy: the base copies the int at
// +0x0 alone, then +0x10 to +0x78 as one 0x68-byte block (`mov eax, [r9]`, then +0x70 and three
// 32-byte moves), which a copy assignment written by hand gives (the int's, then the rest's);
// as a trivially copied value it is one 0x78-byte copy. Where the hand-written assignment is
// (the value's own, or a base class holding the int) is not traced: no second site shows one.
// Also the second list's search from the index it was left at reuses the index's register in
// the base (`mov edi, edi`), a new one in the build
int FUN_00c04330(FrameOwner583950 *self, Node583950 *node) /* derived name */
{
    Value00c04330 *from =
        self->cursor.select(node) ? reinterpret_cast<Value00c04330 *>(self->cursor.value()) : 0;
    Value00c04330 *to = self->cursor190.select(node)
                            ? reinterpret_cast<Value00c04330 *>(self->cursor190.value())
                            : 0;
    if (from && to) {
        const u8 *state = self->selectState(node);
        *self->cursor190.selectState(node) = state ? *state : 0;
        *to = *from;
        self->dispatch(node->child);
        self->dispatch(node->child30);
    }
    return 0;
}
