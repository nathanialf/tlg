/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpPrismaticConstraintData's finish constructor (0x7ce10): the
 * constraint data finishes itself, the vtable is set, then the atoms finish
 * themselves (their constructor is out of line). */
hkpPrismaticConstraintData::hkpPrismaticConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
}

/* The type infos' own callbacks, this file's (static): the atoms' finish
 * kept beside the initializer (0x7cde0, a jump to their out-of-line finish
 * constructor), their cleanup folded by the linker into the shared empty
 * body 0x3b640; the data's finish, the constructor above inlined, folded
 * into the constructor itself (0x7ce10), its cleanup into 0x2d0. */
static void finishLoadedObjecthkpPrismaticConstraintDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpPrismaticConstraintData::Atoms(flag);
}

static void cleanupLoadedObjecthkpPrismaticConstraintDataAtoms(void *object)
{
    static_cast<hkpPrismaticConstraintData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpPrismaticConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpPrismaticConstraintData(flag);
}

static void cleanupLoadedObjecthkpPrismaticConstraintData(void *object)
{
    static_cast<hkpPrismaticConstraintData *>(object)->~hkpPrismaticConstraintData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkpPrismaticConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpPrismaticConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpPrismaticConstraintData(flag);
    return object.vtable;
}

/* The atoms' axis enum with its items and the two classes' member records,
 * file-local (D17); the rows are written at build time from the user's
 * executable (D18, config/data_schema.base.txt). The atoms' classes they
 * cite are named after the members that hold them (derived names). */
extern const hkClass D_57c5270; /* the transforms atom's */
extern const hkClass D_57c4ef0; /* the linear motor atom's */
extern const hkClass D_57c4df0; /* the linear friction atom's */
extern const hkClass D_57c4750; /* the angular atom's */
extern const hkClass D_57c4d70; /* the linear atom's */
extern const hkClass D_57c4e70; /* the linear limit atom's */
extern const hkClass D_57c4008;
static const hkClassEnum::Item D_169ccb0[2] = {
#include "gen/D_169ccb0.inc"
};
static const hkClassEnum D_169ccd0[1] = {
#include "gen/D_169ccd0.inc"
};
static const hkClassMember D_169cb60[7] = {
#include "gen/D_169cb60.inc"
};
static const hkClassMember D_169cc80[1] = {
#include "gen/D_169cc80.inc"
};

/* This file's static initializer (0x7ce60): the atoms' reflection (no
 * parent, the axis enum, seven members) and type info (no vtable), then
 * hkpPrismaticConstraintData's over hkpConstraintData's (one member) and
 * type info. */
const hkClass D_57c4008("hkpPrismaticConstraintDataAtoms", 0,
                        sizeof(hkpPrismaticConstraintData::Atoms), 0, 0, D_169ccd0, 1, D_169cb60, 7,
                        0, 0, 0, 0);
extern const hkTypeInfo D_57c4058;
const hkTypeInfo D_57c4058("hkpPrismaticConstraintDataAtoms", "!hkpPrismaticConstraintData::Atoms",
                           finishLoadedObjecthkpPrismaticConstraintDataAtoms,
                           cleanupLoadedObjecthkpPrismaticConstraintDataAtoms, 0,
                           sizeof(hkpPrismaticConstraintData::Atoms));
const hkClass D_57c4088("hkpPrismaticConstraintData", &D_57c45a8,
                        sizeof(hkpPrismaticConstraintData), 0, 0, 0, 0, D_169cc80, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c40d8;
const hkTypeInfo D_57c40d8("hkpPrismaticConstraintData", "!hkpPrismaticConstraintData",
                           finishLoadedObjecthkpPrismaticConstraintData,
                           cleanupLoadedObjecthkpPrismaticConstraintData,
                           vtableOfhkpPrismaticConstraintData(),
                           sizeof(hkpPrismaticConstraintData));
