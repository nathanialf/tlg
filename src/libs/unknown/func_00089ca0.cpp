/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the object constructed in place from a loaded image through its
 * inline finish constructor, the name finished (the finish callback kept at
 * 0x89c70), and destroyed through its virtual destructor (the body the
 * linker folded, 0x2d0). */
static void finishLoadedObjecthkxMaterialEffect(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxMaterialEffect(flag);
}

static void cleanupLoadedObjecthkxMaterialEffect(void *object) /* derived name */
{
    static_cast<hkxMaterialEffect *>(object)->~hkxMaterialEffect();
}

/* The address of hkxMaterialEffect's vtable, read from an object finished
 * in a buffer (folded to the address point). */
static const void *vtableOfhkxMaterialEffect() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkxMaterialEffect)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxMaterialEffect(flag);
    return object.vtable;
}

/* hkxMaterialEffect's one enum, file-local; its seven items the base's. */
extern const hkClassEnum::Item D_16a1820; /* the first of its items */

static const hkClassEnum D_16a1890[1] = {
#include "gen/D_16a1890.inc"
};

/* This file's static initializer (0x89ca0): hkxMaterialEffect's three
 * member records, built at run time from the type's enum pointer, then its
 * reflection over hkReferencedObject's with its one enum and its type info
 * with its vtable. */
static hkClassMember D_57c71c0[] = {
    {"name", 0, 0, hkClassMember::TYPE_STRINGPTR, hkClassMember::TYPE_VOID, 0, 0, 0x10, 0},
    {"type", 0, D_16dc6c0, hkClassMember::TYPE_ENUM, hkClassMember::TYPE_UINT8, 0, 0, 0x18, 0},
    {"data", 0, 0, hkClassMember::TYPE_ARRAY, hkClassMember::TYPE_UINT8, 0, 0, 0x20, 0}};
const hkClass D_57c7140("hkxMaterialEffect", &D_57b8640, sizeof(hkxMaterialEffect), 0, 0, D_16a1890,
                        1, D_57c71c0, 3, 0, 0, 0, 1);
extern const hkTypeInfo D_57c7190;
const hkTypeInfo D_57c7190("hkxMaterialEffect", "!hkxMaterialEffect",
                           finishLoadedObjecthkxMaterialEffect,
                           cleanupLoadedObjecthkxMaterialEffect, vtableOfhkxMaterialEffect(),
                           sizeof(hkxMaterialEffect));
