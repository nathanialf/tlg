/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the node's finish and cleanup folded by the linker into the empty
 * body 0x1c1e0, the tree's finish kept at 0x1f360 beside the initializer
 * and its cleanup folded into the shared virtual destructor call 0x2d0. */
static void finishLoadedObjecthkcdSimdTreeNode(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdSimdTree::Node(flag);
}

static void cleanupLoadedObjecthkcdSimdTreeNode(void *object)
{
    static_cast<hkcdSimdTree::Node *>(object)->~Node();
}

static void finishLoadedObjecthkcdSimdTree(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdSimdTree(flag);
}

static void cleanupLoadedObjecthkcdSimdTree(void *object)
{
    static_cast<hkcdSimdTree *>(object)->~hkcdSimdTree();
}

/* The two classes' member records and the node's one enum, file-local
 * (D17); the rows are written at build time from the user's executable
 * (D18, config/data_schema.base.txt). The tree's record cites the node's
 * class, the enum the base's items. */
extern const hkClass D_57ba890; /* hkcdFourAabb's hkClass (0x1e090's file) */
extern const hkClass D_57bb310;
extern const hkClassEnum::Item D_1690210; /* the first of its three items */

static const hkClassEnum D_1690240[1] = {
#include "gen/D_1690240.inc"
};

static const hkClassMember D_16901e0[1] = {
#include "gen/D_16901e0.inc"
};

static const hkClassMember D_1690270[1] = {
#include "gen/D_1690270.inc"
};

/* The address of hkcdSimdTree's vtable, read from an object finished in a
 * buffer (folded to the address point). derived name. */
static const void *vtableOfhkcdSimdTree()
{
    union {
        void *vtable;
        char buffer[sizeof(hkcdSimdTree)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkcdSimdTree(flag);
    return object.vtable;
}

/* This file's static initializer (0x1f380): hkcdSimdTree::Node's
 * reflection over hkcdFourAabb's (its one enum and one member) and type
 * info, then hkcdSimdTree's over hkBaseObject's (one member, version 1)
 * and type info with its vtable. The type infos' names are the base's
 * strings. */
const hkClass D_57bb310("hkcdSimdTreeNode", &D_57ba890, sizeof(hkcdSimdTree::Node), 0, 0, D_1690240,
                        1, D_16901e0, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57bb360;
const hkTypeInfo D_57bb360("hkcdSimdTreeNode", "!hkcdSimdTree::Node",
                           finishLoadedObjecthkcdSimdTreeNode, cleanupLoadedObjecthkcdSimdTreeNode,
                           0, sizeof(hkcdSimdTree::Node));
const hkClass D_57bb390("hkcdSimdTree", &D_57b86c0, sizeof(hkcdSimdTree), 0, 0, 0, 0, D_1690270, 1,
                        0, 0, 0, 1);
extern const hkTypeInfo D_57bb3e0;
const hkTypeInfo D_57bb3e0("hkcdSimdTree", "!hkcdSimdTree", finishLoadedObjecthkcdSimdTree,
                           cleanupLoadedObjecthkcdSimdTree, vtableOfhkcdSimdTree(),
                           sizeof(hkcdSimdTree));
