/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: sets up a node of an intrusive list whose head is the
 * pointer at 0x5945880 (FUN_00cb57e0 and FUN_00cb58b0 walk it):
 * clears the link pair at +0x0, stores its three arguments at +0x10, +0x18 and
 * +0x20, and pushes the node at the head (the old head's back link pointed at
 * the node's next field, the node's at the head). Called by FUN_002030d0,
 * FUN_00b98590, FUN_00ea2c50 and others. The arguments' types are not traced. */
struct Node00cb5760 {     /* derived name */
    Node00cb5760 *next;   /* derived name */
    Node00cb5760 **pprev; /* derived name */
    void *unknown10;      /* +0x10 */
    void *unknown18;      /* +0x18 */
    int unknown20;        /* +0x20 */
};

extern Node00cb5760 *D_5945880;

// NONMATCHING: alias analysis: the base reloads the head after the old head's back link is
// stored (`mov [rcx + 8], rdi; mov rax, [head]`, the null path's 0 a PRE'd `xor eax, eax`);
// 4.0.0 and the prebuilt 3.9.1 forward the first load (the store through an inbounds
// field 1 of the loaded node is no alias of the 8-byte head), the prebuilt 3.8.1 reloads.
void FUN_00cb5760(Node00cb5760 *node, void *first, void *second, int third) /* derived name */
{
    node->next = 0;
    node->pprev = 0;
    node->unknown10 = first;
    node->unknown18 = second;
    node->unknown20 = third;
    if (D_5945880)
        D_5945880->pprev = &node->next;
    node->next = D_5945880;
    node->pprev = &D_5945880;
    D_5945880 = node;
}
