/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hkSkinBinding's type info (0x57bd2d8):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
void FUN_000242e0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkSkinBinding(flag);
}

/* hkSkinBinding's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClassMember D_1691c90[]; /* derived name: hkSkinBinding's records */

/* The address of hkSkinBinding's vtable, read from an object finished in a 16-byte aligned
 * buffer (the finish constructor is out of line, 0xaa4f0, so the object is built on the stack,
 * as hkcdStaticAabbTree's in func_0001ff50.cpp). */
static const void *vtableOfhkSkinBinding() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkSkinBinding)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkSkinBinding(flag);
    return object.vtable;
}

/* This file's static initializer (0x24300): hkSkinBinding's reflection over hkMeshShape's
 * (version 0), its three members, then its type info. */
const hkClass D_57bd288("hkSkinBinding", &D_57bd7d0, sizeof(hkSkinBinding), 0, 0, 0, 0, D_1691c90,
                        3, 0, 0, 0, 0);
extern const hkTypeInfo D_57bd2d8;
const hkTypeInfo D_57bd2d8("hkSkinBinding", "!hkSkinBinding", FUN_000242e0, FUN_000002d0,
                           vtableOfhkSkinBinding(), sizeof(hkSkinBinding));
