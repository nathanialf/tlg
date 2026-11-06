/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpDeformableFixedConstraintData's finish constructor (0x7a830): the
 * constraint data finishes itself, the atoms need nothing, and the vtable is
 * set. */
hkpDeformableFixedConstraintData::hkpDeformableFixedConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
}

/* The type infos' own callbacks, this file's (static): the atoms' finish
 * and cleanup folded by the linker into the shared empty body 0x3b640; the
 * data's finish, the constructor above inlined, folded into the
 * constructor itself (0x7a830), its cleanup into 0x2d0. */
static void finishLoadedObjecthkpDeformableFixedConstraintDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpDeformableFixedConstraintData::Atoms(flag);
}

static void cleanupLoadedObjecthkpDeformableFixedConstraintDataAtoms(void *object)
{
    static_cast<hkpDeformableFixedConstraintData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpDeformableFixedConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpDeformableFixedConstraintData(flag);
}

static void cleanupLoadedObjecthkpDeformableFixedConstraintData(void *object)
{
    static_cast<hkpDeformableFixedConstraintData *>(object)->~hkpDeformableFixedConstraintData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkpDeformableFixedConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpDeformableFixedConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpDeformableFixedConstraintData(flag);
    return object.vtable;
}

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
extern const hkClass D_57c5270; /* the transforms atom's */
extern const hkClass D_57c4c70; /* the deformable linear atom's */
extern const hkClass D_57c4bf0; /* the deformable angular atom's */
extern const hkClass D_57c3468;
static const hkClassMember D_169be00[3] = {
#include "gen/D_169be00.inc"
};
static const hkClassMember D_169be80[1] = {
#include "gen/D_169be80.inc"
};

/* This file's static initializer (0x7a870): the atoms' reflection (no
 * parent, three members) and type info (no vtable), then
 * hkpDeformableFixedConstraintData's over hkpConstraintData's (one member)
 * and type info. */
const hkClass D_57c3468("hkpDeformableFixedConstraintDataAtoms", 0,
                        sizeof(hkpDeformableFixedConstraintData::Atoms), 0, 0, 0, 0, D_169be00, 3,
                        0, 0, 0, 0);
extern const hkTypeInfo D_57c34b8;
const hkTypeInfo D_57c34b8("hkpDeformableFixedConstraintDataAtoms",
                           "!hkpDeformableFixedConstraintData::Atoms",
                           finishLoadedObjecthkpDeformableFixedConstraintDataAtoms,
                           cleanupLoadedObjecthkpDeformableFixedConstraintDataAtoms, 0,
                           sizeof(hkpDeformableFixedConstraintData::Atoms));
const hkClass D_57c34e8("hkpDeformableFixedConstraintData", &D_57c45a8,
                        sizeof(hkpDeformableFixedConstraintData), 0, 0, 0, 0, D_169be80, 1, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57c3538;
const hkTypeInfo D_57c3538("hkpDeformableFixedConstraintData", "!hkpDeformableFixedConstraintData",
                           finishLoadedObjecthkpDeformableFixedConstraintData,
                           cleanupLoadedObjecthkpDeformableFixedConstraintData,
                           vtableOfhkpDeformableFixedConstraintData(),
                           sizeof(hkpDeformableFixedConstraintData));
