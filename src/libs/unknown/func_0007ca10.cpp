/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpCogWheelConstraintData's finish constructor (0x7c9d0): the constraint data
 * finishes itself, the atoms need nothing, and the vtable is set. */
hkpCogWheelConstraintData::hkpCogWheelConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
}

/* The type infos' own callbacks, this file's (static): the atoms' finish
 * and cleanup folded by the linker into the shared empty body 0x3b640; the
 * data's finish, the constructor above inlined, folded into the
 * constructor itself (0x7c9d0), its cleanup into 0x2d0. */
static void finishLoadedObjecthkpCogWheelConstraintDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpCogWheelConstraintData::Atoms(flag);
}

static void cleanupLoadedObjecthkpCogWheelConstraintDataAtoms(void *object)
{
    static_cast<hkpCogWheelConstraintData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpCogWheelConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpCogWheelConstraintData(flag);
}

static void cleanupLoadedObjecthkpCogWheelConstraintData(void *object)
{
    static_cast<hkpCogWheelConstraintData *>(object)->~hkpCogWheelConstraintData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkpCogWheelConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpCogWheelConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpCogWheelConstraintData(flag);
    return object.vtable;
}

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
extern const hkClass D_57c4ac0;
extern const hkClass D_57c5270;
extern const hkClass D_57c3e08;
static const hkClassMember D_169ca30[2] = {
#include "gen/D_169ca30.inc"
};
static const hkClassMember D_169ca80[1] = {
#include "gen/D_169ca80.inc"
};

/* This file's static initializer (0x7ca10): the atoms' reflection (no
 * parent, 2 members) and type info (no vtable), then hkpCogWheelConstraintData's over
 * hkpConstraintData's (1 member) and type info. */
const hkClass D_57c3e08("hkpCogWheelConstraintDataAtoms", 0,
                        sizeof(hkpCogWheelConstraintData::Atoms), 0, 0, 0, 0, D_169ca30, 2, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57c3e58;
const hkTypeInfo D_57c3e58("hkpCogWheelConstraintDataAtoms", "!hkpCogWheelConstraintData::Atoms",
                           finishLoadedObjecthkpCogWheelConstraintDataAtoms,
                           cleanupLoadedObjecthkpCogWheelConstraintDataAtoms, 0,
                           sizeof(hkpCogWheelConstraintData::Atoms));
const hkClass D_57c3e88("hkpCogWheelConstraintData", &D_57c45a8, sizeof(hkpCogWheelConstraintData),
                        0, 0, 0, 0, D_169ca80, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c3ed8;
const hkTypeInfo D_57c3ed8("hkpCogWheelConstraintData", "!hkpCogWheelConstraintData",
                           finishLoadedObjecthkpCogWheelConstraintData,
                           cleanupLoadedObjecthkpCogWheelConstraintData,
                           vtableOfhkpCogWheelConstraintData(), sizeof(hkpCogWheelConstraintData));
