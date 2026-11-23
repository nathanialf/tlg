/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_array.h"

/* derived names: a node of a tree that owns its children: FUN_013aa2e0 is
 * its destructor, each child deleted first (the destructor itself, then
 * operator delete), the children indexed signed and the count read again
 * after each deletion (`movsxd rcx, ebx` from an unsigned counter: at(int);
 * `mov eax, [r14+0x40]`), then
 * the blocks of the two arrays released, the children's at +0x38 first.
 * Called by FUN_00c6a6f0. What the array at +0x20 holds and what the node
 * keeps before it are not traced. */
struct Node013aa2e0 { /* derived name */
    ~Node013aa2e0();

    u8 unknown0[0x20];                      /* not traced */
    Array05943280<u32> unknown20;           /* +0x20: the elements are not traced */
    Array05943280<Node013aa2e0 *> children; /* +0x38 */
};

Node013aa2e0::~Node013aa2e0()
{
    for (unsigned i = 0; i < children.size(); ++i)
        delete children.at(i);
}
