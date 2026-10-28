/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the event's kind and its two bodies' ids, then whether the
 * body entered or left the trigger. */
void hknpTriggerEvent::FUN_00040b70(hknpWorld *world, hkOstream &out) const
{
    out.FUN_00008440("TriggerEvent bodyIds=")
        .FUN_00008550(bodyIdA)
        .FUN_00008440(",")
        .FUN_00008550(bodyIdB);
    out.FUN_00008440(exited ? " Status=Exited" : " Status=Entered");
}
