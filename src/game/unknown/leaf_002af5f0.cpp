/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 9 of the vtables at 0x16a7ea8 and 0x16a7f18 (their
 * pointers at 0x16a7f00 and 0x16a7f70; stored by FUN_002ae3c0 FUN_002aec50
 * and FUN_002b4bf0 FUN_002b5080, no rows), written as a free function: when
 * the node the pointer at 0x57cb848 holds is in the list of the owner at
 * +0x38 (the walk from the list's first node at +0x18 along each node's
 * first field, a null link ending it), passes the object to FUN_002c0750 on
 * that owner; then clears bit 7 of the flags byte at +0x24. The nodes' other
 * fields and the meaning of the flag are not traced. */
struct Node002af5f0 /* derived name */
{
    Node002af5f0 *next; /* +0x0 */
};

struct Owner002af5f0 /* derived name */
{
    u8 unknown0[0x18];
    Node002af5f0 *first; /* +0x18 */

    bool contains(const Node002af5f0 *node) const /* derived name */
    {
        const Node002af5f0 *n = first;
        while (n != node) {
            n = n->next;
            if (!n)
                return false;
        }
        return true;
    }
};

struct Object002af5f0 /* derived name */
{
    u8 unknown0[0x24];
    u8 unknown24; /* +0x24: flags */
    u8 unknown25[0x13];
    Owner002af5f0 *unknown38; /* +0x38 */
};

extern Node002af5f0 *D_57cb848;

void FUN_002c0750(Owner002af5f0 *self, Object002af5f0 *object); /* derived name */

// NONMATCHING: block placement, the base duplicates the walk's compare with the
// node (`cmp; je`) into the entry and the loop's bottom; the build keeps it as
// the loop's header (the held placement tail-duplication question).
void FUN_002af5f0(Object002af5f0 *self) /* derived name */
{
    if (self->unknown38->contains(D_57cb848))
        FUN_002c0750(self->unknown38, self);
    self->unknown24 &= 0x7f;
}
