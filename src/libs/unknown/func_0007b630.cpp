/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpRotationalConstraintData's finish constructor (0x7b5f0): the constraint data
 * finishes itself, the atoms need nothing, and the vtable is set. */
hkpRotationalConstraintData::hkpRotationalConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
}

/* The type infos' own callbacks, this file's (static): the atoms' finish
 * and cleanup folded by the linker into the shared empty body 0x3b640; the
 * data's finish, the constructor above inlined, folded into the
 * constructor itself (0x7b5f0), its cleanup into 0x2d0. */
static void finishLoadedObjecthkpRotationalConstraintDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpRotationalConstraintData::Atoms(flag);
}

static void cleanupLoadedObjecthkpRotationalConstraintDataAtoms(void *object)
{
    static_cast<hkpRotationalConstraintData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpRotationalConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpRotationalConstraintData(flag);
}

static void cleanupLoadedObjecthkpRotationalConstraintData(void *object)
{
    static_cast<hkpRotationalConstraintData *>(object)->~hkpRotationalConstraintData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkpRotationalConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpRotationalConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpRotationalConstraintData(flag);
    return object.vtable;
}

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
extern const hkClass D_57c4750;
extern const hkClass D_57c51f0;
extern const hkClass D_57c39e8;
static const hkClassMember D_169c3a0[2] = {
#include "gen/D_169c3a0.inc"
};
static const hkClassMember D_169c3f0[1] = {
#include "gen/D_169c3f0.inc"
};

/* This file's static initializer (0x7b630): the atoms' reflection (no
 * parent, 2 members) and type info (no vtable), then hkpRotationalConstraintData's over
 * hkpConstraintData's (1 member) and type info. */
const hkClass D_57c39e8("hkpRotationalConstraintDataAtoms", 0,
                        sizeof(hkpRotationalConstraintData::Atoms), 0, 0, 0, 0, D_169c3a0, 2, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57c3a38;
const hkTypeInfo D_57c3a38("hkpRotationalConstraintDataAtoms",
                           "!hkpRotationalConstraintData::Atoms",
                           finishLoadedObjecthkpRotationalConstraintDataAtoms,
                           cleanupLoadedObjecthkpRotationalConstraintDataAtoms, 0,
                           sizeof(hkpRotationalConstraintData::Atoms));
const hkClass D_57c3a68("hkpRotationalConstraintData", &D_57c45a8,
                        sizeof(hkpRotationalConstraintData), 0, 0, 0, 0, D_169c3f0, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c3ab8;
const hkTypeInfo D_57c3ab8("hkpRotationalConstraintData", "!hkpRotationalConstraintData",
                           finishLoadedObjecthkpRotationalConstraintData,
                           cleanupLoadedObjecthkpRotationalConstraintData,
                           vtableOfhkpRotationalConstraintData(),
                           sizeof(hkpRotationalConstraintData));
