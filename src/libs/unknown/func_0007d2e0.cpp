/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpHingeConstraintData's finish constructor (0x7d2a0): the constraint data
 * finishes itself, the atoms need nothing, and the vtable is set. */
hkpHingeConstraintData::hkpHingeConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
}

/* The type infos' own callbacks, this file's (static): the atoms' finish
 * and cleanup folded by the linker into the shared empty body 0x3b640; the
 * data's finish, the constructor above inlined, folded into the
 * constructor itself (0x7d2a0), its cleanup into 0x2d0. */
static void finishLoadedObjecthkpHingeConstraintDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpHingeConstraintData::Atoms(flag);
}

static void cleanupLoadedObjecthkpHingeConstraintDataAtoms(void *object)
{
    static_cast<hkpHingeConstraintData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpHingeConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpHingeConstraintData(flag);
}

static void cleanupLoadedObjecthkpHingeConstraintData(void *object)
{
    static_cast<hkpHingeConstraintData *>(object)->~hkpHingeConstraintData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkpHingeConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpHingeConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpHingeConstraintData(flag);
    return object.vtable;
}

/* The two classes' member records and the atoms' axis enum with its item,
 * file-local (D17); the rows are written at build time from the user's
 * executable (D18, config/data_schema.base.txt). The atoms' classes they
 * cite are named after the members that hold them (derived names). */
extern const hkClass D_57c5270; /* the transforms atom's */
extern const hkClass D_57c5370; /* the setup stabilization atom's */
extern const hkClass D_57c4600; /* the 2d angular atom's */
extern const hkClass D_57c4a40; /* the ball-socket atom's */
extern const hkClass D_57c4208;
static const hkClassMember D_169cdd0[4] = {
#include "gen/D_169cdd0.inc"
};
static const hkClassMember D_169ce70[1] = {
#include "gen/D_169ce70.inc"
};
static const hkClassEnum::Item D_169cea0[1] = {
#include "gen/D_169cea0.inc"
};
static const hkClassEnum D_169ceb0[1] = {
#include "gen/D_169ceb0.inc"
};

/* This file's static initializer (0x7d2e0): the atoms' reflection (no
 * parent, the axis enum, four members, version 1) and type info (no vtable),
 * then hkpHingeConstraintData's over hkpConstraintData's (one member) and
 * type info. */
const hkClass D_57c4208("hkpHingeConstraintDataAtoms", 0, sizeof(hkpHingeConstraintData::Atoms), 0,
                        0, D_169ceb0, 1, D_169cdd0, 4, 0, 0, 0, 1);
extern const hkTypeInfo D_57c4258;
const hkTypeInfo D_57c4258("hkpHingeConstraintDataAtoms", "!hkpHingeConstraintData::Atoms",
                           finishLoadedObjecthkpHingeConstraintDataAtoms,
                           cleanupLoadedObjecthkpHingeConstraintDataAtoms, 0,
                           sizeof(hkpHingeConstraintData::Atoms));
const hkClass D_57c4288("hkpHingeConstraintData", &D_57c45a8, sizeof(hkpHingeConstraintData), 0, 0,
                        0, 0, D_169ce70, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c42d8;
const hkTypeInfo D_57c42d8("hkpHingeConstraintData", "!hkpHingeConstraintData",
                           finishLoadedObjecthkpHingeConstraintData,
                           cleanupLoadedObjecthkpHingeConstraintData,
                           vtableOfhkpHingeConstraintData(), sizeof(hkpHingeConstraintData));
