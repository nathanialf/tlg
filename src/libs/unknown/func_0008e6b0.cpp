/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The two classes' finish callbacks (func_0008e530.cpp, func_0008e5c0.cpp).
 * derived names. */
void FUN_0008e530(void *object, int finishing);
void FUN_0008e5c0(void *object, int finishing);

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
                           "!hkRootLevelContainer::NamedVariant", FUN_0008e530,
                           hkRootLevelContainer::NamedVariant::FUN_0008e540, 0,
                           sizeof(hkRootLevelContainer::NamedVariant));
const hkClass D_57c8430("hkRootLevelContainer", 0, sizeof(hkRootLevelContainer), 0, 0, 0, 0,
                        D_16a2fe0, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c8480;
const hkTypeInfo D_57c8480("hkRootLevelContainer", "!hkRootLevelContainer", FUN_0008e5c0,
                           hkRootLevelContainer::FUN_0008e5d0, 0, sizeof(hkRootLevelContainer));
