/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* hkBaseObject's loaded-object callbacks, this file's (static,
 * docs/DECISIONS.md D39): nothing to finish, nothing to clean up, the
 * destructor not called (the empty body 0x6660, which its vtable's slots 0
 * and 1 cite too). */
static void finishLoadedObjecthkBaseObject(void *object, int finishing) {} /* derived name */

static void cleanupLoadedObjecthkBaseObject(void *object) {} /* derived name */

/* The address of hkBaseObject's vtable, read from an object finished in a
 * buffer (folded to the address point). */
static const void *vtableOfhkBaseObject() /* derived name */
{
    union {
        void *vtable;
        char buffer[sizeof(hkBaseObject)];
    } object;

    hkFinishLoadedObjectFlag flag;
    new (object.buffer) hkBaseObject(flag);
    return object.vtable;
}

/* This file's static initializer (0x6a60): hkBaseObject's type info, then
 * hkReferencedObjectLock's registration (no create function, the instance
 * pointer D_57b7b50). */
extern const hkTypeInfo D_57b7b20;
const hkTypeInfo D_57b7b20("hkBaseObject", "!hkBaseObject", finishLoadedObjecthkBaseObject,
                           cleanupLoadedObjecthkBaseObject, vtableOfhkBaseObject(), 16);

static SingletonRecord D_57b7b58("hkReferencedObjectLock", 0,
                                 reinterpret_cast<void **>(&D_57b7b50));
