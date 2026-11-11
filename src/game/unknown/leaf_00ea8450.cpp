/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 5 of the vtable at 0x16be610 (its pointer at
 * 0x16be648): 0 when its argument has no record at +0x18, else passes both to
 * FUN_00eb2500 and returns 1. The object (this) is not read. Class and method
 * unknown. */
struct Argument00ea8450 { /* derived name */
    u8 unknown0[0x18];
    void *unknown18;
};

void FUN_00eb2500(Argument00ea8450 *argument, void *record); /* derived name */

int FUN_00ea8450(void *, Argument00ea8450 *argument) /* derived name */
{
    if (!argument->unknown18) {
        return 0;
    }
    FUN_00eb2500(argument, argument->unknown18);
    return 1;
}
