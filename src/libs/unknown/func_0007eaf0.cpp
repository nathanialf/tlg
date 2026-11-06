/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpWheelConstraintData's finish constructor (0x7eab0): the constraint data
 * finishes itself, the atoms need nothing, and the vtable is set. */
hkpWheelConstraintData::hkpWheelConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
}

/* The type infos' own callbacks, this file's (static): the atoms' finish
 * and cleanup folded by the linker into the shared empty body 0x3b640; the
 * data's finish, the constructor above inlined, folded into the
 * constructor itself (0x7eab0), its cleanup into 0x2d0. */
static void finishLoadedObjecthkpWheelConstraintDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpWheelConstraintData::Atoms(flag);
}

static void cleanupLoadedObjecthkpWheelConstraintDataAtoms(void *object)
{
    static_cast<hkpWheelConstraintData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpWheelConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpWheelConstraintData(flag);
}

static void cleanupLoadedObjecthkpWheelConstraintData(void *object)
{
    static_cast<hkpWheelConstraintData *>(object)->~hkpWheelConstraintData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkpWheelConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpWheelConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpWheelConstraintData(flag);
    return object.vtable;
}

/* The two classes' member records and the atoms' axis enum with its items,
 * file-local (D17); the rows are written at build time from the user's
 * executable (D18, config/data_schema.base.txt). The atoms' classes they
 * cite are named after the members that hold them (derived names). */
extern const hkClass D_57c5270; /* the transforms atom's */
extern const hkClass D_57c4e70; /* the linear limit atom's */
extern const hkClass D_57c4f70; /* the linear soft atom's */
extern const hkClass D_57c4d70; /* the lin atom's */
extern const hkClass D_57c51f0; /* the local rotations atom's */
extern const hkClass D_57c4600; /* the 2d angular atom's */
extern const hkClass D_57c4358;
static const hkClassMember D_169d2e0[7] = {
#include "gen/D_169d2e0.inc"
};
static const hkClassMember D_169d400[3] = {
#include "gen/D_169d400.inc"
};
static const hkClassEnum::Item D_169d480[4] = {
#include "gen/D_169d480.inc"
};
static const hkClassEnum D_169d4c0[1] = {
#include "gen/D_169d4c0.inc"
};

/* This file's static initializer (0x7eaf0): the atoms' reflection (no
 * parent, the axis enum, seven members) and type info (no vtable), then
 * hkpWheelConstraintData's over hkpConstraintData's (three members) and type
 * info. */
const hkClass D_57c4358("hkpWheelConstraintDataAtoms", 0, sizeof(hkpWheelConstraintData::Atoms), 0,
                        0, D_169d4c0, 1, D_169d2e0, 7, 0, 0, 0, 0);
extern const hkTypeInfo D_57c43a8;
const hkTypeInfo D_57c43a8("hkpWheelConstraintDataAtoms", "!hkpWheelConstraintData::Atoms",
                           finishLoadedObjecthkpWheelConstraintDataAtoms,
                           cleanupLoadedObjecthkpWheelConstraintDataAtoms, 0,
                           sizeof(hkpWheelConstraintData::Atoms));
const hkClass D_57c43d8("hkpWheelConstraintData", &D_57c45a8, sizeof(hkpWheelConstraintData), 0, 0,
                        0, 0, D_169d400, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57c4428;
const hkTypeInfo D_57c4428("hkpWheelConstraintData", "!hkpWheelConstraintData",
                           finishLoadedObjecthkpWheelConstraintData,
                           cleanupLoadedObjecthkpWheelConstraintData,
                           vtableOfhkpWheelConstraintData(), sizeof(hkpWheelConstraintData));
