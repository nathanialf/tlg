/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpLinearClearanceConstraintData's finish constructor (0x7ac70): the
 * constraint data finishes itself, the vtable is set, then the atoms finish
 * themselves (their constructor is out of line). */
hkpLinearClearanceConstraintData::hkpLinearClearanceConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
}

/* The type infos' own callbacks, this file's (static): the atoms' finish
 * kept beside the initializer (0x7ac40, a jump to their out-of-line finish
 * constructor), their cleanup folded by the linker into the shared empty
 * body 0x3b640; the data's finish, the constructor above inlined, folded
 * into the constructor itself (0x7ac70), its cleanup into 0x2d0. */
static void finishLoadedObjecthkpLinearClearanceConstraintDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpLinearClearanceConstraintData::Atoms(flag);
}

static void cleanupLoadedObjecthkpLinearClearanceConstraintDataAtoms(void *object)
{
    static_cast<hkpLinearClearanceConstraintData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpLinearClearanceConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpLinearClearanceConstraintData(flag);
}

static void cleanupLoadedObjecthkpLinearClearanceConstraintData(void *object)
{
    static_cast<hkpLinearClearanceConstraintData *>(object)->~hkpLinearClearanceConstraintData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkpLinearClearanceConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpLinearClearanceConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpLinearClearanceConstraintData(flag);
    return object.vtable;
}

/* The atoms' axis enum and the data's type enum with their items and the
 * two classes' member records,
 * file-local (D17); the rows are written at build time from the user's
 * executable (D18, config/data_schema.base.txt). The atoms' classes they
 * cite are named after the members that hold them (derived names). */
extern const hkClass D_57c5270; /* the transforms atom's */
extern const hkClass D_57c4ef0; /* the linear motor atom's */
extern const hkClass D_57c4df0; /* the linear friction atom's */
extern const hkClass D_57c4750; /* the angular atom's */
extern const hkClass D_57c4e70; /* the linear limit atom's */
extern const hkClass D_57c3668;
static const hkClassEnum::Item D_169c100[2] = {
#include "gen/D_169c100.inc"
};
static const hkClassEnum D_169c120[1] = {
#include "gen/D_169c120.inc"
};
static const hkClassMember D_169bf60[9] = {
#include "gen/D_169bf60.inc"
};
static const hkClassEnum::Item D_169c150[3] = {
#include "gen/D_169c150.inc"
};
static const hkClassEnum D_169c180[1] = {
#include "gen/D_169c180.inc"
};
static const hkClassMember D_169c0d0[1] = {
#include "gen/D_169c0d0.inc"
};

/* This file's static initializer (0x7acc0): the atoms' reflection (no
 * parent, the axis enum, nine members) and type info (no vtable), then
 * hkpLinearClearanceConstraintData's over hkpConstraintData's (its type
 * enum, one member) and type info. */
const hkClass D_57c3668("hkpLinearClearanceConstraintDataAtoms", 0,
                        sizeof(hkpLinearClearanceConstraintData::Atoms), 0, 0, D_169c120, 1,
                        D_169bf60, 9, 0, 0, 0, 0);
extern const hkTypeInfo D_57c36b8;
const hkTypeInfo D_57c36b8("hkpLinearClearanceConstraintDataAtoms",
                           "!hkpLinearClearanceConstraintData::Atoms",
                           finishLoadedObjecthkpLinearClearanceConstraintDataAtoms,
                           cleanupLoadedObjecthkpLinearClearanceConstraintDataAtoms, 0,
                           sizeof(hkpLinearClearanceConstraintData::Atoms));
const hkClass D_57c36e8("hkpLinearClearanceConstraintData", &D_57c45a8,
                        sizeof(hkpLinearClearanceConstraintData), 0, 0, D_169c180, 1, D_169c0d0, 1,
                        0, 0, 0, 0);
extern const hkTypeInfo D_57c3738;
const hkTypeInfo D_57c3738("hkpLinearClearanceConstraintData", "!hkpLinearClearanceConstraintData",
                           finishLoadedObjecthkpLinearClearanceConstraintData,
                           cleanupLoadedObjecthkpLinearClearanceConstraintData,
                           vtableOfhkpLinearClearanceConstraintData(),
                           sizeof(hkpLinearClearanceConstraintData));
