/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the object constructed in place from a loaded image through its
 * inline finish constructor, which hands the bridge atom its data when
 * finishing (the finish callback kept at 0x7f120), and destroyed through its
 * virtual destructor (the body the linker folded, 0x2d0). */
static void finishLoadedObjecthkpPointToPathConstraintData(void *object,
                                                           int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpPointToPathConstraintData(flag);
}

static void cleanupLoadedObjecthkpPointToPathConstraintData(void *object) /* derived name */
{
    static_cast<hkpPointToPathConstraintData *>(object)->~hkpPointToPathConstraintData();
}

/* The address of hkpPointToPathConstraintData's vtable, read from an object
 * finished in a buffer (folded to the address point after hkpConstraintData's
 * finish constructor, 0x7f377). */
static const void *vtableOfhkpPointToPathConstraintData() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkpPointToPathConstraintData)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpPointToPathConstraintData(flag);
    return object.vtable;
}

/* The OrientationConstraintType enum and its five items, file-local; the rows
 * the base's. */
static const hkClassEnum::Item D_169d5e0[5] = {
#include "gen/D_169d5e0.inc"
};

static const hkClassEnum D_169d630[1] = {
#include "gen/D_169d630.inc"
};

/* This file's static initializer (0x7f170): hkpPointToPathConstraintData's
 * five member records (in .bss, reached through their address: not the
 * file's own), built at run time from the enum's pointer, then its class
 * over hkpConstraintData's and its type info with its vtable. */
hkClassMember D_57c4460[] = {
    {"atoms", &D_57c2fe8, 0, hkClassMember::TYPE_STRUCT, hkClassMember::TYPE_VOID, 0, 0, 0x20, 0},
    {"path", &D_57c3c68, 0, hkClassMember::TYPE_POINTER, hkClassMember::TYPE_STRUCT, 0, 0, 0x40, 0},
    {"maxFrictionForce", 0, 0, hkClassMember::TYPE_REAL, hkClassMember::TYPE_VOID, 0, 0, 0x48, 0},
    {"angularConstrainedDOF", 0, D_16dc668, hkClassMember::TYPE_ENUM, hkClassMember::TYPE_INT8, 0,
     0, 0x4c, 0},
    {"transform_OS_KS", 0, 0, hkClassMember::TYPE_TRANSFORM, hkClassMember::TYPE_VOID, 2, 0, 0x50,
     0}};
const hkClass D_57c4528("hkpPointToPathConstraintData", &D_57c45a8,
                        sizeof(hkpPointToPathConstraintData), 0, 0, D_169d630, 1, D_57c4460, 5, 0,
                        0, 0, 0);
extern const hkTypeInfo D_57c4578;
const hkTypeInfo D_57c4578("hkpPointToPathConstraintData", "!hkpPointToPathConstraintData",
                           finishLoadedObjecthkpPointToPathConstraintData,
                           cleanupLoadedObjecthkpPointToPathConstraintData,
                           vtableOfhkpPointToPathConstraintData(),
                           sizeof(hkpPointToPathConstraintData));
