/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: a quality cleared, then every flag supported and the
 * contact caching threshold set to 0.1. */
void hknpBodyQuality::FUN_0016a380(float unitScale)
{
    FUN_00018160(this, 0, sizeof(hknpBodyQuality));
    supportedFlags = 0xffffffff;
    contactCachingRelativeMovementThreshold = 0.1f;
}
