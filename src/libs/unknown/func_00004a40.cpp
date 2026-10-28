/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

const hkVariant *hkClass::FUN_00004a40(const char *attributeName) const /* derived name */
{
    return attributes ? attributes->getAttribute(attributeName) : 0;
}
