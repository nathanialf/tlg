/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the finish kept at 0x3ccf0 beside the initializer (a jump to the
 * out-of-line finish constructor), the cleanup folded by the linker into
 * 0x2d0. */
static void finishLoadedObjecthknpFirstPersonGun(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpFirstPersonGun(flag);
}

static void cleanupLoadedObjecthknpFirstPersonGun(void *object)
{
    static_cast<hknpFirstPersonGun *>(object)->~hknpFirstPersonGun();
}

/* The address of hknpFirstPersonGun's vtable, read from an object finished
 * in a buffer (its finish constructor out of line, so called). derived
 * name. */
static const void *vtableOfhknpFirstPersonGun()
{
    union {
        void *vtable;
        char buffer[sizeof(hknpFirstPersonGun)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpFirstPersonGun(flag);
    return object.vtable;
}

/* The two members' attributes, which their records cite (their hkVariants
 * point to them, so they are not const). */
static hkUiAttribute D_57c0030(false, true, hkUiAttribute::HideCriteria(0), "", "", "", false,
                               false, false);
static hkUiAttribute D_57c0058(true, true, hkUiAttribute::HideCriteria(0), "", "", "", false, false,
                               false);

extern const hkClass D_57b8e10; /* derived name: hkUiAttribute's hkClass */

/* The attributes, the class's two enums and its members' defaults,
 * file-local (D17); the rows are written at build time from the user's
 * executable (D18, config/data_schema.base.txt). */
static const hkCustomAttributes::Attribute D_16962f0[1] = {
#include "gen/D_16962f0.inc"
};
static const hkCustomAttributes::Attribute D_1696310[1] = {
#include "gen/D_1696310.inc"
};
static const hkCustomAttributes D_1696108[1] = {
#include "gen/D_1696108.inc"
};
static const hkCustomAttributes D_1696118[1] = {
#include "gen/D_1696118.inc"
};
extern const hkClassEnum::Item D_1696130; /* the first of the types' items */
extern const hkClassEnum::Item D_16961e0; /* the first of the keys' items */
static const hkClassEnum D_16962a0[2] = {
#include "gen/D_16962a0.inc"
};
static const hknpFirstPersonGunDefaults D_16960e0[1] = {
#include "gen/D_16960e0.inc"
};

/* The key's enum pointer, a global its record reads (0x16dc610), so the
 * records are built when the file is initialized. derived name. */
extern const hkClassEnum *D_16dc610;

static hkClassMember D_57c0080[5] = {
    {"type",
     0,
     0,
     hkClassMember::TYPE_ENUM,
     hkClassMember::TYPE_UINT8,
     0,
     {hkClassMember::SERIALIZE_IGNORED},
     u16(HK_OFFSET_OF(hknpFirstPersonGun, type)),
     0},
    {"name",
     0,
     0,
     hkClassMember::TYPE_STRINGPTR,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hknpFirstPersonGun, name)),
     D_1696118},
    {"keyboardKey",
     0,
     D_16dc610,
     hkClassMember::TYPE_ENUM,
     hkClassMember::TYPE_UINT8,
     0,
     {0},
     u16(HK_OFFSET_OF(hknpFirstPersonGun, keyboardKey)),
     D_1696108},
    {"listeners",
     0,
     0,
     hkClassMember::TYPE_ARRAY,
     hkClassMember::TYPE_POINTER,
     0,
     {hkClassMember::SERIALIZE_IGNORED},
     u16(HK_OFFSET_OF(hknpFirstPersonGun, listeners)),
     0},
    {"collisionFilterInfo",
     0,
     0,
     hkClassMember::TYPE_UINT32,
     hkClassMember::TYPE_VOID,
     0,
     {hkClassMember::SERIALIZE_IGNORED},
     u16(HK_OFFSET_OF(hknpFirstPersonGun, collisionFilterInfo)),
     0},
};

/* This file's static initializer (0x3cd10): the members' attributes and
 * records, hknpFirstPersonGun's reflection over hkReferencedObject's (two
 * enums, five members, their defaults) and type info. */
const hkClass D_57bffb0("hknpFirstPersonGun", &D_57b8640, sizeof(hknpFirstPersonGun), 0, 0,
                        D_16962a0, 2, D_57c0080, 5, D_16960e0, 0, 0, 0);
extern const hkTypeInfo D_57c0000;
const hkTypeInfo D_57c0000("hknpFirstPersonGun", "!hknpFirstPersonGun",
                           finishLoadedObjecthknpFirstPersonGun,
                           cleanupLoadedObjecthknpFirstPersonGun, vtableOfhknpFirstPersonGun(),
                           sizeof(hknpFirstPersonGun));
