/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpStiffSpringConstraintData's finish constructor (0x7aa50): the constraint data
 * finishes itself, the atoms need nothing, and the vtable is set. */
hkpStiffSpringConstraintData::hkpStiffSpringConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
}

/* The type infos' own callbacks, this file's (static): the atoms' finish
 * and cleanup folded by the linker into the shared empty body 0x3b640; the
 * data's finish, the constructor above inlined, folded into the
 * constructor itself (0x7aa50), its cleanup into 0x2d0. */
static void finishLoadedObjecthkpStiffSpringConstraintDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpStiffSpringConstraintData::Atoms(flag);
}

static void cleanupLoadedObjecthkpStiffSpringConstraintDataAtoms(void *object)
{
    static_cast<hkpStiffSpringConstraintData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpStiffSpringConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpStiffSpringConstraintData(flag);
}

static void cleanupLoadedObjecthkpStiffSpringConstraintData(void *object)
{
    static_cast<hkpStiffSpringConstraintData *>(object)->~hkpStiffSpringConstraintData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkpStiffSpringConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpStiffSpringConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpStiffSpringConstraintData(flag);
    return object.vtable;
}

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
extern const hkClass D_57c52f0;
extern const hkClass D_57c5370;
extern const hkClass D_57c53f0;
extern const hkClass D_57c3568;
static const hkClassMember D_169beb0[3] = {
#include "gen/D_169beb0.inc"
};
static const hkClassMember D_169bf30[1] = {
#include "gen/D_169bf30.inc"
};

/* This file's static initializer (0x7aa90): the atoms' reflection (no
 * parent, 3 members) and type info (no vtable), then hkpStiffSpringConstraintData's over
 * hkpConstraintData's (1 member) and type info. */
const hkClass D_57c3568("hkpStiffSpringConstraintDataAtoms", 0,
                        sizeof(hkpStiffSpringConstraintData::Atoms), 0, 0, 0, 0, D_169beb0, 3, 0, 0,
                        0, 1);
extern const hkTypeInfo D_57c35b8;
const hkTypeInfo D_57c35b8("hkpStiffSpringConstraintDataAtoms",
                           "!hkpStiffSpringConstraintData::Atoms",
                           finishLoadedObjecthkpStiffSpringConstraintDataAtoms,
                           cleanupLoadedObjecthkpStiffSpringConstraintDataAtoms, 0,
                           sizeof(hkpStiffSpringConstraintData::Atoms));
const hkClass D_57c35e8("hkpStiffSpringConstraintData", &D_57c45a8,
                        sizeof(hkpStiffSpringConstraintData), 0, 0, 0, 0, D_169bf30, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c3638;
const hkTypeInfo D_57c3638("hkpStiffSpringConstraintData", "!hkpStiffSpringConstraintData",
                           finishLoadedObjecthkpStiffSpringConstraintData,
                           cleanupLoadedObjecthkpStiffSpringConstraintData,
                           vtableOfhkpStiffSpringConstraintData(),
                           sizeof(hkpStiffSpringConstraintData));
