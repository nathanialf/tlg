/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkpBridgeAtoms' type info
 * (0x57c3038): construct the atoms in place from a loaded image through the
 * inline finish constructor, which re-initialises the bridge atom with its
 * own constraint data when finishing. */
static void finishLoadedObjecthkpBridgeAtoms(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpBridgeAtoms(flag);
}

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x3b640. */
static void cleanupLoadedObjecthkpBridgeAtoms(void *object) /* derived name */
{
    static_cast<hkpBridgeAtoms *>(object)->~hkpBridgeAtoms();
}

static void finishLoadedObjecthkpBridgeConstraintAtom(void *object,
                                                      int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpBridgeConstraintAtom(flag);
}

static void cleanupLoadedObjecthkpBridgeConstraintAtom(void *object) /* derived name */
{
    static_cast<hkpBridgeConstraintAtom *>(object)->~hkpBridgeConstraintAtom();
}

extern const hkClassMember D_169b780[]; /* derived name: hkpBridgeAtoms' record */
extern const hkClassMember D_169b7b0[]; /* derived name: the bridge atom's records */

/* This file's static initializer (0x78660): hkpBridgeAtoms' reflection (no
 * parent, its one member) and type info, then hkpBridgeConstraintAtom's
 * over hkpConstraintAtom's (its three members), neither with a vtable. The
 * type infos' names are the base's strings. */
const hkClass D_57c2fe8("hkpBridgeAtoms", 0, sizeof(hkpBridgeAtoms), 0, 0, 0, 0, D_169b780, 1, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57c3038;
const hkTypeInfo D_57c3038("hkpBridgeAtoms", "!hkpBridgeAtoms", finishLoadedObjecthkpBridgeAtoms,
                           cleanupLoadedObjecthkpBridgeAtoms, 0, sizeof(hkpBridgeAtoms));
const hkClass D_57c3068("hkpBridgeConstraintAtom", &D_57c4650, sizeof(hkpBridgeConstraintAtom), 0,
                        0, 0, 0, D_169b7b0, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57c30b8;
const hkTypeInfo D_57c30b8("hkpBridgeConstraintAtom", "!hkpBridgeConstraintAtom",
                           finishLoadedObjecthkpBridgeConstraintAtom,
                           cleanupLoadedObjecthkpBridgeConstraintAtom, 0,
                           sizeof(hkpBridgeConstraintAtom));
