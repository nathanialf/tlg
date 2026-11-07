/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the finish kept at 0x39e30 beside the initializer (a jump to the
 * out-of-line finish constructor), the cleanup folded by the linker into
 * 0x2d0. */
static void finishLoadedObjecthknpProjectileGun(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpProjectileGun(flag);
}

static void cleanupLoadedObjecthknpProjectileGun(void *object)
{
    static_cast<hknpProjectileGun *>(object)->~hknpProjectileGun();
}

/* The address of hknpProjectileGun's vtable, read from an object finished
 * in a buffer (its finish constructor out of line, so called). derived
 * name. */
static const void *vtableOfhknpProjectileGun()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpProjectileGun)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpProjectileGun(flag);
    return object.vtable;
}

/* The two members' attributes, which their records cite (their hkVariants
 * point to them, so they are not const). */
static hkUiAttribute D_57bf810(true, true, hkUiAttribute::HideCriteria(0),
                               "Max Projectiles in World", "", "", false, false, false);
static hkRangeInt32Attribute D_57bf838(0, 1000, 0, 1000);
static hkRangeRealAttribute D_57bf848(0.0f, 100.0f, 0.0f, 100.0f);
static hkUiAttribute D_57bf858(true, true, hkUiAttribute::HideCriteria(0), "Reload delay", "", "",
                               false, false, false);

extern const hkClass D_57bffb0; /* derived name: hknpFirstPersonGun's hkClass */
extern const hkClass D_57b8e10; /* derived name: hkUiAttribute's hkClass */
extern const hkClass D_57b8c10; /* derived name: hkRangeInt32Attribute's hkClass */
extern const hkClass D_57b8c90; /* derived name: hkRangeRealAttribute's hkClass */

/* The attributes and the member records, file-local (D17); the rows are
 * written at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hkCustomAttributes::Attribute D_1695140[2] = {
#include "gen/D_1695140.inc"
};
static const hkCustomAttributes::Attribute D_1695110[2] = {
#include "gen/D_1695110.inc"
};
static const hkCustomAttributes D_16950f8[1] = {
#include "gen/D_16950f8.inc"
};
static const hkCustomAttributes D_16950e8[1] = {
#include "gen/D_16950e8.inc"
};
static const hkClassMember D_1695020[5] = {
#include "gen/D_1695020.inc"
};

/* Its members' defaults, file-local (D17, D18). */
static const hknpProjectileGunDefaults D_14ba58c[1] = {
#include "gen/D_14ba58c.inc"
};

/* This file's static initializer (0x39e50): the members' attributes,
 * hknpProjectileGun's reflection over hknpFirstPersonGun's (five members,
 * their defaults) and type info. */
const hkClass D_57bf790("hknpProjectileGun", &D_57bffb0, sizeof(hknpProjectileGun), 0, 0, 0, 0,
                        D_1695020, 5, D_14ba58c, 0, 0, 0);
extern const hkTypeInfo D_57bf7e0;
const hkTypeInfo D_57bf7e0("hknpProjectileGun", "!hknpProjectileGun",
                           finishLoadedObjecthknpProjectileGun,
                           cleanupLoadedObjecthknpProjectileGun, vtableOfhknpProjectileGun(),
                           sizeof(hknpProjectileGun));
