/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* hknpSparseCompactMap<hkUint16>'s finish callback: nothing to finish (the
 * linker folded it into the shared empty body 0x1c1e0, FUN_0001c1e0). */
void FUN_0001c1e0(void *object, int finishing) {}

/* This file's static initializer (0x38a20): hknpSparseCompactMap<hkUint16>'s
 * reflection (hkClass 0x57bef50: no parent, its four members), then its
 * type info (the cleanup callback 0x389a0, no vtable). */
const hkClass D_57bef50("hknpSparseCompactMapunsignedshort", 0, sizeof(hknpSparseCompactMap<u16>),
                        0, 0, 0, 0, D_16941a0, 4, 0, 0, 0, 0);
extern const hkTypeInfo D_57befa0;
const hkTypeInfo D_57befa0("hknpSparseCompactMapunsignedshort",
                           "!hknpSparseCompactMapunsignedshort_typename", FUN_0001c1e0,
                           FUN_000389a0, 0, sizeof(hknpSparseCompactMap<u16>));
