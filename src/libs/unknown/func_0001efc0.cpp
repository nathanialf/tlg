/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The type infos' own callbacks, this file's (static, docs/DECISIONS.md
 * D39), each folded by the linker into the shared empty body 0x1c1e0. */
static void finishLoadedObjecthkcdDynamicTreeAnisotropicMetric(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdDynamicTree::AnisotropicMetric(flag);
}

static void cleanupLoadedObjecthkcdDynamicTreeAnisotropicMetric(void *object)
{
    static_cast<hkcdDynamicTree::AnisotropicMetric *>(object)->~AnisotropicMetric();
}

static void finishLoadedObjecthkcdDynamicTreeBalanceMetric(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdDynamicTree::BalanceMetric(flag);
}

static void cleanupLoadedObjecthkcdDynamicTreeBalanceMetric(void *object)
{
    static_cast<hkcdDynamicTree::BalanceMetric *>(object)->~BalanceMetric();
}

static void finishLoadedObjecthkcdDynamicTreeCentroidMetric(void *object, int finishing)
{
    hkFinishLoadedObjectFlag flag;
    flag.finishing = finishing;
    new (object) hkcdDynamicTree::CentroidMetric(flag);
}

static void cleanupLoadedObjecthkcdDynamicTreeCentroidMetric(void *object)
{
    static_cast<hkcdDynamicTree::CentroidMetric *>(object)->~CentroidMetric();
}

/* This file's static initializer (0x1efc0): each metric's reflection (no
 * parent, no members) and type info (no vtable). */
const hkClass D_57bb110("hkcdDynamicTreeAnisotropicMetric", 0,
                        sizeof(hkcdDynamicTree::AnisotropicMetric), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
extern const hkTypeInfo D_57bb160;
const hkTypeInfo D_57bb160("hkcdDynamicTreeAnisotropicMetric",
                           "!hkcdDynamicTree::AnisotropicMetric",
                           finishLoadedObjecthkcdDynamicTreeAnisotropicMetric,
                           cleanupLoadedObjecthkcdDynamicTreeAnisotropicMetric, 0,
                           sizeof(hkcdDynamicTree::AnisotropicMetric));
const hkClass D_57bb190("hkcdDynamicTreeBalanceMetric", 0, sizeof(hkcdDynamicTree::BalanceMetric),
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
extern const hkTypeInfo D_57bb1e0;
const hkTypeInfo D_57bb1e0("hkcdDynamicTreeBalanceMetric", "!hkcdDynamicTree::BalanceMetric",
                           finishLoadedObjecthkcdDynamicTreeBalanceMetric,
                           cleanupLoadedObjecthkcdDynamicTreeBalanceMetric, 0,
                           sizeof(hkcdDynamicTree::BalanceMetric));
const hkClass D_57bb210("hkcdDynamicTreeCentroidMetric", 0, sizeof(hkcdDynamicTree::CentroidMetric),
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
extern const hkTypeInfo D_57bb260;
const hkTypeInfo D_57bb260("hkcdDynamicTreeCentroidMetric", "!hkcdDynamicTree::CentroidMetric",
                           finishLoadedObjecthkcdDynamicTreeCentroidMetric,
                           cleanupLoadedObjecthkcdDynamicTreeCentroidMetric, 0,
                           sizeof(hkcdDynamicTree::CentroidMetric));
