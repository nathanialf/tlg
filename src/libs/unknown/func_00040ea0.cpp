/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x3b640. */
static void finishLoadedObjecthknpMinMaxQuadTreeMinMaxLevel(void *object,
                                                            int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpMinMaxQuadTree::MinMaxLevel(flag);
}

static void cleanupLoadedObjecthknpMinMaxQuadTreeMinMaxLevel(void *object) /* derived name */
{
    static_cast<hknpMinMaxQuadTree::MinMaxLevel *>(object)->~MinMaxLevel();
}

static void finishLoadedObjecthknpMinMaxQuadTree(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpMinMaxQuadTree(flag);
}

/* derived name: the cleanup callback of hknpMinMaxQuadTree's type info
 * (registered by its file's initializer 0x40ea0): the tree destroyed in
 * place, each level's data freed from the last, then the levels'. */
static void cleanupLoadedObjecthknpMinMaxQuadTree(void *object) /* derived name */
{
    static_cast<hknpMinMaxQuadTree *>(object)->~hknpMinMaxQuadTree();
}

extern const hkClassMember D_1697780[]; /* derived name: MinMaxLevel's records */
extern const hkClassMember D_1697800[]; /* derived name: hknpMinMaxQuadTree's records */

/* This file's static initializer (0x40ea0): hknpMinMaxQuadTree::MinMaxLevel's
 * reflection (no parent, its three members) and type info, then
 * hknpMinMaxQuadTree's (its four members), neither with a vtable. The type
 * infos' names are the base's strings. */
const hkClass D_57c0f80("hknpMinMaxQuadTreeMinMaxLevel", 0, sizeof(hknpMinMaxQuadTree::MinMaxLevel),
                        0, 0, 0, 0, D_1697780, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57c0fd0;
const hkTypeInfo D_57c0fd0("hknpMinMaxQuadTreeMinMaxLevel", "!hknpMinMaxQuadTree::MinMaxLevel",
                           finishLoadedObjecthknpMinMaxQuadTreeMinMaxLevel,
                           cleanupLoadedObjecthknpMinMaxQuadTreeMinMaxLevel, 0,
                           sizeof(hknpMinMaxQuadTree::MinMaxLevel));
const hkClass D_57c1000("hknpMinMaxQuadTree", 0, sizeof(hknpMinMaxQuadTree), 0, 0, 0, 0, D_1697800,
                        4, 0, 0, 0, 0);
extern const hkTypeInfo D_57c1050;
const hkTypeInfo D_57c1050("hknpMinMaxQuadTree", "!hknpMinMaxQuadTree",
                           finishLoadedObjecthknpMinMaxQuadTree,
                           cleanupLoadedObjecthknpMinMaxQuadTree, 0, sizeof(hknpMinMaxQuadTree));
