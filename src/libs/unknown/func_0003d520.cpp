/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the object constructed in place from a loaded image through its
 * inline finish constructor, which has nothing to fix up but the vtable
 * (the finish callback kept at 0x3d520), and destroyed through its virtual
 * destructor (the body the linker folded, 0x2d0). */
static void finishLoadedObjecthknpLinearSurfaceVelocity(void *object,
                                                        int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpLinearSurfaceVelocity(flag);
}

static void cleanupLoadedObjecthknpLinearSurfaceVelocity(void *object) /* derived name */
{
    static_cast<hknpLinearSurfaceVelocity *>(object)->~hknpLinearSurfaceVelocity();
}

extern const hkClass D_57c19d8; /* hknpSurfaceVelocity's hkClass */

/* The address of hknpLinearSurfaceVelocity's vtable, read from an object
 * finished in a buffer (folded to the address point, 0x3d780). */
static const void *vtableOfhknpLinearSurfaceVelocity() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hknpLinearSurfaceVelocity)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hknpLinearSurfaceVelocity(flag);
    return object.vtable;
}

/* The ProjectMethod enum and its two items, file-local; the rows the
 * base's. */
static const hkClassEnum::Item D_1696500[2] = {
#include "gen/D_1696500.inc"
};

static const hkClassEnum D_1696520[1] = {
#include "gen/D_1696520.inc"
};

/* This file's static initializer (0x3d540): hknpLinearSurfaceVelocity's
 * five member records (in .bss, stored to directly: the file's own), built
 * at run time from the two enums' pointers, then its class over
 * hknpSurfaceVelocity's and its type info with its vtable. */
static hkClassMember D_57c0420[] = {
    {"space", 0, D_16dc628, hkClassMember::TYPE_ENUM, hkClassMember::TYPE_UINT8, 0, 0, 0xc, 0},
    {"projectMethod", 0, D_16dc618, hkClassMember::TYPE_ENUM, hkClassMember::TYPE_UINT8, 0, 0, 0xd,
     0},
    {"maxVelocityScale", 0, 0, hkClassMember::TYPE_REAL, hkClassMember::TYPE_VOID, 0, 0, 0x10, 0},
    {"velocityMeasurePlane", 0, 0, hkClassMember::TYPE_VECTOR4, hkClassMember::TYPE_VOID, 0, 0,
     0x20, 0},
    {"velocity", 0, 0, hkClassMember::TYPE_VECTOR4, hkClassMember::TYPE_VOID, 0, 0, 0x30, 0}};
const hkClass D_57c03a0("hknpLinearSurfaceVelocity", &D_57c19d8, sizeof(hknpLinearSurfaceVelocity),
                        0, 0, D_1696520, 1, D_57c0420, 5, 0, 0, 0, 0);
extern const hkTypeInfo D_57c03f0;
const hkTypeInfo D_57c03f0("hknpLinearSurfaceVelocity", "!hknpLinearSurfaceVelocity",
                           finishLoadedObjecthknpLinearSurfaceVelocity,
                           cleanupLoadedObjecthknpLinearSurfaceVelocity,
                           vtableOfhknpLinearSurfaceVelocity(), sizeof(hknpLinearSurfaceVelocity));
