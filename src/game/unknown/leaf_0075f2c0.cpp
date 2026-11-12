/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_sce_kernel.h"

/* derived names: finds the node whose id (+0x210, 0 for none) is the key's
 * first int in a tree of nodes: the node itself, else each child (+0x40, the
 * count at +0x48) searched in turn, the children read under the reader count
 * at +0x23c of the record at +0x108 of the global at 0x5938c40 (as
 * leaf_0048fd50.cpp's: skipped when the record's owner at +0x248 is the
 * calling thread); null when none has it. */
struct Node0075f2c0 { /* derived name */
    u8 unknown0[0x40];
    Node0075f2c0 **children; /* +0x40 */
    u32 childCount;          /* +0x48 */
    u8 unknown4c[0x1c4];
    int id; /* +0x210 */
};

struct Lock0075f2c0 { /* derived name */
    u8 unknown0[0x23c];
    int readers; /* +0x23c */
    u8 unknown240[8];
    pthread_t owner; /* +0x248 */
};

struct Object05938c40 { /* derived name */
    u8 unknown0[0x108];
    Lock0075f2c0 *unknown108; /* +0x108 */
};

extern Object05938c40 *D_5938c40;

void FUN_01331c10(int *readers); /* derived name */

Node0075f2c0 *FUN_0075f2c0(Node0075f2c0 *node, const int *key) /* derived name */
{
    if (node->id != 0 && node->id == *key)
        return node;
    Lock0075f2c0 *lock = D_5938c40->unknown108;
    if (scePthreadSelf() != lock->owner)
        FUN_01331c10(&lock->readers);
    Node0075f2c0 *found = 0;
    Node0075f2c0 **end = node->children + node->childCount;
    for (Node0075f2c0 **child = node->children; child != end; ++child) {
        found = FUN_0075f2c0(*child, key);
        if (found)
            break;
    }
    lock = D_5938c40->unknown108;
    if (scePthreadSelf() != lock->owner)
        __sync_fetch_and_sub(&lock->readers, 1);
    return found;
}
