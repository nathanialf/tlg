/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39): hkxVertexAnimation constructed in place from a loaded image (the
 * finish callback kept at 0x8cb10) and destroyed through its virtual
 * destructor (the body the linker folded, 0x2d0); the usage map's cleanup
 * has nothing to do (folded into the empty body 0x8c0a0). The vtable and
 * the inline destructor's three variants (0x8c930, 0x8c940, 0x8c990) are
 * emitted here. derived names. */
static void cleanupLoadedObjecthkxVertexAnimationUsageMap(void *object)
{
    static_cast<hkxVertexAnimationUsageMap *>(object)->~hkxVertexAnimationUsageMap();
}

static void finishLoadedObjecthkxVertexAnimation(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkxVertexAnimation(flag);
}

static void cleanupLoadedObjecthkxVertexAnimation(void *object)
{
    static_cast<hkxVertexAnimation *>(object)->~hkxVertexAnimation();
}

/* The address of hkxVertexAnimation's vtable, read from an object finished
 * in a buffer (the vertex buffer's finish constructor is out of line, so the
 * object stays on the stack and the vtable is read back from it). derived
 * name. */
static const void *vtableOfhkxVertexAnimation()
{
    union {
        void *vtable;
        alignas(16) char buffer[sizeof(hkxVertexAnimation)];
    } object;

    hkFinishLoadedObjectFlag flag;
    flag.finishing = 0;
    new (object.buffer) hkxVertexAnimation(flag);
    return object.vtable;
}

extern const hkClass D_57b8640;         /* hkReferencedObject's hkClass */
extern const hkClassMember D_16a2700[]; /* derived name: hkxVertexAnimation's records */

/* This file's static initializer (0x8cb40): the usage map's three member
 * records (in .bss, built at run time from the enum's pointer), its class
 * and type info, then hkxVertexAnimation's class over hkReferencedObject's
 * and its type info with its vtable. */
static hkClassMember D_57c7e40[] = {
    {"use", 0, D_16dc6e8, hkClassMember::TYPE_ENUM, hkClassMember::TYPE_UINT16, 0, 0, 0, 0},
    {"useIndexOrig", 0, 0, hkClassMember::TYPE_UINT8, hkClassMember::TYPE_VOID, 0, 0, 2, 0},
    {"useIndexLocal", 0, 0, hkClassMember::TYPE_UINT8, hkClassMember::TYPE_VOID, 0, 0, 3, 0}};
const hkClass D_57c7d40("hkxVertexAnimationUsageMap", 0, sizeof(hkxVertexAnimationUsageMap), 0, 0,
                        0, 0, D_57c7e40, 3, 0, 0, 0, 0);
extern const hkTypeInfo D_57c7d90;
const hkTypeInfo D_57c7d90("hkxVertexAnimationUsageMap", "!hkxVertexAnimation::UsageMap", 0,
                           cleanupLoadedObjecthkxVertexAnimationUsageMap, 0,
                           sizeof(hkxVertexAnimationUsageMap));
const hkClass D_57c7dc0("hkxVertexAnimation", &D_57b8640, sizeof(hkxVertexAnimation), 0, 0, 0, 0,
                        D_16a2700, 4, 0, 0, 0, 0);
extern const hkTypeInfo D_57c7e10;
const hkTypeInfo D_57c7e10("hkxVertexAnimation", "!hkxVertexAnimation",
                           finishLoadedObjecthkxVertexAnimation,
                           cleanupLoadedObjecthkxVertexAnimation, vtableOfhkxVertexAnimation(),
                           sizeof(hkxVertexAnimation));
