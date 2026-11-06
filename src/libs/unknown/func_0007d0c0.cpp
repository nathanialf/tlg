/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpRackAndPinionConstraintData's finish constructor (0x7d080): the
 * constraint data finishes itself, the atoms need nothing, and the vtable
 * is set. */
hkpRackAndPinionConstraintData::hkpRackAndPinionConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
}

/* The type infos' own callbacks, this file's (static): the atoms' finish
 * and cleanup folded by the linker into the shared empty body 0x3b640; the
 * data's finish, the constructor above inlined, folded into the
 * constructor itself (0x7d080), its cleanup into 0x2d0. */
static void finishLoadedObjecthkpRackAndPinionConstraintDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpRackAndPinionConstraintData::Atoms(flag);
}

static void cleanupLoadedObjecthkpRackAndPinionConstraintDataAtoms(void *object)
{
    static_cast<hkpRackAndPinionConstraintData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpRackAndPinionConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpRackAndPinionConstraintData(flag);
}

static void cleanupLoadedObjecthkpRackAndPinionConstraintData(void *object)
{
    static_cast<hkpRackAndPinionConstraintData *>(object)->~hkpRackAndPinionConstraintData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkpRackAndPinionConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpRackAndPinionConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpRackAndPinionConstraintData(flag);
    return object.vtable;
}

/* The two classes' member records and the data's type enum with its
 * items, file-local (D17); the rows are written at build time from the
 * user's executable (D18, config/data_schema.base.txt). The atoms' classes
 * they cite are named after the members that hold them (derived names). */
extern const hkClass D_57c5270; /* the transforms atom's */
extern const hkClass D_57c50f0; /* the rack and pinion atom's */
extern const hkClass D_57c4108;
static const hkClassMember D_169cd00[2] = {
#include "gen/D_169cd00.inc"
};
static const hkClassMember D_169cd50[1] = {
#include "gen/D_169cd50.inc"
};
static const hkClassEnum::Item D_169cd80[2] = {
#include "gen/D_169cd80.inc"
};
static const hkClassEnum D_169cda0[1] = {
#include "gen/D_169cda0.inc"
};

/* This file's static initializer (0x7d0c0): the atoms' reflection (no
 * parent, two members) and type info (no vtable), then
 * hkpRackAndPinionConstraintData's over hkpConstraintData's (the type
 * enum, one member) and type info. */
const hkClass D_57c4108("hkpRackAndPinionConstraintDataAtoms", 0,
                        sizeof(hkpRackAndPinionConstraintData::Atoms), 0, 0, 0, 0, D_169cd00, 2, 0,
                        0, 0, 0);
extern const hkTypeInfo D_57c4158;
const hkTypeInfo D_57c4158("hkpRackAndPinionConstraintDataAtoms",
                           "!hkpRackAndPinionConstraintData::Atoms",
                           finishLoadedObjecthkpRackAndPinionConstraintDataAtoms,
                           cleanupLoadedObjecthkpRackAndPinionConstraintDataAtoms, 0,
                           sizeof(hkpRackAndPinionConstraintData::Atoms));
const hkClass D_57c4188("hkpRackAndPinionConstraintData", &D_57c45a8,
                        sizeof(hkpRackAndPinionConstraintData), 0, 0, D_169cda0, 1, D_169cd50, 1, 0,
                        0, 0, 0);
extern const hkTypeInfo D_57c41d8;
const hkTypeInfo D_57c41d8("hkpRackAndPinionConstraintData", "!hkpRackAndPinionConstraintData",
                           finishLoadedObjecthkpRackAndPinionConstraintData,
                           cleanupLoadedObjecthkpRackAndPinionConstraintData,
                           vtableOfhkpRackAndPinionConstraintData(),
                           sizeof(hkpRackAndPinionConstraintData));
