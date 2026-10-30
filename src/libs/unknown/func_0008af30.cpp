/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the finish callback of hkxNodeSelectionSet's type info
 * (registered at 0x8b00e): construct the object in place from a loaded image. */
void FUN_0008af30(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxNodeSelectionSet(flag);
}

/* hkxNodeSelectionSet's cleanup callback: the virtual destructor (the shared body 0x2d0). */
void FUN_000002d0(void *object);
extern const hkClass D_57c76b0;         /* hkxAttributeHolder's hkClass */
extern const hkClassMember D_16a1eb0[]; /* derived name: hkxNodeSelectionSet's records */

/* The address of hkxNodeSelectionSet's vtable, read from an object finished in a 16-byte
 * aligned buffer: the name's finish constructor is out of line (0xe5c0), so the object is
 * built on the stack and its vtable read back after the call. */
static const void *vtableOfhkxNodeSelectionSet() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkxNodeSelectionSet)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxNodeSelectionSet(flag);
    return object.vtable;
}

/* This file's static initializer (0x8af60): hkxNodeSelectionSet's reflection over
 * hkxAttributeHolder's (version 0), its two members, then its type info. */
const hkClass D_57c75b0("hkxNodeSelectionSet", &D_57c76b0, sizeof(hkxNodeSelectionSet), 0, 0, 0, 0,
                        D_16a1eb0, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57c7600;
const hkTypeInfo D_57c7600("hkxNodeSelectionSet", "!hkxNodeSelectionSet", FUN_0008af30,
                           FUN_000002d0, vtableOfhkxNodeSelectionSet(),
                           sizeof(hkxNodeSelectionSet));
