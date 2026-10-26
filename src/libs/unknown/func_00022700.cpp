/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* A finished tree is the object's to delete unless the object was loaded in
 * place (no memory size). The tree pointer is left as loaded. */
hkcdStaticAabbTree::hkcdStaticAabbTree(hkFinishLoadedObjectFlag flag) : hkReferencedObject(flag)
{
    if (flag.finishing) {
        shouldDeleteTree = (memSizeAndRefCount >> 16) != 0;
    }
}
