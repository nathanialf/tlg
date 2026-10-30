/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

hkxTextureFile::hkxTextureFile(hkFinishLoadedObjectFlag flag)
    : hkReferencedObject(flag), filename(flag), name(flag), originalFilename(flag)
{
}

/* The finish callback of hkxTextureFile's type info: construct the object
 * in place from a loaded image (the linker folded it with the constructor
 * above, 0x878f0). */
void FUN_000878f0(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxTextureFile(flag);
}

/* hkxTextureFile's loaded-object cleanup: the virtual destructor (the
 * linker folded it with the other classes' identical body, 0x2d0,
 * FUN_000002d0). */
void FUN_000002d0(void *object)
{
    static_cast<hkxTextureFile *>(object)->~hkxTextureFile();
}

/* The class's vtable, read from an object its finish constructor builds
 * (cookbook 166). derived name. */
static const void *vtableOfhkxTextureFile() /* derived name */
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkxTextureFile)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxTextureFile(flag);
    return object.vtable;
}

/* NONMATCHING (by the layout, not the bytes): quick_diff finds 0x87950 equal; the gate's
 * layout refuses the finish callback's reference (`bytes of _Z12FUN_000878f0Pvi occur 0
 * times`): the address's row is the constructor's, so the callback is placed by a search for
 * its bytes, which still hold the unrelocated GOT load of the vtable (NOTES Round 64B). */
/* This file's static initializer (0x87950): hkxTextureFile's reflection,
 * hkReferencedObject's as the parent, its three members, version 1, then its
 * type info (its finish callback, the destructor, the vtable). */
const hkClass D_57c67d0("hkxTextureFile", &D_57b8640, sizeof(hkxTextureFile), 0, 0, 0, 0, D_16a0f30,
                        3, 0, 0, 0, 1);
extern const hkTypeInfo D_57c6820;
const hkTypeInfo D_57c6820("hkxTextureFile", "!hkxTextureFile", FUN_000878f0, FUN_000002d0,
                           vtableOfhkxTextureFile(), sizeof(hkxTextureFile));
