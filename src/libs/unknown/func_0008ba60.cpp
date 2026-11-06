/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the object constructed in place from a loaded image through its
 * inline finish constructor, which has nothing to fix up but the vtable
 * (the finish callback kept at 0x8ba40), and destroyed through its virtual
 * destructor (the body the linker folded, 0x2d0). */
static void finishLoadedObjecthkxAnimatedFloat(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxAnimatedFloat(flag);
}

static void cleanupLoadedObjecthkxAnimatedFloat(void *object) /* derived name */
{
    static_cast<hkxAnimatedFloat *>(object)->~hkxAnimatedFloat();
}

/* The address of hkxAnimatedFloat's vtable, read from an object finished
 * in a buffer (folded to the address point). */
static const void *vtableOfhkxAnimatedFloat() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkxAnimatedFloat)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkxAnimatedFloat(flag);
    return object.vtable;
}

/* This file's static initializer (0x8ba60): hkxAnimatedFloat's two member
 * records, built at run time from the hint's enum pointer, then its
 * reflection over hkReferencedObject's (version 1) and its type info with
 * its vtable. */
static hkClassMember D_57c79b0[] = {
    {"floats", 0, 0, hkClassMember::TYPE_ARRAY, hkClassMember::TYPE_REAL, 0, 0, 0x10, 0},
    {"hint", 0, D_16dc6d0, hkClassMember::TYPE_ENUM, hkClassMember::TYPE_UINT8, 0, 0, 0x20, 0}};
const hkClass D_57c7930("hkxAnimatedFloat", &D_57b8640, sizeof(hkxAnimatedFloat), 0, 0, 0, 0,
                        D_57c79b0, 2, 0, 0, 0, 1);
extern const hkTypeInfo D_57c7980;
const hkTypeInfo D_57c7980("hkxAnimatedFloat", "!hkxAnimatedFloat",
                           finishLoadedObjecthkxAnimatedFloat, cleanupLoadedObjecthkxAnimatedFloat,
                           vtableOfhkxAnimatedFloat(), sizeof(hkxAnimatedFloat));
