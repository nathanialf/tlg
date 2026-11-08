/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' cleanup callbacks, this file's (static, docs/DECISIONS.md
 * D39): nothing to destroy (the empty body the linker folded, 0xe5c0); no
 * finish callback. */
static void cleanupLoadedObjecthkClassEnumItem(void *object) /* derived name */ {}

static void cleanupLoadedObjecthkClassEnum(void *object) /* derived name */ {}

/* hkClassEnum::Item's two member records and hkClassEnum's one enum with
 * its item, file-local; the rows the base's. */
static const hkClassMember D_168e180[2] = {
#include "gen/D_168e180.inc"
};

static const hkClassEnum::Item D_168e1d0[1] = {
#include "gen/D_168e1d0.inc"
};

static const hkClassEnum D_168e1e0[1] = {
#include "gen/D_168e1e0.inc"
};

/* This file's static initializer (0x11e50): hkClassEnum::Item's class and
 * type info, then hkClassEnum's four member records (in .bss, reached
 * through its address, 0x11eed: not the file's own), built at run time
 * from the flags enum's pointer, its class and its type info. */
const hkClass D_57b92c0("hkClassEnumItem", 0, sizeof(hkClassEnum::Item), 0, 0, 0, 0, D_168e180, 2,
                        0, 0, 0, 0);
extern const hkTypeInfo D_57b9310;
const hkTypeInfo D_57b9310("hkClassEnumItem", "!hkClassEnum::Item", 0,
                           cleanupLoadedObjecthkClassEnumItem, 0, sizeof(hkClassEnum::Item));
hkClassMember D_57b9340[] = {
    {"name", 0, 0, hkClassMember::TYPE_CSTRING, hkClassMember::TYPE_VOID, 0, 0, 0, 0},
    {"items", &D_57b92c0, 0, hkClassMember::TYPE_SIMPLEARRAY, hkClassMember::TYPE_STRUCT, 0, 0, 8,
     0},
    {"attributes", &D_57b7ee8, 0, hkClassMember::TYPE_POINTER, hkClassMember::TYPE_STRUCT, 0, 0x400,
     0x18, 0},
    {"flags", 0, D_16dc580, hkClassMember::TYPE_FLAGS, hkClassMember::TYPE_UINT32, 0, 0, 0x20, 0}};
const hkClass D_57b93e0("hkClassEnum", 0, sizeof(hkClassEnum), 0, 0, D_168e1e0, 1, D_57b9340, 4, 0,
                        0, 0, 0);
extern const hkTypeInfo D_57b9430;
const hkTypeInfo D_57b9430("hkClassEnum", "!hkClassEnum", 0, cleanupLoadedObjecthkClassEnum, 0,
                           sizeof(hkClassEnum));
