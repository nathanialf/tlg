/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* This file's static initializer (0x403d0): hknpCollisionFilter's one
 * member record, its type (an enum in a byte) at +0xc, built at run time
 * from the enum pointer, then the class over hkReferencedObject's. */
static hkClassMember D_57c0d00[] = {
    {"type", 0, D_16dc620, hkClassMember::TYPE_ENUM, hkClassMember::TYPE_UINT8, 0, 0, 0xc, 0}};
const hkClass D_57c0cb0("hknpCollisionFilter", &D_57b8640, 16, 0, 0, D_1696e60, 1, D_57c0d00, 1, 0,
                        0, 0, 0);
