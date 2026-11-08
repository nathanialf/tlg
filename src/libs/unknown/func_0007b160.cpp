/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the atoms' and the constraint data's finishes kept beside the
 * initializer (0x7b0d0, 0x7b110); the runtime's and the atoms' cleanups
 * folded by the linker into the empty body 0x3b640, the constraint data's
 * into the shared virtual destructor call 0x2d0. */
static void cleanupLoadedObjecthkpWheelFrictionConstraintDataRuntime(void *object)
{
    static_cast<hkpWheelFrictionConstraintData::Runtime *>(object)->~Runtime();
}

static void finishLoadedObjecthkpWheelFrictionConstraintDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpWheelFrictionConstraintData::Atoms(flag);
}

static void cleanupLoadedObjecthkpWheelFrictionConstraintDataAtoms(void *object)
{
    static_cast<hkpWheelFrictionConstraintData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpWheelFrictionConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpWheelFrictionConstraintData(flag);
}

static void cleanupLoadedObjecthkpWheelFrictionConstraintData(void *object)
{
    static_cast<hkpWheelFrictionConstraintData *>(object)->~hkpWheelFrictionConstraintData();
}

/* The address of the class's vtable, read from an object finished in a
 * buffer (folded to the address point). derived name. */
static const void *vtableOfhkpWheelFrictionConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpWheelFrictionConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpWheelFrictionConstraintData(flag);
    return object.vtable;
}

extern const hkClass D_57c5270; /* hkpSetLocalTransformsConstraintAtom's hkClass */
extern const hkClass D_57c5570; /* hkpWheelFrictionConstraintAtom's hkClass */
extern const hkClass D_57c38e8;

/* The member records, file-local (D17); the rows are written at build time
 * from the user's executable (D18, config/data_schema.base.txt). */
static const hkClassMember D_169c230[2] = {
#include "gen/D_169c230.inc"
};
static const hkClassMember D_169c280[1] = {
#include "gen/D_169c280.inc"
};

/* This file's static initializer (0x7b160): the runtime's reflection (no
 * members) and type info (no finish), the atoms' and their type info, then
 * hkpWheelFrictionConstraintData's over hkpConstraintData's with its type
 * info and vtable. The type infos' names are the base's strings. */
extern const hkClass D_57c3868;
const hkClass D_57c3868("hkpWheelFrictionConstraintDataRuntime", 0,
                        sizeof(hkpWheelFrictionConstraintData::Runtime), 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57c38b8;
const hkTypeInfo D_57c38b8("hkpWheelFrictionConstraintDataRuntime",
                           "!hkpWheelFrictionConstraintData::Runtime", 0,
                           cleanupLoadedObjecthkpWheelFrictionConstraintDataRuntime, 0,
                           sizeof(hkpWheelFrictionConstraintData::Runtime));
const hkClass D_57c38e8("hkpWheelFrictionConstraintDataAtoms", 0,
                        sizeof(hkpWheelFrictionConstraintData::Atoms), 0, 0, 0, 0, D_169c230, 2, 0,
                        0, 0, 0);
extern const hkTypeInfo D_57c3938;
const hkTypeInfo D_57c3938("hkpWheelFrictionConstraintDataAtoms",
                           "!hkpWheelFrictionConstraintData::Atoms",
                           finishLoadedObjecthkpWheelFrictionConstraintDataAtoms,
                           cleanupLoadedObjecthkpWheelFrictionConstraintDataAtoms, 0,
                           sizeof(hkpWheelFrictionConstraintData::Atoms));
extern const hkClass D_57c3968;
const hkClass D_57c3968("hkpWheelFrictionConstraintData", &D_57c45a8,
                        sizeof(hkpWheelFrictionConstraintData), 0, 0, 0, 0, D_169c280, 1, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57c39b8;
const hkTypeInfo D_57c39b8("hkpWheelFrictionConstraintData", "!hkpWheelFrictionConstraintData",
                           finishLoadedObjecthkpWheelFrictionConstraintData,
                           cleanupLoadedObjecthkpWheelFrictionConstraintData,
                           vtableOfhkpWheelFrictionConstraintData(),
                           sizeof(hkpWheelFrictionConstraintData));
