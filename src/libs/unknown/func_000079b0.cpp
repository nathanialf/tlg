/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's cleanup callback, this file's (static, docs/DECISIONS.md
 * D39): nothing to destroy (the empty body the linker folded, 0x6c80); no
 * finish callback. */
static void cleanupLoadedObjecthkClassMember(void *object) /* derived name */ {}

/* hkClassMember's three enums (Type, FlagValues, DeprecatedFlagValues) with
 * their items, file-local; the rows the base's. */
static const hkClassEnum::Item D_168cc30[36] = {
#include "gen/D_168cc30.inc"
};

static const hkClassEnum::Item D_168ce70[7] = {
#include "gen/D_168ce70.inc"
};

static const hkClassEnum::Item D_168cee0[6] = {
#include "gen/D_168cee0.inc"
};

static const hkClassEnum D_168cf40[3] = {
#include "gen/D_168cf40.inc"
};

/* This file's static initializer (0x79b0): hkClassMember's nine member
 * records (in .bss), built at run time from the enums' pointers, then its
 * class and type info. */
hkClassMember D_57b7bb0[] = {
    {"name", 0, 0, hkClassMember::TYPE_CSTRING, hkClassMember::TYPE_VOID, 0, 0, 0, 0},
    {"class", &D_57b77f0, 0, hkClassMember::TYPE_POINTER, hkClassMember::TYPE_STRUCT, 0, 0, 8, 0},
    {"enum", &D_57b93e0, 0, hkClassMember::TYPE_POINTER, hkClassMember::TYPE_STRUCT, 0, 0, 0x10, 0},
    {"type", 0, D_16dc140, hkClassMember::TYPE_ENUM, hkClassMember::TYPE_UINT8, 0, 0, 0x18, 0},
    {"subtype", 0, D_16dc140, hkClassMember::TYPE_ENUM, hkClassMember::TYPE_UINT8, 0, 0, 0x19, 0},
    {"cArraySize", 0, 0, hkClassMember::TYPE_INT16, hkClassMember::TYPE_VOID, 0, 0, 0x1a, 0},
    {"flags", 0, D_16dc148, hkClassMember::TYPE_FLAGS, hkClassMember::TYPE_UINT16, 0, 0, 0x1c, 0},
    {"offset", 0, 0, hkClassMember::TYPE_UINT16, hkClassMember::TYPE_VOID, 0, 0, 0x1e, 0},
    {"attributes", &D_57b7ee8, 0, hkClassMember::TYPE_POINTER, hkClassMember::TYPE_STRUCT, 0, 0x400,
     0x20, 0}};
const hkClass D_57b7d18("hkClassMember", 0, sizeof(hkClassMember), 0, 0, D_168cf40, 3, D_57b7bb0, 9,
                        0, 0, 0, 0);
extern const hkTypeInfo D_57b7d68;
const hkTypeInfo D_57b7d68("hkClassMember", "!hkClassMember", 0, cleanupLoadedObjecthkClassMember,
                           0, sizeof(hkClassMember));
