/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static): the finish is kept
 * at 0x3f380 beside the initializer (a jump to the out-of-line finish
 * constructor), the cleanup folded by the linker into 0x2d0. */
static void finishLoadedObjecthknpMountedBallGun(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpMountedBallGun(flag);
}

static void cleanupLoadedObjecthknpMountedBallGun(void *object)
{
    static_cast<hknpMountedBallGun *>(object)->~hknpMountedBallGun();
}

/* The address of hknpMountedBallGun's vtable, read from an object finished
 * in a buffer (its finish constructor out of line, so called). derived
 * name. */
static const void *vtableOfhknpMountedBallGun()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpMountedBallGun)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpMountedBallGun(flag);
    return object.vtable;
}

/* The position's attributes, which its member record cites (their
 * hkVariants point to them, so they are not const). */
static hkRangeRealAttribute D_57c0ae8(-10000.0f, 100000.0f, -10000.0f, 100000.0f);
static hkUiAttribute D_57c0af8(true, true, hkUiAttribute::HideCriteria(0), "World Position", "", "",
                               false, false, false);
static hkSemanticsAttribute D_57c0b20(hkSemanticsAttribute::POSITION);

extern const hkClass D_57c2070; /* derived name: hknpBallGun's hkClass */
extern const hkClass D_57b8c90; /* derived name: hkRangeRealAttribute's hkClass */
extern const hkClass D_57b8e10; /* derived name: hkUiAttribute's hkClass */
extern const hkClass D_57b8d90; /* derived name: hkSemanticsAttribute's hkClass */

/* The position's attributes and its member record, file-local (D17); the
 * rows are written at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hkCustomAttributes::Attribute D_1696cd0[3] = {
#include "gen/D_1696cd0.inc"
};
static const hkCustomAttributes D_1696cb8[1] = {
#include "gen/D_1696cb8.inc"
};
static const hkClassMember D_1696c90[1] = {
#include "gen/D_1696c90.inc"
};

/* Its member's defaults, file-local (D17, D18). */
static const hknpMountedBallGunDefaults D_14bb724[1] = {
#include "gen/D_14bb724.inc"
};

/* This file's static initializer (0x3f3a0): the position's attributes,
 * hknpMountedBallGun's reflection over hknpBallGun's (one member, its
 * defaults) and type info. */
const hkClass D_57c0a68("hknpMountedBallGun", &D_57c2070, sizeof(hknpMountedBallGun), 0, 0, 0, 0,
                        D_1696c90, 1, D_14bb724, 0, 0, 0);
extern const hkTypeInfo D_57c0ab8;
const hkTypeInfo D_57c0ab8("hknpMountedBallGun", "!hknpMountedBallGun",
                           finishLoadedObjecthknpMountedBallGun,
                           cleanupLoadedObjecthknpMountedBallGun, vtableOfhknpMountedBallGun(),
                           sizeof(hknpMountedBallGun));
