/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived names: the cleanup callback of the raw-ulong dynamic tree
 * storage's type info (registered by 0x1f750): destroy the storage in
 * place, which frees its nodes. */
template <>
void hkcdDynamicTree::DefaultDynamicStorage<hkcdDynamicTree::CodecRawUlong>::FUN_0001f650(
    void *object)
{
    static_cast<DefaultDynamicStorage *>(object)->nodes.clearAndDeallocate();
}
