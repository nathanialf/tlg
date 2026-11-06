/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static): the blueprints'
 * finish kept at 0x82660 (a jump to the out-of-line finish constructor),
 * their cleanup folded by the linker into the shared empty body 0x3b640;
 * the data's finish kept at 0x82690, its cleanup folded into 0x2d0. */
static void finishLoadedObjecthkp6DofConstraintDataBlueprints(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkp6DofConstraintData::Blueprints(flag);
}

static void cleanupLoadedObjecthkp6DofConstraintDataBlueprints(void *object)
{
    static_cast<hkp6DofConstraintData::Blueprints *>(object)->~Blueprints();
}

/* The data's finish constructor runs by its address's name while the
 * class has pure slots this header does not override (as 0x82690's stand-in
 * did). */
static void finishLoadedObjecthkp6DofConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_0017b5f0(static_cast<hkp6DofConstraintData *>(object), flag);
}

static void cleanupLoadedObjecthkp6DofConstraintData(void *object)
{
    static_cast<hkp6DofConstraintData *>(object)->~hkp6DofConstraintData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (its finish constructor out of line, so called). derived name. */
static const void *vtableOfhkp6DofConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkp6DofConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    FUN_0017b5f0(reinterpret_cast<hkp6DofConstraintData *>(object.buffer), flag);
    return object.vtable;
}

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt), and the data's two enums with their
 * items. */
extern const hkClass D_57c59f8;
/* The atoms' classes the records cite (derived names, after the members
 * that hold them). */
extern const hkClass D_57c5270; /* the transforms atom's */
extern const hkClass D_57c5370; /* the setup stabilization atom's */
extern const hkClass D_57c5170; /* the ragdoll motors atom's */
extern const hkClass D_57c47d0; /* the angular friction atom's */
extern const hkClass D_57c5470; /* the twist limit atom's */
extern const hkClass D_57c4cf0; /* the elliptical limit atom's */
extern const hkClass D_57c53f0; /* the stiff spring atom's */
extern const hkClass D_57c4ef0; /* the linear motor atom's */
extern const hkClass D_57c4a40; /* the ball-socket atom's */
static const hkClassMember D_169f730[12] = {
#include "gen/D_169f730.inc"
};
static const hkClassEnum::Item D_169fa00[4] = {
#include "gen/D_169fa00.inc"
};
static const hkClassEnum::Item D_169fa40[3] = {
#include "gen/D_169fa40.inc"
};
static const hkClassEnum D_169fa70[2] = {
#include "gen/D_169fa70.inc"
};
static const hkClassMember D_169f910[6] = {
#include "gen/D_169f910.inc"
};

/* This file's static initializer (0x826b0): the blueprints' reflection (no
 * parent, twelve members) and type info (no vtable), then
 * hkp6DofConstraintData's over hkpConstraintData's (two enums, six
 * members) and type info. */
const hkClass D_57c59f8("hkp6DofConstraintDataBlueprints", 0,
                        sizeof(hkp6DofConstraintData::Blueprints), 0, 0, 0, 0, D_169f730, 12, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57c5a48;
const hkTypeInfo D_57c5a48("hkp6DofConstraintDataBlueprints", "!hkp6DofConstraintData::Blueprints",
                           finishLoadedObjecthkp6DofConstraintDataBlueprints,
                           cleanupLoadedObjecthkp6DofConstraintDataBlueprints, 0,
                           sizeof(hkp6DofConstraintData::Blueprints));
const hkClass D_57c5a78("hkp6DofConstraintData", &D_57c45a8, sizeof(hkp6DofConstraintData), 0, 0,
                        D_169fa70, 2, D_169f910, 6, 0, 0, 0, 0);
extern const hkTypeInfo D_57c5ac8;
const hkTypeInfo D_57c5ac8("hkp6DofConstraintData", "!hkp6DofConstraintData",
                           finishLoadedObjecthkp6DofConstraintData,
                           cleanupLoadedObjecthkp6DofConstraintData,
                           vtableOfhkp6DofConstraintData(), sizeof(hkp6DofConstraintData));
