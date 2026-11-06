/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static): the atoms' finish
 * and cleanup folded by the linker into the shared empty body 0x3b640; the
 * data's finish kept at 0x788f0 (its finish constructor inline: the cone's
 * stabilization turned back on when the loaded atoms had it), its cleanup
 * folded into 0x2d0. */
static void finishLoadedObjecthkpRagdollLimitsDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpRagdollLimitsData::Atoms(flag);
}

static void cleanupLoadedObjecthkpRagdollLimitsDataAtoms(void *object)
{
    static_cast<hkpRagdollLimitsData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpRagdollLimitsData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpRagdollLimitsData(flag);
}

static void cleanupLoadedObjecthkpRagdollLimitsData(void *object)
{
    static_cast<hkpRagdollLimitsData *>(object)->~hkpRagdollLimitsData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkpRagdollLimitsData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpRagdollLimitsData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpRagdollLimitsData(flag);
    return object.vtable;
}

/* The two classes' member records and the atoms' enum with its items,
 * file-local (D17); the rows are written at build time from the user's
 * executable (D18, config/data_schema.base.txt). */
extern const hkClass D_57c3168;
/* The atoms' classes the records cite (derived names, after the members
 * that hold them). */
extern const hkClass D_57c51f0; /* the local rotations atom's */
extern const hkClass D_57c5470; /* the twist limit atom's */
extern const hkClass D_57c4b40; /* the cone limit atom's */
static const hkClassMember D_169b8d0[4] = {
#include "gen/D_169b8d0.inc"
};
static const hkClassMember D_169b970[1] = {
#include "gen/D_169b970.inc"
};
static const hkClassEnum::Item D_169b9a0[3] = {
#include "gen/D_169b9a0.inc"
};
static const hkClassEnum D_169b9d0[1] = {
#include "gen/D_169b9d0.inc"
};

/* This file's static initializer (0x78950): the atoms' reflection (no
 * parent, the axis enum, four members) and type info (no vtable), then
 * hkpRagdollLimitsData's over hkpConstraintData's (one member) and type
 * info. */
const hkClass D_57c3168("hkpRagdollLimitsDataAtoms", 0, sizeof(hkpRagdollLimitsData::Atoms), 0, 0,
                        D_169b9d0, 1, D_169b8d0, 4, 0, 0, 0, 0);
extern const hkTypeInfo D_57c31b8;
const hkTypeInfo D_57c31b8("hkpRagdollLimitsDataAtoms", "!hkpRagdollLimitsData::Atoms",
                           finishLoadedObjecthkpRagdollLimitsDataAtoms,
                           cleanupLoadedObjecthkpRagdollLimitsDataAtoms, 0,
                           sizeof(hkpRagdollLimitsData::Atoms));
const hkClass D_57c31e8("hkpRagdollLimitsData", &D_57c45a8, sizeof(hkpRagdollLimitsData), 0, 0, 0,
                        0, D_169b970, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c3238;
const hkTypeInfo D_57c3238("hkpRagdollLimitsData", "!hkpRagdollLimitsData",
                           finishLoadedObjecthkpRagdollLimitsData,
                           cleanupLoadedObjecthkpRagdollLimitsData, vtableOfhkpRagdollLimitsData(),
                           sizeof(hkpRagdollLimitsData));
