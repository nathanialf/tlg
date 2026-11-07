/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpRagdollConstraintData's finish constructor (0x82c70): the
 * constraint data finishes itself, the vtable is set, then the atoms finish
 * themselves (their constructor is out of line); a finished one with a cone
 * limit's angle offset has the cone's angle offset reset (0x7dad0). */
hkpRagdollConstraintData::hkpRagdollConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
    if (flag.finishing && atoms.coneLimit.memOffsetToAngleOffset) {
        FUN_0007dad0(true);
    }
}

/* The type infos' own callbacks, this file's (static): the atoms' finish
 * kept beside the initializer (0x82c40, a jump to their out-of-line finish
 * constructor), their cleanup folded by the linker into the shared empty
 * body 0x3b640; the data's finish, the constructor above inlined, folded
 * into the constructor itself (0x82c70), its cleanup into 0x2d0. */
static void finishLoadedObjecthkpRagdollConstraintDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpRagdollConstraintData::Atoms(flag);
}

static void cleanupLoadedObjecthkpRagdollConstraintDataAtoms(void *object)
{
    static_cast<hkpRagdollConstraintData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpRagdollConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpRagdollConstraintData(flag);
}

static void cleanupLoadedObjecthkpRagdollConstraintData(void *object)
{
    static_cast<hkpRagdollConstraintData *>(object)->~hkpRagdollConstraintData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkpRagdollConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpRagdollConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpRagdollConstraintData(flag);
    return object.vtable;
}

/* The atoms' axis enum and the data's motor index enum with their items and the
 * two classes' member records,
 * file-local (D17); the rows are written at build time from the user's
 * executable (D18, config/data_schema.base.txt). The atoms' classes they
 * cite are named after the members that hold them (derived names). */
extern const hkClass D_57c5270; /* the transforms atom's */
extern const hkClass D_57c5370; /* the setup stabilization atom's */
extern const hkClass D_57c5170; /* the ragdoll motors atom's */
extern const hkClass D_57c47d0; /* the angular friction atom's */
extern const hkClass D_57c5470; /* the twist limit atom's */
extern const hkClass D_57c4b40; /* the cone limit atom's */
extern const hkClass D_57c4a40; /* the ball-socket atom's */
extern const hkClass D_57c5af8;
static const hkClassEnum::Item D_169fd20[3] = {
#include "gen/D_169fd20.inc"
};
static const hkClassEnum D_169fd50[1] = {
#include "gen/D_169fd50.inc"
};
static const hkClassMember D_169fbb0[8] = {
#include "gen/D_169fbb0.inc"
};
static const hkClassEnum::Item D_169fd80[4] = {
#include "gen/D_169fd80.inc"
};
static const hkClassEnum D_169fdc0[1] = {
#include "gen/D_169fdc0.inc"
};
static const hkClassMember D_169fcf0[1] = {
#include "gen/D_169fcf0.inc"
};

/* This file's static initializer (0x82cd0): the atoms' reflection (no
 * parent, the axis enum, eight members, version 1) and type info (no
 * vtable), then hkpRagdollConstraintData's over hkpConstraintData's (its
 * motor index enum, one member) and type info. */
const hkClass D_57c5af8("hkpRagdollConstraintDataAtoms", 0, sizeof(hkpRagdollConstraintData::Atoms),
                        0, 0, D_169fd50, 1, D_169fbb0, 8, 0, 0, 0, 1);
extern const hkTypeInfo D_57c5b48;
const hkTypeInfo D_57c5b48("hkpRagdollConstraintDataAtoms", "!hkpRagdollConstraintData::Atoms",
                           finishLoadedObjecthkpRagdollConstraintDataAtoms,
                           cleanupLoadedObjecthkpRagdollConstraintDataAtoms, 0,
                           sizeof(hkpRagdollConstraintData::Atoms));
const hkClass D_57c5b78("hkpRagdollConstraintData", &D_57c45a8, sizeof(hkpRagdollConstraintData), 0,
                        0, D_169fdc0, 1, D_169fcf0, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c5bc8;
const hkTypeInfo D_57c5bc8("hkpRagdollConstraintData", "!hkpRagdollConstraintData",
                           finishLoadedObjecthkpRagdollConstraintData,
                           cleanupLoadedObjecthkpRagdollConstraintData,
                           vtableOfhkpRagdollConstraintData(), sizeof(hkpRagdollConstraintData));
