/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 6 of hkXmlParser: a node put back, for the next read
 * to return first. */
void hkXmlParser::FUN_0019e6b0(void *node)
{
    pendingNodes.pushBack(node);
}
