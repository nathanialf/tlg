/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* The class is declared in tlg_hk_reflect.h. */
hkSlot::~hkSlot()
{
    /* A slot is destroyed still bound to the subscriber it was created
     * for. */
    HK_ASSERT(0, object != 0); /* derived assert */
}

hknpWorldMaterialSlot::~hknpWorldMaterialSlot() {}
