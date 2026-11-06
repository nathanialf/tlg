/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the finish callback of hkRootLevelContainer::NamedVariant's type info (0x57c8400):
 * construct the object in place from a loaded image through its
 * out-of-line finish constructor. */
static void finishLoadedObjecthkRootLevelContainerNamedVariant(void *object,
                                                               int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkRootLevelContainer::NamedVariant(flag);
}

/* derived names: the finish callback of hkRootLevelContainer's type info (0x57c8480):
 * construct the object in place from a loaded image through its
 * out-of-line finish constructor. */
static void finishLoadedObjecthkRootLevelContainer(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_0017de10(static_cast<hkRootLevelContainer *>(object), flag);
}

/* NamedVariant's cleanup callback (0x8e540): the entry destroyed in
 * place. */
static void cleanupLoadedObjecthkRootLevelContainerNamedVariant(void *object) /* derived name */
{
    static_cast<hkRootLevelContainer::NamedVariant *>(object)->~NamedVariant();
}

/* hkRootLevelContainer's cleanup callback (0x8e5d0): the object
 * destroyed in place, its entries from the last, then their storage. */
static void cleanupLoadedObjecthkRootLevelContainer(void *object) /* derived name */
{
    static_cast<hkRootLevelContainer *>(object)->~hkRootLevelContainer();
}

extern const hkClassMember D_16a2f60[]; /* derived name: NamedVariant's records */
extern const hkClassMember D_16a2fe0[]; /* derived name: hkRootLevelContainer's record */

/* This file's static initializer (0x8e6b0): hkRootLevelContainer::
 * NamedVariant's reflection (no parent, its three members, version 1) and
 * type info, then hkRootLevelContainer's (its one member), each with its
 * finish and cleanup callbacks and no vtable. The type infos' names are
 * the base's strings. */
const hkClass D_57c83b0("hkRootLevelContainerNamedVariant", 0,
                        sizeof(hkRootLevelContainer::NamedVariant), 0, 0, 0, 0, D_16a2f60, 3, 0, 0,
                        0, 1);
extern const hkTypeInfo D_57c8400;
const hkTypeInfo D_57c8400("hkRootLevelContainerNamedVariant",
                           "!hkRootLevelContainer::NamedVariant",
                           finishLoadedObjecthkRootLevelContainerNamedVariant,
                           cleanupLoadedObjecthkRootLevelContainerNamedVariant, 0,
                           sizeof(hkRootLevelContainer::NamedVariant));
const hkClass D_57c8430("hkRootLevelContainer", 0, sizeof(hkRootLevelContainer), 0, 0, 0, 0,
                        D_16a2fe0, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c8480;
const hkTypeInfo D_57c8480("hkRootLevelContainer", "!hkRootLevelContainer",
                           finishLoadedObjecthkRootLevelContainer,
                           cleanupLoadedObjecthkRootLevelContainer, 0,
                           sizeof(hkRootLevelContainer));
