/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpPulleyConstraintData's finish constructor (0x7aec0): the constraint data
 * finishes itself, the atoms need nothing, and the vtable is set. */
hkpPulleyConstraintData::hkpPulleyConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
}

/* The type infos' own callbacks, this file's (static): the atoms' finish
 * and cleanup folded by the linker into the shared empty body 0x3b640; the
 * data's finish, the constructor above inlined, folded into the
 * constructor itself (0x7aec0), its cleanup into 0x2d0. */
static void finishLoadedObjecthkpPulleyConstraintDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpPulleyConstraintData::Atoms(flag);
}

static void cleanupLoadedObjecthkpPulleyConstraintDataAtoms(void *object)
{
    static_cast<hkpPulleyConstraintData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpPulleyConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpPulleyConstraintData(flag);
}

static void cleanupLoadedObjecthkpPulleyConstraintData(void *object)
{
    static_cast<hkpPulleyConstraintData *>(object)->~hkpPulleyConstraintData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkpPulleyConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpPulleyConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpPulleyConstraintData(flag);
    return object.vtable;
}

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
extern const hkClass D_57c5070;
extern const hkClass D_57c52f0;
extern const hkClass D_57c3768;
static const hkClassMember D_169c1b0[2] = {
#include "gen/D_169c1b0.inc"
};
static const hkClassMember D_169c200[1] = {
#include "gen/D_169c200.inc"
};

/* This file's static initializer (0x7af00): the atoms' reflection (no
 * parent, 2 members) and type info (no vtable), then hkpPulleyConstraintData's over
 * hkpConstraintData's (1 member) and type info. */
const hkClass D_57c3768("hkpPulleyConstraintDataAtoms", 0, sizeof(hkpPulleyConstraintData::Atoms),
                        0, 0, 0, 0, D_169c1b0, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57c37b8;
const hkTypeInfo D_57c37b8("hkpPulleyConstraintDataAtoms", "!hkpPulleyConstraintData::Atoms",
                           finishLoadedObjecthkpPulleyConstraintDataAtoms,
                           cleanupLoadedObjecthkpPulleyConstraintDataAtoms, 0,
                           sizeof(hkpPulleyConstraintData::Atoms));
const hkClass D_57c37e8("hkpPulleyConstraintData", &D_57c45a8, sizeof(hkpPulleyConstraintData), 0,
                        0, 0, 0, D_169c200, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c3838;
const hkTypeInfo D_57c3838("hkpPulleyConstraintData", "!hkpPulleyConstraintData",
                           finishLoadedObjecthkpPulleyConstraintData,
                           cleanupLoadedObjecthkpPulleyConstraintData,
                           vtableOfhkpPulleyConstraintData(), sizeof(hkpPulleyConstraintData));
