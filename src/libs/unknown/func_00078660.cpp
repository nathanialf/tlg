/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpBridgeAtoms' finish callback (func_00078610.cpp). derived name. */
void FUN_00078610(void *object, int finishing);

/* Both classes' cleanup callbacks have nothing to clean up (the linker
 * folded them into the empty body 0x3b640); the bridge atom's finish
 * callback, the atoms' own body, was folded onto 0x78610. The first
 * registration's are spelled under the addresses' names (D15's round 57
 * addendum), the second's with its class appended (D15's round 68A
 * addendum). */
void FUN_0003b640(void *object) {}

void FUN_00078610_hkpBridgeConstraintAtom(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpBridgeConstraintAtom(flag);
}

void FUN_0003b640_hkpBridgeConstraintAtom(void *object) {}

extern const hkClassMember D_169b780[]; /* derived name: hkpBridgeAtoms' record */
extern const hkClassMember D_169b7b0[]; /* derived name: the bridge atom's records */

/* This file's static initializer (0x78660): hkpBridgeAtoms' reflection (no
 * parent, its one member) and type info, then hkpBridgeConstraintAtom's
 * over hkpConstraintAtom's (its three members), neither with a vtable. The
 * type infos' names are the base's strings. */
const hkClass D_57c2fe8("hkpBridgeAtoms", 0, sizeof(hkpBridgeAtoms), 0, 0, 0, 0, D_169b780, 1, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57c3038;
const hkTypeInfo D_57c3038("hkpBridgeAtoms", "!hkpBridgeAtoms", FUN_00078610, FUN_0003b640, 0,
                           sizeof(hkpBridgeAtoms));
const hkClass D_57c3068("hkpBridgeConstraintAtom", &D_57c4650, sizeof(hkpBridgeConstraintAtom), 0,
                        0, 0, 0, D_169b7b0, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57c30b8;
const hkTypeInfo D_57c30b8("hkpBridgeConstraintAtom", "!hkpBridgeConstraintAtom",
                           FUN_00078610_hkpBridgeConstraintAtom,
                           FUN_0003b640_hkpBridgeConstraintAtom, 0,
                           sizeof(hkpBridgeConstraintAtom));
