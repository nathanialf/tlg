/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: slot 19 of the vtable at 0x16be9a8 (its pointer at
 * 0x16bea50): passes one of two settings strings for the effect
 * "AntennaEff" to FUN_00ec0170, as a tail call, the dry one when the int at
 * +0x158 is set. Class and method unknown. */
struct Object00eb6220 { /* derived name */
    u8 unknown0[0x158];
    int unknown158;
};

void FUN_00ec0170(const char *settings); /* derived name */

void FUN_00eb6220(const Object00eb6220 *self) /* derived name */
{
    if (self->unknown158 != 0) {
        FUN_00ec0170("AntennaEff.dry=0;AntennaEff.wet=100;");
    } else {
        FUN_00ec0170("AntennaEff.dry=100;AntennaEff.wet=0;");
    }
}
