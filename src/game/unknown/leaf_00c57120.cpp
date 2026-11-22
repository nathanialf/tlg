/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_game_node.h"
#include "tlg_game_object01388080.h"
#include "tlg_game_object016b85e0.h"

/* derived names: a node taken out of its parent's children. With a parent
 * at +0x38 the node holds a reference to itself for the length of the work
 * (`lock inc dword [r12]` at 0xc57149 with no null test, the drop at
 * 0xc57198), FUN_00c56780 runs over it, the parent's flag 2 at +0x20 is
 * set, FUN_01351240 takes the node's index (+0x218) out of the parent's
 * children and, when it moved another child there, that child's index is
 * set; then the node's parent is cleared and its index made -1. The class
 * is the scene node's (the parent at +0x38, the children at +0x40, the
 * index -1 from its constructor). */

void FUN_00c56780(Object016b85e0 *node);                             /* derived name */
int FUN_01351240(Ref00503fb0<Object016b85e0> **children, int index); /* derived name */

void FUN_00c57120(Object016b85e0 *self) /* derived name */
{
    Object016b85e0 *parent = self->parent;
    if (parent) {
        addReference(self);
        FUN_00c56780(self);
        parent->flags |= 2;
        int index = self->index;
        if (FUN_01351240(&parent->children, index))
            parent->children[index].get()->index = index;
        self->parent = 0;
        self->index = -1;
        dropReference(self);
    }
}

/* derived name: the node taken out of its parent under the world's write
 * lock, held by a WorldWriteLock05938c40 (tlg_game_object01388080.h): the
 * registry's unlock at the end is a call the function returns from (`call
 * 0x14b0568; add rsp, 8; pop rbx; pop rbp; ret` at 0xc572b7), not a jump */
void FUN_00c57220(Object016b85e0 *node) /* derived name */
{
    WorldWriteLock05938c40 lock;
    FUN_00c57120(node);
}

/* derived name: the same for the node's children, the last first (each
 * through this function, so their own children before them), then for the
 * node; the index is signed (`dec eax; js`, then `movsxd`) */
void FUN_00c572d0(Object016b85e0 *self) /* derived name */
{
    for (int i = self->childCount - 1; i >= 0; --i)
        FUN_00c572d0(self->childAt(i));
    WorldWriteLock05938c40 lock;
    FUN_00c57120(self);
}

/* derived name: not traced; the node and an int handed on (`mov esi,
 * r14d`) */
void FUN_00c579f0(Object016b85e0 *self, int value); /* derived name */

/* derived name: FUN_00c579f0 under the world's write lock */
void FUN_00c57940(Object016b85e0 *self, int value) /* derived name */
{
    WorldWriteLock05938c40 lock;
    FUN_00c579f0(self, value);
}
