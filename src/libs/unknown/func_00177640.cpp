/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* The listener, when there is one, is told after each solve. */
void hknpCharacterProxy::FUN_00177640(hknpWorld *world) /* derived name */
{
    if (listener) {
        listener->unknownVirtual7(this);
    }
}
