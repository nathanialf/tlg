/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type info's own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared body 0x1c1e0. */
static void cleanupLoadedObjecthkcdStaticPvsBlockHeader(void *object) /* derived name */
{
    static_cast<hkcdStaticPvsBlockHeader *>(object)->~hkcdStaticPvsBlockHeader();
}

static void finishLoadedObjecthkcdStaticPvs(void *object, int finishing) /* derived name */
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdStaticPvs(flag);
}

/* derived names: the cleanup callback of hkcdStaticPvs's type info (0x57ba5e0):
 * destroy the object in place through its out-of-line destructor. */
static void cleanupLoadedObjecthkcdStaticPvs(void *object) /* derived name */
{
    static_cast<hkcdStaticPvs *>(object)->~hkcdStaticPvs();
}

/* This file's static initializer (0x1db10): hkcdStaticPvs::BlockHeader's
 * reflection (no parent, its two members) and type info, then
 * hkcdStaticPvs's (its six members), neither with a vtable. The type
 * infos' names are the base's strings. */
const hkClass D_57ba510("hkcdStaticPvsBlockHeader", 0, sizeof(hkcdStaticPvsBlockHeader), 0, 0, 0, 0,
                        D_168f9f0, 2, 0, 0, 0, 0);
extern const hkTypeInfo D_57ba560;
const hkTypeInfo D_57ba560("hkcdStaticPvsBlockHeader", "!hkcdStaticPvs::BlockHeader", 0,
                           cleanupLoadedObjecthkcdStaticPvsBlockHeader, 0,
                           sizeof(hkcdStaticPvsBlockHeader));
const hkClass D_57ba590("hkcdStaticPvs", 0, sizeof(hkcdStaticPvs), 0, 0, 0, 0, D_168fa40, 6, 0, 0,
                        0, 0);
extern const hkTypeInfo D_57ba5e0;
const hkTypeInfo D_57ba5e0("hkcdStaticPvs", "!hkcdStaticPvs", finishLoadedObjecthkcdStaticPvs,
                           cleanupLoadedObjecthkcdStaticPvs, 0, sizeof(hkcdStaticPvs));
