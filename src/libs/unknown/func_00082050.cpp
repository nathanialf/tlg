/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpLimitedHingeConstraintData's finish constructor (0x82000): the
 * constraint data finishes itself, the vtable is set, then the atoms finish
 * themselves (their constructor is out of line). */
hkpLimitedHingeConstraintData::hkpLimitedHingeConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
}

/* The type infos' own callbacks, this file's (static): the atoms' finish
 * kept beside the initializer (0x81fd0, a jump to their out-of-line finish
 * constructor), their cleanup folded by the linker into the shared empty
 * body 0x3b640; the data's finish, the constructor above inlined, folded
 * into the constructor itself (0x82000), its cleanup into 0x2d0. */
static void finishLoadedObjecthkpLimitedHingeConstraintDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpLimitedHingeConstraintData::Atoms(flag);
}

static void cleanupLoadedObjecthkpLimitedHingeConstraintDataAtoms(void *object)
{
    static_cast<hkpLimitedHingeConstraintData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpLimitedHingeConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpLimitedHingeConstraintData(flag);
}

static void cleanupLoadedObjecthkpLimitedHingeConstraintData(void *object)
{
    static_cast<hkpLimitedHingeConstraintData *>(object)->~hkpLimitedHingeConstraintData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkpLimitedHingeConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpLimitedHingeConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpLimitedHingeConstraintData(flag);
    return object.vtable;
}

/* The atoms' axis enum with its items and the two classes' member records,
 * file-local (D17); the rows are written at build time from the user's
 * executable (D18, config/data_schema.base.txt). The atoms' classes they
 * cite are named after the members that hold them (derived names). */
extern const hkClass D_57c5270; /* the transforms atom's */
extern const hkClass D_57c5370; /* the setup stabilization atom's */
extern const hkClass D_57c48d0; /* the angular motor atom's */
extern const hkClass D_57c47d0; /* the angular friction atom's */
extern const hkClass D_57c4850; /* the angular limit atom's */
extern const hkClass D_57c4600; /* the 2d angular atom's */
extern const hkClass D_57c4a40; /* the ball-socket atom's */
extern const hkClass D_57c57a8;
static const hkClassEnum::Item D_169f440[3] = {
#include "gen/D_169f440.inc"
};
static const hkClassEnum D_169f470[1] = {
#include "gen/D_169f470.inc"
};
static const hkClassMember D_169f2f0[7] = {
#include "gen/D_169f2f0.inc"
};
static const hkClassMember D_169f410[1] = {
#include "gen/D_169f410.inc"
};

/* This file's static initializer (0x82050): the atoms' reflection (no
 * parent, the axis enum, seven members, version 1) and type info (no vtable), then
 * hkpLimitedHingeConstraintData's over hkpConstraintData's (one member) and
 * type info. */
const hkClass D_57c57a8("hkpLimitedHingeConstraintDataAtoms", 0,
                        sizeof(hkpLimitedHingeConstraintData::Atoms), 0, 0, D_169f470, 1, D_169f2f0,
                        7, 0, 0, 0, 1);
extern const hkTypeInfo D_57c57f8;
const hkTypeInfo D_57c57f8("hkpLimitedHingeConstraintDataAtoms",
                           "!hkpLimitedHingeConstraintData::Atoms",
                           finishLoadedObjecthkpLimitedHingeConstraintDataAtoms,
                           cleanupLoadedObjecthkpLimitedHingeConstraintDataAtoms, 0,
                           sizeof(hkpLimitedHingeConstraintData::Atoms));
const hkClass D_57c5828("hkpLimitedHingeConstraintData", &D_57c45a8,
                        sizeof(hkpLimitedHingeConstraintData), 0, 0, 0, 0, D_169f410, 1, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57c5878;
const hkTypeInfo D_57c5878("hkpLimitedHingeConstraintData", "!hkpLimitedHingeConstraintData",
                           finishLoadedObjecthkpLimitedHingeConstraintData,
                           cleanupLoadedObjecthkpLimitedHingeConstraintData,
                           vtableOfhkpLimitedHingeConstraintData(),
                           sizeof(hkpLimitedHingeConstraintData));
