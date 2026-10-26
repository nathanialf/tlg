/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: prints the event's name, "Reserved". */
void hknpReservedEvent::FUN_00040be0(hknpWorld *world, hkOstream &out) const /* derived name */
{
    out.FUN_00008440("Reserved");
}
