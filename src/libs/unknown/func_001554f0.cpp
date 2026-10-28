/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

void hknpBinaryBodyDebugEvent::FUN_001554f0(hknpWorld *world,
                                            hkOstream &out) const /* derived name */
{
    out.FUN_00008440("BinaryBodyDebugEvent id[0]=")
        .FUN_00008550(bodyIdA)
        .FUN_00008440(", id[1]=")
        .FUN_00008550(bodyIdB)
        .FUN_00008440(": ");
    out.FUN_00008440(text);
}
