/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x1c1e0. */
static void finishLoadedObjecthknpSparseCompactMapunsignedshort(void *object,
                                                                int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpSparseCompactMap<u16>(flag);
}

/* The cleanup callback of hknpSparseCompactMap<hkUint16>'s type info
 * (0x57befa0, set at 0x38ab2): the map destroyed in place, its arrays'
 * storage given back. */
static void cleanupLoadedObjecthknpSparseCompactMapunsignedshort(void *object) /* derived name */
{
    static_cast<hknpSparseCompactMap<u16> *>(object)->~hknpSparseCompactMap();
}

/* This file's static initializer (0x38a20): hknpSparseCompactMap<hkUint16>'s
 * reflection (hkClass 0x57bef50: no parent, its four members), then its
 * type info (the cleanup callback 0x389a0, no vtable). */
const hkClass D_57bef50("hknpSparseCompactMapunsignedshort", 0, sizeof(hknpSparseCompactMap<u16>),
                        0, 0, 0, 0, D_16941a0, 4, 0, 0, 0, 0);
extern const hkTypeInfo D_57befa0;
const hkTypeInfo D_57befa0("hknpSparseCompactMapunsignedshort",
                           "!hknpSparseCompactMapunsignedshort_typename",
                           finishLoadedObjecthknpSparseCompactMapunsignedshort,
                           cleanupLoadedObjecthknpSparseCompactMapunsignedshort, 0,
                           sizeof(hknpSparseCompactMap<u16>));
