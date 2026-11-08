/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the finish is kept at 0x689a0 beside the initializer (a jump to the
 * out-of-line finish constructor), the cleanup folded by the linker into
 * 0x2d0. */
static void finishLoadedObjecthknpBallGun(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpBallGun(flag);
}

static void cleanupLoadedObjecthknpBallGun(void *object)
{
    static_cast<hknpBallGun *>(object)->~hknpBallGun();
}

/* The address of hknpBallGun's vtable, read from an object finished in a
 * buffer (its finish constructor out of line, so called). derived name. */
static const void *vtableOfhknpBallGun()
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpBallGun)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpBallGun(flag);
    return object.vtable;
}

/* The members' attributes, which their records' attribute tables cite
 * (their hkVariants point to them, so they are not const), in the members'
 * order. */
static hkRangeRealAttribute D_57c20f0(0.0f, 100.0f, 0.0f, 1.0f);
static hkUiAttribute D_57c2100(true, true, hkUiAttribute::HideCriteria(0), "Radius", "Bullet", "",
                               false, false, false);
static hkSemanticsAttribute D_57c2128(hkSemanticsAttribute::DISTANCE);
static hkRangeRealAttribute D_57c212c(0.0f, 10000.0f, 0.0f, 100.0f);
static hkRangeRealAttribute D_57c213c(0.0f, 1000000.0f, 0.0f, 100.0f);
static hkUiAttribute D_57c2150(true, true, hkUiAttribute::HideCriteria(0), "Mass", "", "", false,
                               false, false);
static hkRangeRealAttribute D_57c2178(0.0f, 10000.0f, 0.0f, 10.0f);
static hkUiAttribute D_57c2188(true, true, hkUiAttribute::HideCriteria(0), "", "", "", true, false,
                               false);
static hkUiAttribute D_57c21b0(true, true, hkUiAttribute::HideCriteria(0), "", "", "", false, false,
                               false);
static hkRangeInt32Attribute D_57c21d8(0, 100, 0, 100);
static hkRangeRealAttribute D_57c21e8(-10000.0f, 100000.0f, -10000.0f, 100000.0f);
static hkUiAttribute D_57c21f8(true, true, hkUiAttribute::HideCriteria(0), "Center Offset", "", "",
                               false, false, false);
static hkSemanticsAttribute D_57c2220(hkSemanticsAttribute::POSITION);

extern const hkClass D_57bffb0; /* hknpFirstPersonGun's hkClass */

/* The member records, read through the GOT as another file's (the lea
 * group's order and registers are the base's only so, cookbook 481 and
 * 740); they and the attribute tables they cite are left unclaimed. */
extern const hkClassMember D_1699d10[];

/* The members' defaults, file-local (D17); the rows are written at build
 * time from the user's executable (D18, config/data_schema.base.txt). */
static const hknpBallGunDefaults D_14be8b8[1] = {
#include "gen/D_14be8b8.inc"
};

/* This file's static initializer (0x689c0): the members' attributes,
 * hknpBallGun's reflection over hknpFirstPersonGun's (eleven members, their
 * defaults) and type info. */
const hkClass D_57c2070("hknpBallGun", &D_57bffb0, sizeof(hknpBallGun), 0, 0, 0, 0, D_1699d10, 11,
                        D_14be8b8, 0, 0, 0);
extern const hkTypeInfo D_57c20c0;
const hkTypeInfo D_57c20c0("hknpBallGun", "!hknpBallGun", finishLoadedObjecthknpBallGun,
                           cleanupLoadedObjecthknpBallGun, vtableOfhknpBallGun(),
                           sizeof(hknpBallGun));
