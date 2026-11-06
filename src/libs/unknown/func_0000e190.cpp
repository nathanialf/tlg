/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the finish callback of hkReferencedObject's type info
 * (0x57b8690, registered at 0xe1b0): construct the object in place from a
 * loaded image through its inline finish constructor, which has nothing to
 * fix up but the vtable. */
static void finishLoadedObjecthkReferencedObject(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkReferencedObject(flag);
}

/* Its cleanup callback: the object destroyed in place through its virtual
 * destructor. The linker folded the identical bodies of every polymorphic
 * class's cleanup into one, 0x2d0 (hkMonitorStreamColorTable's type info at
 * 0x57af3e8, hkUuidObject's at 0x57b7ae8, hkSimpleLocalFrame's, hkGeometry's,
 * hkcdShape's and the hkcd planar classes' among them); an identical body at
 * 0x37d0 has no reference. The row is claimed here. */
static void cleanupLoadedObjecthkReferencedObject(void *object) /* derived name */
{
    static_cast<hkReferencedObject *>(object)->~hkReferencedObject();
}

/* The address of hkReferencedObject's vtable, read from an object finished
 * in a buffer (folded to the address point). */
static const void *vtableOfhkReferencedObject() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkReferencedObject)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkReferencedObject(flag);
    return object.vtable;
}

/* This file's static initializer (0xe1b0): hkReferencedObject's reflection
 * over hkBaseObject's, its one member, then its type info. */
const hkClass D_57b8640("hkReferencedObject", &D_57b86c0, sizeof(hkReferencedObject), 0, 0, 0, 0,
                        D_168d980, 1, 0, 0, 0, 0);
extern const hkTypeInfo D_57b8690;
const hkTypeInfo D_57b8690("hkReferencedObject", "!hkReferencedObject",
                           finishLoadedObjecthkReferencedObject,
                           cleanupLoadedObjecthkReferencedObject, vtableOfhkReferencedObject(),
                           sizeof(hkReferencedObject));
