/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The finish callback of hkMemoryMeshTexture's type info (0x24800):
 * construct the object in place from a loaded image. */
static void finishLoadedObjecthkMemoryMeshTexture(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkMemoryMeshTexture(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes', 0x2d0). */
static void cleanupLoadedObjecthkMemoryMeshTexture(void *object) /* derived name */
{
    static_cast<hkMemoryMeshTexture *>(object)->~hkMemoryMeshTexture();
}

/* The address of the class's vtable, read from an object finished in a
 * buffer on a 16-byte boundary (rbp-0x60; the file name's finish
 * constructor out of line, 0x24af8). */
static const void *vtableOfhkMemoryMeshTexture() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkMemoryMeshTexture)] __attribute__((aligned(16)));
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkMemoryMeshTexture(flag);
    return object.vtable;
}

/* The texture interface's enums' pointers, globals the records read
 * (0x16dc5a0, 0x16dc5a8 and 0x16dc5b0 hold its three item tables), so the
 * records are built when the file is initialized. derived names. */
extern const hkClassEnum *D_16dc5a0; /* Format */
extern const hkClassEnum *D_16dc5a8; /* FilterMode */
extern const hkClassEnum *D_16dc5b0; /* TextureUsageType */
extern const hkClass D_57bc990;      /* hkMeshTexture's hkClass */

/* The records, a global of the file's own (the base reaches them through
 * the GOT, the stores relative to one register, 0x24857). */
extern hkClassMember D_57bd4e0[7];
hkClassMember D_57bd4e0[7] = {
    {"filename",
     0,
     0,
     hkClassMember::TYPE_STRINGPTR,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hkMemoryMeshTexture, filename)),
     0},
    {"data",
     0,
     0,
     hkClassMember::TYPE_ARRAY,
     hkClassMember::TYPE_UINT8,
     0,
     {0},
     u16(HK_OFFSET_OF(hkMemoryMeshTexture, data)),
     0},
    {"format",
     0,
     D_16dc5a0,
     hkClassMember::TYPE_ENUM,
     hkClassMember::TYPE_INT8,
     0,
     {0},
     u16(HK_OFFSET_OF(hkMemoryMeshTexture, format)),
     0},
    {"hasMipMaps",
     0,
     0,
     hkClassMember::TYPE_BOOL,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hkMemoryMeshTexture, hasMipMaps)),
     0},
    {"filterMode",
     0,
     D_16dc5a8,
     hkClassMember::TYPE_ENUM,
     hkClassMember::TYPE_INT8,
     0,
     {0},
     u16(HK_OFFSET_OF(hkMemoryMeshTexture, filterMode)),
     0},
    {"usageHint",
     0,
     D_16dc5b0,
     hkClassMember::TYPE_ENUM,
     hkClassMember::TYPE_INT8,
     0,
     {0},
     u16(HK_OFFSET_OF(hkMemoryMeshTexture, usageHint)),
     0},
    {"textureCoordChannel",
     0,
     0,
     hkClassMember::TYPE_INT32,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hkMemoryMeshTexture, textureCoordChannel)),
     0},
};

/* This file's static initializer (0x24830): the records, hkMemoryMeshTexture's
 * reflection over hkMeshTexture's (version 2), then its type info. */
const hkClass D_57bd5f8("hkMemoryMeshTexture", &D_57bc990, sizeof(hkMemoryMeshTexture), 0, 0, 0, 0,
                        D_57bd4e0, 7, 0, 0, 0, 2);
extern const hkTypeInfo D_57bd648;
const hkTypeInfo D_57bd648("hkMemoryMeshTexture", "!hkMemoryMeshTexture",
                           finishLoadedObjecthkMemoryMeshTexture,
                           cleanupLoadedObjecthkMemoryMeshTexture, vtableOfhkMemoryMeshTexture(),
                           sizeof(hkMemoryMeshTexture));
