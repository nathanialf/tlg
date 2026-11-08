/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39): the cinfo constructed in place from a loaded image through its inline
 * finish constructor, which finishes the name (0x36990), and destroyed in
 * place, the name and then the data's reference (0x369a0). */
static void finishLoadedObjecthknpConstraintCinfo(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hknpConstraintCinfo(flag);
}

static void cleanupLoadedObjecthknpConstraintCinfo(void *object) /* derived name */
{
    static_cast<hknpConstraintCinfo *>(object)->~hknpConstraintCinfo();
}

/* This file's static initializer (0x36a10): hknpConstraintCinfo's five
 * member records, file-local, built at run time from the flags enum's
 * pointer, then its class and its type info. */
static hkClassMember D_57beae0[] = {
    {"constraintData", &D_57c45a8, 0, hkClassMember::TYPE_POINTER, hkClassMember::TYPE_STRUCT, 0, 0,
     0, 0},
    {"bodyA", 0, 0, hkClassMember::TYPE_UINT32, hkClassMember::TYPE_VOID, 0, 0, 8, 0},
    {"bodyB", 0, 0, hkClassMember::TYPE_UINT32, hkClassMember::TYPE_VOID, 0, 0, 0xc, 0},
    {"flags", 0, D_16dc650, hkClassMember::TYPE_FLAGS, hkClassMember::TYPE_UINT8, 0, 0, 0x10, 0},
    {"name", 0, 0, hkClassMember::TYPE_STRINGPTR, hkClassMember::TYPE_VOID, 0, 0, 0x18, 0}};
const hkClass D_57bea60("hknpConstraintCinfo", 0, sizeof(hknpConstraintCinfo), 0, 0, 0, 0,
                        D_57beae0, 5, 0, 0, 0, 3);
extern const hkTypeInfo D_57beab0;
const hkTypeInfo D_57beab0("hknpConstraintCinfo", "!hknpConstraintCinfo",
                           finishLoadedObjecthknpConstraintCinfo,
                           cleanupLoadedObjecthknpConstraintCinfo, 0, sizeof(hknpConstraintCinfo));
