/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the object constructed in place from a loaded image through its
 * inline finish constructor, which has nothing to fix up but the vtable
 * (the finish callback kept at 0x7c410), and destroyed through its virtual
 * destructor (the body the linker folded, 0x2d0). */
static void finishLoadedObjecthkpCallbackConstraintMotor(void *object,
                                                         int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkpCallbackConstraintMotor(flag);
}

static void cleanupLoadedObjecthkpCallbackConstraintMotor(void *object) /* derived name */
{
    static_cast<hkpCallbackConstraintMotor *>(object)->~hkpCallbackConstraintMotor();
}

extern const hkClass D_57c59a8; /* hkpLimitedForceConstraintMotor's hkClass */

/* The address of hkpCallbackConstraintMotor's vtable, read from an object
 * finished in a buffer (folded to the address point, 0x7c66d). */
static const void *vtableOfhkpCallbackConstraintMotor() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkpCallbackConstraintMotor)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkpCallbackConstraintMotor(flag);
    return object.vtable;
}

/* The CallbackType enum and its five items, and the members' defaults,
 * file-local; the rows the base's. */
static const hkClassEnum::Item D_169c8c0[5] = {
#include "gen/D_169c8c0.inc"
};

static const hkClassEnum D_169c910[1] = {
#include "gen/D_169c910.inc"
};

static const hkpCallbackConstraintMotorDefaults D_14c02e4[1] = {
#include "gen/D_14c02e4.inc"
};

/* This file's static initializer (0x7c430): hkpCallbackConstraintMotor's
 * five member records (in .bss, stored to directly: the file's own), built
 * at run time from the enum's pointer, then its class over
 * hkpLimitedForceConstraintMotor's and its type info with its vtable. */
static hkClassMember D_57c3d40[] = {
    {"callbackFunc", 0, 0, hkClassMember::TYPE_POINTER, hkClassMember::TYPE_VOID, 0,
     hkClassMember::SERIALIZE_IGNORED, 0x18, 0},
    {"callbackType", 0, D_16dc660, hkClassMember::TYPE_ENUM, hkClassMember::TYPE_UINT32, 0, 0, 0x20,
     0},
    {"userData0", 0, 0, hkClassMember::TYPE_ULONG, hkClassMember::TYPE_VOID, 0, 0, 0x28, 0},
    {"userData1", 0, 0, hkClassMember::TYPE_ULONG, hkClassMember::TYPE_VOID, 0, 0, 0x30, 0},
    {"userData2", 0, 0, hkClassMember::TYPE_ULONG, hkClassMember::TYPE_VOID, 0, 0, 0x38, 0}};
const hkClass D_57c3cc0("hkpCallbackConstraintMotor", &D_57c59a8,
                        sizeof(hkpCallbackConstraintMotor), 0, 0, D_169c910, 1, D_57c3d40, 5,
                        D_14c02e4, 0, 0, 0);
extern const hkTypeInfo D_57c3d10;
const hkTypeInfo D_57c3d10("hkpCallbackConstraintMotor", "!hkpCallbackConstraintMotor",
                           finishLoadedObjecthkpCallbackConstraintMotor,
                           cleanupLoadedObjecthkpCallbackConstraintMotor,
                           vtableOfhkpCallbackConstraintMotor(),
                           sizeof(hkpCallbackConstraintMotor));
