/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: the function of the entry "jt_Hip_Rt" of the name and
 * function table at 0x57adc68 (its pointer at 0x57adf60): returns what
 * FUN_008f0180 gives for its first argument and the floats at +0x0 and +0x8 of
 * its second, a record returned through memory. The types are not traced. */
struct Result0136afd0 { /* derived name */
    u8 unknown0[0x20];
};

Result0136afd0 FUN_008f0180(void *object, float x, float z); /* derived name */

Result0136afd0 FUN_0136afd0(void *object, const float *vector) /* derived name */
{
    return FUN_008f0180(object, vector[0], vector[2]);
}
