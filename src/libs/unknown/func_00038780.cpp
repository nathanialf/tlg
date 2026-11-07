/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's cleanup callback, this file's (static, docs/DECISIONS.md
 * D39): the quality destroyed in place, nothing to do (the body the linker
 * folded, 0x1c1e0); a loaded quality needs no finishing. */
static void cleanupLoadedObjecthknpBodyQuality(void *object) /* derived name */
{
    static_cast<hknpBodyQuality *>(object)->~hknpBodyQuality();
}

/* hknpBodyQuality's one enum, file-local; its eighteen items the base's. */
extern const hkClassEnum::Item D_1694050; /* the first of its items */

static const hkClassEnum D_1694170[1] = {
#include "gen/D_1694170.inc"
};

/* This file's static initializer (0x38780): hknpBodyQuality's four member
 * records, built at run time from the flags' enum pointer, then its
 * reflection (no parent, its one enum, version 1) and its type info. */
static hkClassMember D_57beeb0[] = {
    {"priority", 0, 0, hkClassMember::TYPE_INT32, hkClassMember::TYPE_VOID, 0, 0, 0, 0},
    {"supportedFlags", 0, D_16dc5e8, hkClassMember::TYPE_FLAGS, hkClassMember::TYPE_UINT32, 0, 0, 4,
     0},
    {"requestedFlags", 0, D_16dc5e8, hkClassMember::TYPE_FLAGS, hkClassMember::TYPE_UINT32, 0, 0, 8,
     0},
    {"contactCachingRelativeMovementThreshold", 0, 0, hkClassMember::TYPE_REAL,
     hkClassMember::TYPE_VOID, 0, 0, 0xc, 0}};
const hkClass D_57bee30("hknpBodyQuality", 0, sizeof(hknpBodyQuality), 0, 0, D_1694170, 1,
                        D_57beeb0, 4, 0, 0, 0, 1);
extern const hkTypeInfo D_57bee80;
const hkTypeInfo D_57bee80("hknpBodyQuality", "!hknpBodyQuality", 0,
                           cleanupLoadedObjecthknpBodyQuality, 0, sizeof(hknpBodyQuality));
