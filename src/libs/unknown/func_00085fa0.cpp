/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The finish callback of hkxSpline's type info (0x85fa0): construct the
 * object in place from a loaded image through its inline finish
 * constructor, which has nothing to fix up but the vtable. */
static void finishLoadedObjecthkxSpline(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxSpline(flag);
}

/* Its cleanup callback: the object destroyed through its virtual
 * destructor (the linker folded the body with the other classes', 0x2d0). */
static void cleanupLoadedObjecthkxSpline(void *object) /* derived name */
{
    static_cast<hkxSpline *>(object)->~hkxSpline();
}

/* The control point has nothing to destroy (the shared empty body the
 * linker folded, 0x83250) and no finish callback. */
static void cleanupLoadedObjecthkxSplineControlPoint(void *object) /* derived name */ {}

/* The address of hkxSpline's vtable, read from an object finished in a
 * buffer (folded to the address point). */
static const void *vtableOfhkxSpline() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxSpline)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkxSpline(flag);
    return object.vtable;
}

extern const hkClassEnum D_16a0950[]; /* derived name: hkxSpline's one enum, the control types */
/* The enum's pointer, a global the control point's records read (0x16dc690),
 * so the records are built when the file is initialized. derived name. */
extern const hkClassEnum *D_16dc690;
extern const hkClassMember D_16a08c0[]; /* derived name: hkxSpline's records */

static hkClassMember D_57c6000[5] = {
    {"position",
     0,
     0,
     hkClassMember::TYPE_VECTOR4,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hkxSplineControlPoint, position)),
     0},
    {"tangentIn",
     0,
     0,
     hkClassMember::TYPE_VECTOR4,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hkxSplineControlPoint, tangentIn)),
     0},
    {"tangentOut",
     0,
     0,
     hkClassMember::TYPE_VECTOR4,
     hkClassMember::TYPE_VOID,
     0,
     {0},
     u16(HK_OFFSET_OF(hkxSplineControlPoint, tangentOut)),
     0},
    {"inType",
     0,
     D_16dc690,
     hkClassMember::TYPE_ENUM,
     hkClassMember::TYPE_UINT8,
     0,
     {0},
     u16(HK_OFFSET_OF(hkxSplineControlPoint, inType)),
     0},
    {"outType",
     0,
     D_16dc690,
     hkClassMember::TYPE_ENUM,
     hkClassMember::TYPE_UINT8,
     0,
     {0},
     u16(HK_OFFSET_OF(hkxSplineControlPoint, outType)),
     0},
};

/* This file's static initializer (0x85fc0): the control point's records,
 * its reflection (no parent) and type info, then hkxSpline's reflection
 * over hkReferencedObject's (its enum and its two members) and type
 * info. */
const hkClass D_57c5f00("hkxSplineControlPoint", 0, sizeof(hkxSplineControlPoint), 0, 0, 0, 0,
                        D_57c6000, 5, 0, 0, 0, 0);
extern const hkTypeInfo D_57c5f50;
const hkTypeInfo D_57c5f50("hkxSplineControlPoint", "!hkxSpline::ControlPoint", 0,
                           cleanupLoadedObjecthkxSplineControlPoint, 0,
                           sizeof(hkxSplineControlPoint));
const hkClass D_57c5f80("hkxSpline", &D_57b8640, sizeof(hkxSpline), 0, 0, D_16a0950, 1, D_16a08c0,
                        2, 0, 0, 0, 0);
extern const hkTypeInfo D_57c5fd0;
const hkTypeInfo D_57c5fd0("hkxSpline", "!hkxSpline", finishLoadedObjecthkxSpline,
                           cleanupLoadedObjecthkxSpline, vtableOfhkxSpline(), sizeof(hkxSpline));
