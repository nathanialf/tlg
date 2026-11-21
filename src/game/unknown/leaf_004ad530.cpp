/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_libc.h"
#include "tlg_game_target004ad600.h"

/* derived names: the handler FUN_004acae0 stores at 0x57d7518, beside the
 * hash of "Marker.firerange.enter" at 0x57d7510: sets the target's bool at
 * +0x1a8, then reads self's name as two numbers "a,b": the first, where one
 * is read, into +0x1ac, and after a comma the second into +0x1b0. Class and
 * method unknown. */
void FUN_004ad530(Object004ad600 *self, Target004ad600 *target) /* derived name */
{
    target->unknown1a8 = true;
    if (self->unknown14.index != 0) {
        const char *string = D_17ac870[self->unknown14.index].string0;
        if (string && *string) {
            char *end = 0;
            float value = strtof(string, &end);
            if (end != string)
                target->unknown1ac = value;
            if (*end == ',') {
                char *secondEnd = 0;
                value = strtof(end + 1, &secondEnd);
                if (end + 1 != secondEnd)
                    target->unknown1b0 = value;
            }
        }
    }
}
