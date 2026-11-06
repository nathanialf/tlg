/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpBallAndSocketConstraintData's finish constructor (0x7cbf0): the constraint data
 * finishes itself, the atoms need nothing, and the vtable is set. */
hkpBallAndSocketConstraintData::hkpBallAndSocketConstraintData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
}

/* The type infos' own callbacks, this file's (static): the atoms' finish
 * and cleanup folded by the linker into the shared empty body 0x3b640; the
 * data's finish, the constructor above inlined, folded into the
 * constructor itself (0x7cbf0), its cleanup into 0x2d0. */
static void finishLoadedObjecthkpBallAndSocketConstraintDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpBallAndSocketConstraintData::Atoms(flag);
}

static void cleanupLoadedObjecthkpBallAndSocketConstraintDataAtoms(void *object)
{
    static_cast<hkpBallAndSocketConstraintData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpBallAndSocketConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpBallAndSocketConstraintData(flag);
}

static void cleanupLoadedObjecthkpBallAndSocketConstraintData(void *object)
{
    static_cast<hkpBallAndSocketConstraintData *>(object)->~hkpBallAndSocketConstraintData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkpBallAndSocketConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpBallAndSocketConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpBallAndSocketConstraintData(flag);
    return object.vtable;
}

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
extern const hkClass D_57c4a40;
extern const hkClass D_57c52f0;
extern const hkClass D_57c5370;
extern const hkClass D_57c3f08;
static const hkClassMember D_169cab0[3] = {
#include "gen/D_169cab0.inc"
};
static const hkClassMember D_169cb30[1] = {
#include "gen/D_169cb30.inc"
};

/* This file's static initializer (0x7cc30): the atoms' reflection (no
 * parent, 3 members) and type info (no vtable), then hkpBallAndSocketConstraintData's over
 * hkpConstraintData's (1 member) and type info. */
const hkClass D_57c3f08("hkpBallAndSocketConstraintDataAtoms", 0,
                        sizeof(hkpBallAndSocketConstraintData::Atoms), 0, 0, 0, 0, D_169cab0, 3, 0,
                        0, 0, 1);
extern const hkTypeInfo D_57c3f58;
const hkTypeInfo D_57c3f58("hkpBallAndSocketConstraintDataAtoms",
                           "!hkpBallAndSocketConstraintData::Atoms",
                           finishLoadedObjecthkpBallAndSocketConstraintDataAtoms,
                           cleanupLoadedObjecthkpBallAndSocketConstraintDataAtoms, 0,
                           sizeof(hkpBallAndSocketConstraintData::Atoms));
const hkClass D_57c3f88("hkpBallAndSocketConstraintData", &D_57c45a8,
                        sizeof(hkpBallAndSocketConstraintData), 0, 0, 0, 0, D_169cb30, 1, 0, 0, 0,
                        0);
extern const hkTypeInfo D_57c3fd8;
const hkTypeInfo D_57c3fd8("hkpBallAndSocketConstraintData", "!hkpBallAndSocketConstraintData",
                           finishLoadedObjecthkpBallAndSocketConstraintData,
                           cleanupLoadedObjecthkpBallAndSocketConstraintData,
                           vtableOfhkpBallAndSocketConstraintData(),
                           sizeof(hkpBallAndSocketConstraintData));
