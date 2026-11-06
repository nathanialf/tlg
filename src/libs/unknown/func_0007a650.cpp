/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpFixedConstraintData's finish constructor (0x7a610): the constraint
 * data finishes itself, the atoms need nothing, and the vtable is set. */
hkpFixedConstraintData::hkpFixedConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
}

/* The type infos' own callbacks, this file's (static): the atoms' finish
 * and cleanup folded by the linker into the shared empty body 0x3b640; the
 * data's finish, the constructor above inlined, folded into the
 * constructor itself (0x7a610), its cleanup into 0x2d0. */
static void finishLoadedObjecthkpFixedConstraintDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpFixedConstraintData::Atoms(flag);
}

static void cleanupLoadedObjecthkpFixedConstraintDataAtoms(void *object)
{
    static_cast<hkpFixedConstraintData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpFixedConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpFixedConstraintData(flag);
}

static void cleanupLoadedObjecthkpFixedConstraintData(void *object)
{
    static_cast<hkpFixedConstraintData *>(object)->~hkpFixedConstraintData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkpFixedConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpFixedConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpFixedConstraintData(flag);
    return object.vtable;
}

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). The atoms' classes they cite are named
 * after the members that hold them (derived names). */
extern const hkClass D_57c5270; /* the transforms atom's */
extern const hkClass D_57c5370; /* the setup stabilization atom's */
extern const hkClass D_57c4a40; /* the ball-socket atom's */
extern const hkClass D_57c46d0; /* the angular atom's */
extern const hkClass D_57c3368;
static const hkClassMember D_169bd30[4] = {
#include "gen/D_169bd30.inc"
};
static const hkClassMember D_169bdd0[1] = {
#include "gen/D_169bdd0.inc"
};

/* This file's static initializer (0x7a650): the atoms' reflection (no
 * parent, four members) and type info (no vtable), then
 * hkpFixedConstraintData's over hkpConstraintData's (one member) and type
 * info. */
const hkClass D_57c3368("hkpFixedConstraintDataAtoms", 0, sizeof(hkpFixedConstraintData::Atoms), 0,
                        0, 0, 0, D_169bd30, 4, 0, 0, 0, 0);
extern const hkTypeInfo D_57c33b8;
const hkTypeInfo D_57c33b8("hkpFixedConstraintDataAtoms", "!hkpFixedConstraintData::Atoms",
                           finishLoadedObjecthkpFixedConstraintDataAtoms,
                           cleanupLoadedObjecthkpFixedConstraintDataAtoms, 0,
                           sizeof(hkpFixedConstraintData::Atoms));
const hkClass D_57c33e8("hkpFixedConstraintData", &D_57c45a8, sizeof(hkpFixedConstraintData), 0, 0,
                        0, 0, D_169bdd0, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c3438;
const hkTypeInfo D_57c3438("hkpFixedConstraintData", "!hkpFixedConstraintData",
                           finishLoadedObjecthkpFixedConstraintData,
                           cleanupLoadedObjecthkpFixedConstraintData,
                           vtableOfhkpFixedConstraintData(), sizeof(hkpFixedConstraintData));
