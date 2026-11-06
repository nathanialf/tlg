/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived names: the finish callback of hknpMotionProperties's type info (0x57bf510):
 * construct the object in place from a loaded image through its out-of-line
 * finish constructor. */
static void finishLoadedObjecthknpMotionProperties(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    FUN_000396a0(static_cast<hknpMotionProperties *>(object), flag);
}

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x1c1e0. */
static void cleanupLoadedObjecthknpMotionProperties(void *object) /* derived name */
{
    static_cast<hknpMotionProperties *>(object)->~hknpMotionProperties();
}

/* hknpMotionProperties's members' defaults, file-local (D17); the rows are
 * written at build time from the user's executable (D18,
 * config/data_schema.base.txt). */
static const hknpMotionPropertiesDefaults D_14ba280[1] = {
#include "gen/D_14ba280.inc"
};

/* This file's static initializer (0x395e0): hknpMotionProperties's
 * reflection, no parent, its two enums, its twenty members and their
 * defaults, version 3, then its type info (the finish callback
 * FUN_000395c0, no vtable). */
const hkClass D_57bf4c0("hknpMotionProperties", 0, sizeof(hknpMotionProperties), 0, 0, D_1694c40, 2,
                        D_16948a0, 20, D_14ba280, 0, 0, 3);
extern const hkTypeInfo D_57bf510;
const hkTypeInfo D_57bf510("hknpMotionProperties", "!hknpMotionProperties",
                           finishLoadedObjecthknpMotionProperties,
                           cleanupLoadedObjecthknpMotionProperties, 0,
                           sizeof(hknpMotionProperties));
