/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the event's kind, whether the body woke or went to sleep,
 * and its id. */
void hknpBodyActivationEvent::FUN_00155430(hknpWorld *world, hkOstream &stream) const
{
    stream.FUN_00008440("BodyActivationEvent ");
    stream.FUN_00008440(activated ? " Activated" : " Deactivated");
    stream.FUN_00008440(" Id=").FUN_00008550(bodyId);
}
