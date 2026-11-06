/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static): the bridge atom's
 * finish and cleanup folded by the linker into the shared empty body
 * 0x3b640; the malleable data's finish kept at 0x615c0 beside the
 * initializer (a jump to the out-of-line finish constructor), its cleanup
 * folded into 0x2d0. */
static void finishLoadedObjecthknpBridgeConstraintAtom(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpBridgeConstraintAtom(flag);
}

static void cleanupLoadedObjecthknpBridgeConstraintAtom(void *object)
{
    static_cast<hknpBridgeConstraintAtom *>(object)->~hknpBridgeConstraintAtom();
}

static void finishLoadedObjecthknpMalleableConstraintData(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpMalleableConstraintData(flag);
}

static void cleanupLoadedObjecthknpMalleableConstraintData(void *object)
{
    static_cast<hknpMalleableConstraintData *>(object)->~hknpMalleableConstraintData();
}

/* The address of the malleable data's vtable, read from an object finished
 * in a buffer (its finish constructor out of line, so called). derived
 * name. */
static const void *vtableOfhknpMalleableConstraintData()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpMalleableConstraintData)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpMalleableConstraintData(flag);
    return object.vtable;
}

/* The two classes' member records, file-local (D17); the rows are written
 * at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
extern const hkClass D_57c1808;
static const hkClassMember D_1699620[3] = {
#include "gen/D_1699620.inc"
};
static const hkClassMember D_16996a0[3] = {
#include "gen/D_16996a0.inc"
};

/* This file's static initializer (0x615e0): the bridge atom's reflection
 * over hkpConstraintAtom's (three members) and type info (no vtable), then
 * hknpMalleableConstraintData's over hkpWrappedConstraintData's (three
 * members) and type info. */
const hkClass D_57c1808("hknpBridgeConstraintAtom", &D_57c4650, sizeof(hknpBridgeConstraintAtom), 0,
                        0, 0, 0, D_1699620, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57c1858;
const hkTypeInfo D_57c1858("hknpBridgeConstraintAtom", "!hknpBridgeConstraintAtom",
                           finishLoadedObjecthknpBridgeConstraintAtom,
                           cleanupLoadedObjecthknpBridgeConstraintAtom, 0,
                           sizeof(hknpBridgeConstraintAtom));
const hkClass D_57c1888("hknpMalleableConstraintData", &D_57c4308,
                        sizeof(hknpMalleableConstraintData), 0, 0, 0, 0, D_16996a0, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57c18d8;
const hkTypeInfo D_57c18d8("hknpMalleableConstraintData", "!hknpMalleableConstraintData",
                           finishLoadedObjecthknpMalleableConstraintData,
                           cleanupLoadedObjecthknpMalleableConstraintData,
                           vtableOfhknpMalleableConstraintData(),
                           sizeof(hknpMalleableConstraintData));
