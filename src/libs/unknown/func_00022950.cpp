/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The raw buffer descriptor's loaded-object callbacks: nothing to finish,
 * nothing to clean up (the linker folded both into the empty body
 * 0x1c1e0). */
void FUN_0001c1e0(void *object, int finishing) {}

void FUN_0001c1e0(void *object) {}

extern const hkClassMember D_1690e20[]; /* derived name: the raw buffer descriptor's records */
extern const hkClassEnum D_1691010[];   /* derived name: hkMeshTexture's three enums */

/* This file's static initializer (0x22950): the raw buffer descriptor's
 * reflection (hkClass 0x57bc910: no parent, three members) and type info
 * (no vtable; the name its hkClass spells, the scoped name the base's
 * string), then hkMeshTexture's reflection over hkReferencedObject's
 * (hkClass 0x57bc990: its three enums, no members). */
const hkClass D_57bc910("hkMeshTextureRawBufferDescriptor", 0,
                        sizeof(hkMeshTexture::RawBufferDescriptor), 0, 0, 0, 0, D_1690e20, 3, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57bc960;
const hkTypeInfo D_57bc960("hkMeshTextureRawBufferDescriptor",
                           "!hkMeshTexture::RawBufferDescriptor", FUN_0001c1e0, FUN_0001c1e0, 0,
                           sizeof(hkMeshTexture::RawBufferDescriptor));
const hkClass D_57bc990("hkMeshTexture", &D_57b8640, sizeof(hkMeshTexture), 0, 0, D_1691010, 3, 0,
                        0, 0, 0, 0, 0);
