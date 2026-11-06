/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpPointToPlaneConstraintData's finish constructor (0x7b900): the constraint data
 * finishes itself, the atoms need nothing, and the vtable is set. */
hkpPointToPlaneConstraintData::hkpPointToPlaneConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
}

/* The type infos' own callbacks, this file's (static): the atoms' finish
 * and cleanup folded by the linker into the shared empty body 0x3b640; the
 * data's finish, the constructor above inlined, folded into the
 * constructor itself (0x7b900), its cleanup into 0x2d0. */
static void finishLoadedObjecthkpPointToPlaneConstraintDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpPointToPlaneConstraintData::Atoms(flag);
}

static void cleanupLoadedObjecthkpPointToPlaneConstraintDataAtoms(void *object)
{
    static_cast<hkpPointToPlaneConstraintData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpPointToPlaneConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpPointToPlaneConstraintData(flag);
}

static void cleanupLoadedObjecthkpPointToPlaneConstraintData(void *object)
{
    static_cast<hkpPointToPlaneConstraintData *>(object)->~hkpPointToPlaneConstraintData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkpPointToPlaneConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpPointToPlaneConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpPointToPlaneConstraintData(flag);
    return object.vtable;
}

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
extern const hkClass D_57c4d70;
extern const hkClass D_57c5270;
extern const hkClass D_57c3b68;
static const hkClassMember D_169c4b0[2] = {
#include "gen/D_169c4b0.inc"
};
static const hkClassMember D_169c500[1] = {
#include "gen/D_169c500.inc"
};

/* This file's static initializer (0x7b940): the atoms' reflection (no
 * parent, 2 members) and type info (no vtable), then hkpPointToPlaneConstraintData's over
 * hkpConstraintData's (1 member) and type info. */
const hkClass D_57c3b68("hkpPointToPlaneConstraintDataAtoms", 0,
                        sizeof(hkpPointToPlaneConstraintData::Atoms), 0, 0, 0, 0, D_169c4b0, 2, 0,
                        0, 0, 0);
extern const hkTypeInfo D_57c3bb8;
const hkTypeInfo D_57c3bb8("hkpPointToPlaneConstraintDataAtoms",
                           "!hkpPointToPlaneConstraintData::Atoms",
                           finishLoadedObjecthkpPointToPlaneConstraintDataAtoms,
                           cleanupLoadedObjecthkpPointToPlaneConstraintDataAtoms, 0,
                           sizeof(hkpPointToPlaneConstraintData::Atoms));
const hkClass D_57c3be8("hkpPointToPlaneConstraintData", &D_57c45a8,
                        sizeof(hkpPointToPlaneConstraintData), 0, 0, 0, 0, D_169c500, 1, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57c3c38;
const hkTypeInfo D_57c3c38("hkpPointToPlaneConstraintData", "!hkpPointToPlaneConstraintData",
                           finishLoadedObjecthkpPointToPlaneConstraintData,
                           cleanupLoadedObjecthkpPointToPlaneConstraintData,
                           vtableOfhkpPointToPlaneConstraintData(),
                           sizeof(hkpPointToPlaneConstraintData));
