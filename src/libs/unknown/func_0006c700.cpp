/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

hknpMaterial::hknpMaterial(const hknpMaterial &other)
{
    FUN_0000e3d0(&name);
    FUN_0000e6c0(&name, &other.name);
    FUN_00017e70(&isExclusive, &other.isExclusive, sizeof(hknpMaterial) - sizeof(hkStringPtr));
}
