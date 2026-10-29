/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

void hkMemoryResourceHandle::FUN_0017f330(const char *memberName, const char *externalId)
{
    hkMemoryResourceHandleExternalLink &link = references.expandOne();
    link.memberName = memberName;
    link.externalId = externalId;
}
