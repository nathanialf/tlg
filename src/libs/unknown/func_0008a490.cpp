/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The finish callback of hkxMaterialShader's type info (0x8a490):
 * construct the object in place from a loaded image (the finish
 * constructor is inline: its four strings finished in order). */
static void finishLoadedObjecthkxMaterialShader(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxMaterialShader(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes', 0x2d0). */
static void cleanupLoadedObjecthkxMaterialShader(void *object) /* derived name */
{
    static_cast<hkxMaterialShader *>(object)->~hkxMaterialShader();
}

/* The address of hkxMaterialShader's vtable, read from an object finished
 * in a buffer on a 16-byte boundary (rbp-0x70; the four strings' finish
 * constructors called, 0x8a7aa). */
static const void *vtableOfhkxMaterialShader() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkxMaterialShader)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxMaterialShader(flag);
    return object.vtable;
}

/* hkxMaterialShader's one enum, file-local; its seven items the base's. */
extern const hkClassEnum::Item D_16a1c10; /* the first of its items */

static const hkClassEnum D_16a1c80[1] = {
#include "gen/D_16a1c80.inc"
};

/* The enum's pointer, a global the type's record reads (0x16dc6c8), so the
 * records are built when the file is initialized. derived name. */
extern const hkClassEnum *D_16dc6c8;

static hkClassMember D_57c73c0[6] = {
    {"name",
     0,
     0,
     hkClassMember::TYPE_STRINGPTR,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hkxMaterialShader, name)),
     0},
    {"type",
     0,
     D_16dc6c8,
     hkClassMember::TYPE_ENUM,
     hkClassMember::TYPE_UINT8,
     0,
     {0},
     u16(HK_OFFSET_OF(hkxMaterialShader, type)),
     0},
    {"vertexEntryName",
     0,
     0,
     hkClassMember::TYPE_STRINGPTR,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hkxMaterialShader, vertexEntryName)),
     0},
    {"geomEntryName",
     0,
     0,
     hkClassMember::TYPE_STRINGPTR,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hkxMaterialShader, geomEntryName)),
     0},
    {"pixelEntryName",
     0,
     0,
     hkClassMember::TYPE_STRINGPTR,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hkxMaterialShader, pixelEntryName)),
     0},
    {"data",
     0,
     0,
     hkClassMember::TYPE_ARRAY,
     hkClassMember::TYPE_UINT8,
     0,
     {0},
     u16(HK_OFFSET_OF(hkxMaterialShader, data)),
     0},
};

/* This file's static initializer (0x8a4f0): the records, hkxMaterialShader's
 * reflection over hkReferencedObject's (its enum and six members, version
 * 1), then its type info. */
const hkClass D_57c7340("hkxMaterialShader", &D_57b8640, sizeof(hkxMaterialShader), 0, 0, D_16a1c80,
                        1, D_57c73c0, 6, 0, 0, 0, 1);
extern const hkTypeInfo D_57c7390;
const hkTypeInfo D_57c7390("hkxMaterialShader", "!hkxMaterialShader",
                           finishLoadedObjecthkxMaterialShader,
                           cleanupLoadedObjecthkxMaterialShader, vtableOfhkxMaterialShader(),
                           sizeof(hkxMaterialShader));
