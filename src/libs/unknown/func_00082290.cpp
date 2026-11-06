/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hkpHingeLimitsData's finish constructor (0x82250): the constraint data
 * finishes itself, the atoms need nothing, and the vtable is set. */
hkpHingeLimitsData::hkpHingeLimitsData(hkFinishLoadedObjectFlag flag)
    : hkpConstraintData(flag), atoms(flag)
{
}

/* The type infos' own callbacks, this file's (static): the atoms' finish
 * and cleanup folded by the linker into the shared empty body 0x3b640; the
 * data's finish, the constructor above inlined, folded into the
 * constructor itself (0x82250), its cleanup into 0x2d0. */
static void finishLoadedObjecthkpHingeLimitsDataAtoms(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpHingeLimitsData::Atoms(flag);
}

static void cleanupLoadedObjecthkpHingeLimitsDataAtoms(void *object)
{
    static_cast<hkpHingeLimitsData::Atoms *>(object)->~Atoms();
}

static void finishLoadedObjecthkpHingeLimitsData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpHingeLimitsData(flag);
}

static void cleanupLoadedObjecthkpHingeLimitsData(void *object)
{
    static_cast<hkpHingeLimitsData *>(object)->~hkpHingeLimitsData();
}

/* The address of the data's vtable, read from an object finished in a
 * buffer (the finish constructor inlined, the read folded to the address
 * point). derived name. */
static const void *vtableOfhkpHingeLimitsData()
{
    union {
        void *vtable;
        char buffer[sizeof(hkpHingeLimitsData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpHingeLimitsData(flag);
    return object.vtable;
}

/* The two classes' member records and the atoms' axis enum with its items,
 * file-local (D17); the rows are written at build time from the user's
 * executable (D18, config/data_schema.base.txt). The atoms' classes they
 * cite are named after the members that hold them (derived names). */
extern const hkClass D_57c51f0; /* the local rotations atom's */
extern const hkClass D_57c4850; /* the angular limit atom's */
extern const hkClass D_57c4600; /* the 2d angular atom's */
extern const hkClass D_57c58a8;
static const hkClassMember D_169f4a0[3] = {
#include "gen/D_169f4a0.inc"
};
static const hkClassMember D_169f520[1] = {
#include "gen/D_169f520.inc"
};
static const hkClassEnum::Item D_169f550[3] = {
#include "gen/D_169f550.inc"
};
static const hkClassEnum D_169f580[1] = {
#include "gen/D_169f580.inc"
};

/* This file's static initializer (0x82290): the atoms' reflection (no
 * parent, the axis enum, three members) and type info (no vtable), then
 * hkpHingeLimitsData's over hkpConstraintData's (one member) and type info. */
const hkClass D_57c58a8("hkpHingeLimitsDataAtoms", 0, sizeof(hkpHingeLimitsData::Atoms), 0, 0,
                        D_169f580, 1, D_169f4a0, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57c58f8;
const hkTypeInfo D_57c58f8("hkpHingeLimitsDataAtoms", "!hkpHingeLimitsData::Atoms",
                           finishLoadedObjecthkpHingeLimitsDataAtoms,
                           cleanupLoadedObjecthkpHingeLimitsDataAtoms, 0,
                           sizeof(hkpHingeLimitsData::Atoms));
const hkClass D_57c5928("hkpHingeLimitsData", &D_57c45a8, sizeof(hkpHingeLimitsData), 0, 0, 0, 0,
                        D_169f520, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57c5978;
const hkTypeInfo D_57c5978("hkpHingeLimitsData", "!hkpHingeLimitsData",
                           finishLoadedObjecthkpHingeLimitsData,
                           cleanupLoadedObjecthkpHingeLimitsData, vtableOfhkpHingeLimitsData(),
                           sizeof(hkpHingeLimitsData));
