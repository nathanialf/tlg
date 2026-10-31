/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The min-max levels' loaded-object callbacks: nothing to finish (the
 * empty body 0x3b640) and the level destroyed in place, its data freed
 * (the body 0x9cc0 hkBitField's cleanup shares: an hkArray<hkUint32>
 * first). Each folded callback of this file is spelled under the address's
 * own name (D15's addenda); the tree's finish callback, folded onto the
 * same empty body, under that name with its class appended (D15's round
 * 68A addendum). */
void FUN_0003b640(void *object, int finishing) {}

void FUN_00009cc0(void *object)
{
    static_cast<hknpMinMaxQuadTree::MinMaxLevel *>(object)->~MinMaxLevel();
}

void FUN_0003b640_hknpMinMaxQuadTree(void *object, int finishing) {}

void FUN_00040dd0(void *object); /* func_00040dd0.cpp */

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
                           FUN_0003b640, FUN_00009cc0, 0, sizeof(hknpMinMaxQuadTree::MinMaxLevel));
const hkClass D_57c1000("hknpMinMaxQuadTree", 0, sizeof(hknpMinMaxQuadTree), 0, 0, 0, 0, D_1697800,
                        4, 0, 0, 0, 0);
extern const hkTypeInfo D_57c1050;
const hkTypeInfo D_57c1050("hknpMinMaxQuadTree", "!hknpMinMaxQuadTree",
                           FUN_0003b640_hknpMinMaxQuadTree, FUN_00040dd0, 0,
                           sizeof(hknpMinMaxQuadTree));
